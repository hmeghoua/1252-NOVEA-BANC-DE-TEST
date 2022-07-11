/**
 * @file          EvtTransitionSAlimSecoursVersLastState.cpp
 * @version       1.0
 * @date          Created on: 30 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright Emkaelectronique
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
 *        (#) IDE          : Eclipse Papyrus - Decembre 2022 - Plugin CDT 
 *
 * ===================================================================
 *                 ##### Historique des modifications #####
 * ===================================================================
 * 
 *        (#) Version   | Date           | Auteur              | Nature de la modification
 *            1.00        30 juin 2022         H. MEGHOUACHE         Creation
 *
 * @endverbatim
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2022 EmkaELECTRONIQUE </center></h2>
 *******************************************************************************
 *
 */
#include "../../Headers/Transitions/EvtTransitionSAlimSecoursVersLastState.h"


#include "../../Headers/Actions/CActionConsommation.h"
#include "../../Headers/Actions/CActionAlimSecours.h"

EvtTransitionSAlimSecoursVersLastState::EvtTransitionSAlimSecoursVersLastState() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSAlimSecoursVersLastState::~EvtTransitionSAlimSecoursVersLastState() {
	// TODO Auto-generated destructor stub
}
/**
  * @brief  Condition de garde entre les �tats SConsommation vers SAlimSecours
  * @brief  Pr�conditions :
  *          				CONSOMMATION_MESURE_SOUS_5V_NOK    			:  Succ�s de la mesure de la consommation
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
  * @retval     			1                                       : La condition de garde s'est bien pass�e
  *          				100			                            : La pr�condition a �chou� (l'�tat pr�c�dent a �chou�)
  *          				ALIM_SECOURS_30V_NOK			    	: Echec de l'alimentation de la carte sous 30V
  *          				ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK     : Echec de la mesure de la hausse de consommation de la carte
  */
const /*string*/ uint EvtTransitionSAlimSecoursVersLastState::onTransitionEvent(CAction*argAction,CAction*argActionBefore)
{

	uint retour=100;    	     //Contient le retour des appels la m�thode : �chec par d�faut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'�tat de l'action pr�c�dente associ�e � l'�tat "SConsommation"
	CActionConsommation* oActionLuxmetre=(CActionConsommation*)argActionBefore;
	uint *tabResEtatPrecedent=  oActionLuxmetre->getm_STATE();


	//L'objet "oActionLedRGB pour r�aliser les actions pr�vues dans l'�tat SAlimSecours
	CActionAlimSecours* oActionAlimSecours=(CActionAlimSecours*)argAction;


	//On teste alors la pr�condition : la condition de garde est-elle �tablie ?
	 if((*(tabResEtatPrecedent)==CONSOMMATION_MESURE_SOUS_5V_OK)){

#ifdef DEBUG_PC
			cout<<"Je suis dans la transition de SAlimSecours Vers SLastState"<<endl;
#endif

	 precondition=true; //Precondition �tablie

	 //On r�alise les actions associ�es � l'�tat "SAlimSecours"
	 //Alimentation de la carte en 30v
	 if(oActionAlimSecours->alimenterCarteEn30V()==0){//1
		 //Succes de l'alimentation de la carte en 30V
		 oActionAlimSecours->setm_STATE(0, ALIM_SECOURS_30V_OK);
		 //Mesure de la hausse d'alimentation
		 if(oActionAlimSecours->mesurerHausseAlimentation()==0){//2

			 //Succes de la mesure de la hausse d'alimentation
			 oActionAlimSecours->setm_STATE(1, ALIM_SECOURS_MESURE_HAUSSE_ALIM_OK);

		 }else{//2

			 //Echec de la mesure de la hausse d'alimentation
			  oActionAlimSecours->setm_STATE(1, ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK);
			  retour=ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK;
		 }

	 }else{//1

		 //Echec de l'alimentation de la carte en 30V
		 oActionAlimSecours->setm_STATE(0, ALIM_SECOURS_30V_NOK);
		 retour=ALIM_SECOURS_30V_NOK;
	 	 }
	 }


	 //On construit le retour de la m�thode : La pr�condition est OK et la derni�re action a r�ussi ?
	if((precondition)&&((*(oActionAlimSecours->getm_STATE()+1))==ALIM_SECOURS_MESURE_HAUSSE_ALIM_OK)){

	#ifdef DEBUG_PC
		cout<<"Transition de SAlimSecours Vers SLastState r�ussie"<<endl;
		cout<<"****************************************************************"<<endl;
		cout<<endl;
	#endif
			 retour=1;

		 }/*else{

			 //La derni�re action a �chou�
			 if(precondition==true)
			 {
				 retour=ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK;
			 }
		 }*/

	 return retour;

}

