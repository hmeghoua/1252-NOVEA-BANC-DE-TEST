/**
 * @file          Graph.h
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
 *            1.00        20/06/2022     H. MEGHOUACHE         Creation
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
#ifndef GRAPH_H_
#define GRAPH_H_

#include "CStateBanc.h"
#include <iostream>
#include <map>
#include <string>


class Transition;
class CAction;


class Graph {

public:

	Graph(map<string, CStateBanc*> argListeEtat, map<string,CAction*> argListeActions) {

			states_=argListeEtat;
			listeDesActions_=argListeActions;
			//Premier état du graphe à exécuter
			nextState_="StateAMiseEnPlaceCarte";
			currentActionBefore_=NULL;
	}

		void setListeTransitions( map<string,Transition*> argNewValue){

				transitions_=argNewValue;

		}

	    void StartGraph(){


	    	//Exécution de chaque état

	    //while(nextState_!=/*"StateExit"*/"StateLastState")
	      do {
#ifdef DEBUG_PC
					cout<<"Etat suivant  : "<<nextState_<<endl;
#endif

					/*CStateBanc* etatCourant=states_[nextState_];
					currentTransition_=transitions_[nextState_];
					etatCourant->SetTransition(currentTransition_);
					currentAction_=listeDesActions_[nextState_];
					string entry=etatCourant->Entry(currentAction_);
					nextState_ = etatCourant->Action(currentAction_);
					string exit = etatCourant->Exit(currentAction_);*/

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


	       }while(nextState_!=/*"StateExit"*/"StateLastState");





}


	virtual ~Graph();

private:


    map<string, CStateBanc*> states_;
    map<string,Transition*>  transitions_;
    map<string,CAction*> listeDesActions_;
    Transition* currentTransition_;
    CStateBanc * currentState_;
    CAction * currentAction_,*currentActionBefore_;
    string nextState_;

};

#endif /* GRAPH_H_ */
