/**
 * @file          EvtTransitionSConsommationVersSAlimSecours.cpp
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
#include "../../Headers/Transitions/EvtTransitionSConsommationVersSAlimSecours.h"
#include "../../Headers/Actions/CActionLuxmetre.h"
#include "../../Headers/Actions/CActionConsommation.h"

EvtTransitionSConsommationVersSAlimSecours::EvtTransitionSConsommationVersSAlimSecours() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSConsommationVersSAlimSecours::~EvtTransitionSConsommationVersSAlimSecours() {
	// TODO Auto-generated destructor stub
}
/**
  * @brief  Condition de garde entre les �tats SConsommation vers SAlimSecours
  * @brief  Pr�conditions :
  *          				LUXMETRE_PING_I2C_OK		    			:  Succ�s du ping I2C du Luxmetre
  *          				LUXMETRE_CALIBRATION_OK						:  Succ�s de la calibration du luxmetre
  *          				LUXMETRE_LECTURE_VALEUR_SOURCE_OK 			:  Succ�s de la lecture de valeur de la source lumineuse
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
  * @retval     			1                                           :  La condition de garde s'est bien pass�e
  *          				100			                                :  La pr�condition a �chou� (l'�tat pr�c�dent a �chou�)
  *          				CONSOMMATION_MESURE_SOUS_5V_NOK		    	:  Echec de la lecture de la conso de la carte sous 5V
  */
const /*string*/uint  EvtTransitionSConsommationVersSAlimSecours::onTransitionEvent(CAction*argAction,CAction*argActionBefore){

	uint retour=100;    	     //Contient le retour des appels la m�thode : �chec par d�faut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'�tat de l'action pr�c�dente associ�e � l'�tat "SLuxmetre"
	CActionLuxmetre* oActionLuxmetre=(CActionLuxmetre*)argActionBefore;
	uint *tabResEtatPrecedent=  oActionLuxmetre->getm_STATE();


	//L'objet "oActionLedRGB pour r�aliser les actions pr�vues dans l'�tat SConsommation
	CActionConsommation* oActionConsommation=(CActionConsommation*)argAction;


	//On teste alors la pr�condition : la condition de garde est-elle �tablie ?
	 if((*(tabResEtatPrecedent)==LUXMETRE_PING_I2C_OK )
	 &&(*(tabResEtatPrecedent+1)==LUXMETRE_CALIBRATION_OK)
	 &&(*(tabResEtatPrecedent+2)==LUXMETRE_LECTURE_VALEUR_SOURCE_OK ))
	 {

#ifdef DEBUG_PC
			cout<<"Je suis dans la transition de SConsommation Vers SAlimSecours"<<endl;
#endif

	 precondition=true; //Precondition �tablie

	 //On r�alise les actions associ�es � l'�tat "SConsommation"
	 //Mesure de la consommation
	 if(oActionConsommation->messureConsommation5V()==0){//1
		 //Succ�s de la Mesure de la consommation - on le retient
		 oActionConsommation->setm_STATE(0, CONSOMMATION_MESURE_SOUS_5V_OK);

		 }
	 }else{

		 oActionConsommation->setm_STATE(0, CONSOMMATION_MESURE_SOUS_5V_NOK);
		 retour=CONSOMMATION_MESURE_SOUS_5V_NOK;
	 }

	 //On construit le retour de la m�thode : La pr�condition est OK et la derni�re action a r�ussi ?
	if((precondition)&&((*(oActionConsommation->getm_STATE()))==CONSOMMATION_MESURE_SOUS_5V_OK)){

#ifdef DEBUG_PC
	cout<<"Transition de SConsommation Vers SAlimSecours r�ussie"<<endl;
	cout<<"****************************************************************"<<endl;
	cout<<endl;
#endif
		 retour=1;

	 }/*else{

		 //La derni�re action a �chou�
		 if(precondition==true)
		 {
			 retour=CONSOMMATION_MESURE_SOUS_5V_NOK;
		 }
	 }*/

 return retour;

}

