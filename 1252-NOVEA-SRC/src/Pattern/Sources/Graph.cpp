/**
 * @file          Graph.cpp
 * @version       1.0
 * @date          Created on: 16 juin 2022
 * @author        hme
 * @brief         Copyright emkaelectronique
 * @details       à compléter
 *
 *
 * @verbatim
 * ===================================================================
 *                 ##### Client et projet #####
 * ===================================.================================
 * 
 *        (#) Client    : NOVEA
 *        (#) Projet    : BANC DE TEST NOVCOM Z
 *        (#) Référence : BC 1252 002 000 800
 * ===================================================================
 *                 ##### Cible, compilateur et IDE #####
 * ===================================================================
 * 
 *        (#) Cible        : Raspberry V4
 *        (#) Compilateur  : g++
 *        (#) IDE          : Eclipse Papyrus - Decembre 2012 - Plugin CDT 
 *
 * ===================================================================
 *                 ##### Historique des modifications #####
 * ===================================================================
 * 
 *        (#) Version   | Date           | Auteur              | Nature de la modification
 *            1.00        29/03/2022     H. MEGHOUACHE         Creation
 *
 * @endverbatim
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2022 emkaELECTRONIQUE </center></h2>
 *
 ******************************************************************************
 *
 */
#include "../Headers/Graph.h"

Graph::Graph(map<string, CStateBanc*> argListeEtat, map<string,CAction*> argListeActions) {
	// TODO Auto-generated constructor stub

	states_=argListeEtat;
	listeDesActions_=argListeActions;
	//Premier état du graphe à exécuter
	nextState_="StateAMiseEnPlaceCarte";
	//Pas d'action avant
	currentActionBefore_=NULL;
	//Pour l'affichage sur l'écran LCD
	lcd_=new CScreen();

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub

	delete lcd_;
}

void Graph::StartGraph(){


	      do {
#ifdef DEBUG_PC
					cout<<"Etat suivant  : "<<nextState_<<endl;
#endif

					currentActionBefore_=currentAction_;

					/*On traite l'état courant*/
					currentState_ = states_[nextState_];
					/*On lui affecte sa transition*/
					currentTransition_=transitions_[nextState_];
					currentState_->SetTransition(currentTransition_);
					/*On lui dit quelle action est associée*/
					currentAction_=listeDesActions_[nextState_];
					/*On exécute l'état courant*/
					string entry=currentState_->Entry(currentAction_);
					/*nextState contient l'état qui sera exécuté*/
					nextState_ = currentState_->Action(currentAction_,currentActionBefore_);
					string exit = currentState_->Exit(currentAction_);

					//Si le test a échoué on affiche l'erreur sur l'écran LCD
					if(nextState_.compare("testError")==0){

						unsigned short int indice=currentAction_->getm_resultatActionCourante();
						lcd_->print(LcdToPrint[indice].c_str(),LcdToPrint[indice].size(), 0, 0);
					}else{

						string test="Test en cours";
						lcd_->print(test.c_str(),test.size(), 0, 0);

					}


	       }while(nextState_!="StateLastState");





}

