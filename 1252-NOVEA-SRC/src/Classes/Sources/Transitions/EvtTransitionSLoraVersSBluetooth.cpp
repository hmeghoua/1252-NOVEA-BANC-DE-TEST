/**
 * @file          EvtTransitionSLoraVersSBluetooth.cpp
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright emkaelectronique
 * @details       � compl�ter
 *
 *
 * @verbatim
 * ===================================================================
 *                 ##### Client et projet #####
 * ===================================.================================
 * 
 *        (#) Client    : NOVEA
 *        (#) Projet    : BANC DE TEST NOVCOM Z
 *        (#) R�f�rence : BC 1252 002 000 800
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
 *            1.00        20 juin 2022         H. MEGHOUACHE         Creation
 *
 * @endverbatim
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2020 emkaELECTRONIQUE </center></h2>
 *
 ******************************************************************************
 *
 */
#include "../../Headers/Transitions/EvtTransitionSLoraVersSBluetooth.h"
#include "../../Headers/Actions/CActionCan.h"
#include "../../Headers/Actions/CActionLora.h"


EvtTransitionSLoraVersSBluetooth::EvtTransitionSLoraVersSBluetooth() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSLoraVersSBluetooth::~EvtTransitionSLoraVersSBluetooth() {
	// TODO Auto-generated destructor stub
}

/**
  * @brief  Condition de garde entre les �tats SLora et SBluetooth
  * @brief  Pr�conditions : PING_CAN_OK                      :
  *                         ECRITURE_NUM_SERIE_OK            :
  *                         RELECTURE_NUM_SERIE_OK;          :
  *                         LECTURE_UUI_OK
  * @brief  Postconditions:
  *
  *
  *
  *
  * @brief  Invariants    : Pr�sence de la carte
  * @param  entr�e        : aucun
  * @param  sortie        : aucun
  * @param  entr�e/sortie : argAction                               : contient les m�thodes m�tiers qui g�rent les actions li�es � la transition
  *  	  	  	  	  	  	argActionBefore                         : permet de savoir si l'action pr�c�dente s'est bien pass�e
  *
  * @retval     			1                                       :  La condition de garde s'est bien pass�e
  *          				100			                            :  La pr�condition a �chou� (l'�tat pr�c�dent a �chou�)
  *          				LORA_ACTIVATION_EMETTEUR_NOK            :  Echec de l'activation de l'emetteur
  *          				LORA_MESURE_PUISSANCE_NOK               :  Echec de la mesure de puissance
  *          				LORA_COMPARAISON_FORME_ONDE_NOK         :  Echec de la comparaison de forme d'onde
  */

const /*string*/ uint EvtTransitionSLoraVersSBluetooth::onTransitionEvent(CAction*argAction,CAction*argActionBefore)
{


	uint retour=100;    	     //Contient le retour des appels la m�thode : �chec par d�faut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'�tat de l'action pr�c�dente associ�e � l'�tat "Scan"
	CActionCan* oScan=(CActionCan*)argActionBefore;
	uint *tabResEtatPrecedent=oScan->getm_STATE();


	//L'objet "oActionLora pour r�aliser les actions pr�vues dans l'�tat SLora
	CActionLora* oActionLora=(CActionLora*)argAction;

	//On teste alors la pr�condition : la condition de garde est-elle �tablie ?
	 if((*(tabResEtatPrecedent)==PING_CAN_OK)
	 &&(*(tabResEtatPrecedent+1)==ECRITURE_NUM_SERIE_OK)
	 &&(*(tabResEtatPrecedent+2)==RELECTURE_NUM_SERIE_OK)
	 &&(*(tabResEtatPrecedent+3)==LECTURE_UUI_OK))

	 {
#ifdef DEBUG_PC
				cout<<"Je suis dans la transition de SLora vers SBluetooth"<<endl;
#endif

        	 precondition=true; //Precondition �tablie

        	 //On r�alise les actions associ�es � l'�tat "SLora"
        	 //Ping de la carte
        	 if((oActionLora->activation_Emetteur())==0){//1
        		 //L'activation de l'emetteur s'est bien pass� et on le retient
        		 oActionLora->setm_STATE(0, LORA_ACTIVATION_EMETTEUR_OK);
        		 	 if(oActionLora->Mesurer_puissance_lora()==0){//2
        		 		 oActionLora->setm_STATE(1, LORA_MESURE_PUISSANCE_OK);
        		 		 if(oActionLora->comparaison_forme_onde()==0){//3
        		 			oActionLora->setm_STATE(2, LORA_COMPARAISON_FORME_ONDE_OK);

        		 		 }else{	 //3
        		 			     oActionLora->setm_STATE(2, LORA_COMPARAISON_FORME_ONDE_NOK);
        		 			     retour=LORA_COMPARAISON_FORME_ONDE_NOK;
        		 		 }
        		 	 }else{	//2
        		 		     oActionLora->setm_STATE(1, LORA_MESURE_PUISSANCE_NOK);
        		 		     retour=LORA_ACTIVATION_EMETTEUR_NOK;
        		 	 }
        	 }else{//1
        		     oActionLora->setm_STATE(0, LORA_ACTIVATION_EMETTEUR_NOK);
        		 	 retour=LORA_ACTIVATION_EMETTEUR_NOK;
        	 }
	 }

	 //On construit le retour de la m�thode
	 //La pr�condition est OK et la derni�re action
	 // a r�ussi
	 if((precondition)&&((*(oActionLora->getm_STATE()+2))==LORA_COMPARAISON_FORME_ONDE_OK)){

	#ifdef DEBUG_PC
				cout<<"Transition de transition de SLora vers SBluetooth r�ussie"<<endl;
				cout<<"****************************************************************"<<endl;
				cout<<endl;
	#endif
			 retour=1;

		 }/*else{//Erreur suite au test V14 du 05/07/14

			 //La derni�re action a �chou�
			 if(precondition==true)
			 {
				 retour=LORA_COMPARAISON_FORME_ONDE_NOK;
			 }
	 }*/

	 return retour;

}

