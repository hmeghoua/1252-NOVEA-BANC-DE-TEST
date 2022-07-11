/**
 * @file          EvtTransitionSConsommationVersSAlimSecours.cpp
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
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
  * @brief  Condition de garde entre les états SConsommation vers SAlimSecours
  * @brief  Préconditions :
  *          				LUXMETRE_PING_I2C_OK		    			:  Succès du ping I2C du Luxmetre
  *          				LUXMETRE_CALIBRATION_OK						:  Succès de la calibration du luxmetre
  *          				LUXMETRE_LECTURE_VALEUR_SOURCE_OK 			:  Succès de la lecture de valeur de la source lumineuse
  * @brief  Postconditions:
  *
  *
  *
  *
  * @brief  Invariants    : Présence de la carte
  * @param  entrée        : aucun
  * @param  sortie        : aucun
  * @param  entrée/sortie : argAction                               : contient les méthodes métiers qui gèrent les actions liées à la transition
  *  	  	  	  	  	  	argActionBefore                         : permet de savoir si l'action précédente s'est bien passée
  *
  * @retval     			1                                           :  La condition de garde s'est bien passée
  *          				100			                                :  La précondition a échoué (l'état précédent a échoué)
  *          				CONSOMMATION_MESURE_SOUS_5V_NOK		    	:  Echec de la lecture de la conso de la carte sous 5V
  */
const /*string*/uint  EvtTransitionSConsommationVersSAlimSecours::onTransitionEvent(CAction*argAction,CAction*argActionBefore){

	uint retour=100;    	     //Contient le retour des appels la méthode : échec par défaut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'état de l'action précédente associée à l'état "SLuxmetre"
	CActionLuxmetre* oActionLuxmetre=(CActionLuxmetre*)argActionBefore;
	uint *tabResEtatPrecedent=  oActionLuxmetre->getm_STATE();


	//L'objet "oActionLedRGB pour réaliser les actions prévues dans l'état SConsommation
	CActionConsommation* oActionConsommation=(CActionConsommation*)argAction;


	//On teste alors la précondition : la condition de garde est-elle établie ?
	 if((*(tabResEtatPrecedent)==LUXMETRE_PING_I2C_OK )
	 &&(*(tabResEtatPrecedent+1)==LUXMETRE_CALIBRATION_OK)
	 &&(*(tabResEtatPrecedent+2)==LUXMETRE_LECTURE_VALEUR_SOURCE_OK ))
	 {

#ifdef DEBUG_PC
			cout<<"Je suis dans la transition de SConsommation Vers SAlimSecours"<<endl;
#endif

	 precondition=true; //Precondition établie

	 //On réalise les actions associées à l'état "SConsommation"
	 //Mesure de la consommation
	 if(oActionConsommation->messureConsommation5V()==0){//1
		 //Succès de la Mesure de la consommation - on le retient
		 oActionConsommation->setm_STATE(0, CONSOMMATION_MESURE_SOUS_5V_OK);

		 }
	 }else{

		 oActionConsommation->setm_STATE(0, CONSOMMATION_MESURE_SOUS_5V_NOK);
		 retour=CONSOMMATION_MESURE_SOUS_5V_NOK;
	 }

	 //On construit le retour de la méthode : La précondition est OK et la dernière action a réussi ?
	if((precondition)&&((*(oActionConsommation->getm_STATE()))==CONSOMMATION_MESURE_SOUS_5V_OK)){

#ifdef DEBUG_PC
	cout<<"Transition de SConsommation Vers SAlimSecours réussie"<<endl;
	cout<<"****************************************************************"<<endl;
	cout<<endl;
#endif
		 retour=1;

	 }/*else{

		 //La dernière action a échoué
		 if(precondition==true)
		 {
			 retour=CONSOMMATION_MESURE_SOUS_5V_NOK;
		 }
	 }*/

 return retour;

}

