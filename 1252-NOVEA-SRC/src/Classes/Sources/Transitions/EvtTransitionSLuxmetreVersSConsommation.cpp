/**
 * @file          EvtTransitionSLuxmetreVersSConsommation.cpp
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
#include "../../Headers/Transitions/EvtTransitionSLuxmetreVersSConsommation.h"
#include "../../Headers/Actions/CActionLuxmetre.h"
#include "../../Headers/Actions/CActionLedRGB.h"

EvtTransitionSLuxmetreVersSConsommation::EvtTransitionSLuxmetreVersSConsommation() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSLuxmetreVersSConsommation::~EvtTransitionSLuxmetreVersSConsommation() {
	// TODO Auto-generated destructor stub
}

/**
  * @brief  Condition de garde entre les états SLuxmetre vers SConsommation
  * @brief  Préconditions :
  *          				LED_RGB_R_OK 				    			:  Succès de la lecture de la longueur d'onde LED R
  *          				LED_RGB_G_OK								:  Succès de la lecture de la longueur d'onde LED G
  *          				LED_RGB_B_OK				    			:  Succès de la lecture de la longueur d'onde LED B
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
  *          				LUXMETRE_PING_I2C_NOK 				    	:  Echec de la lecture de la longueur d'onde LED R
  *          				LUXMETRE_CALIBRATION_NOK					:  Echec de la lecture de la longueur d'onde LED G
  *          				LUXMETRE_LECTURE_VALEUR_SOURCE_NOK			:  Echec de la lecture de la longueur d'onde LED B
  */

const /*string*/uint EvtTransitionSLuxmetreVersSConsommation::onTransitionEvent(CAction*argAction,CAction*argActionBefore){

	uint retour=100;    	     //Contient le retour des appels la méthode : échec par défaut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'état de l'action précédente associée à l'état "SLedRGB"
	CActionLedRGB* oActionLedRGB=(CActionLedRGB*)argActionBefore;
	uint *tabResEtatPrecedent=  oActionLedRGB->getm_STATE();


	//L'objet "oActionLedRGB pour réaliser les actions prévues dans l'état SLuxmetre
	CActionLuxmetre* oActionLuxmetre=(CActionLuxmetre*)argAction;


	//On teste alors la précondition : la condition de garde est-elle établie ?
	 if((*(tabResEtatPrecedent)==LED_RGB_R_OK )
	 &&(*(tabResEtatPrecedent+1)==LED_RGB_G_OK)
	 &&(*(tabResEtatPrecedent+2)==LED_RGB_B_OK ))
	 {

#ifdef DEBUG_PC
			cout<<"Je suis dans la transition de SLuxmetre Vers SConsommation"<<endl;
#endif



		 	 precondition=true; //Precondition établie

			 //On réalise les actions associées à l'état "SLedRGB"
			 //Test de la longueur d'onde de la LED rouge
			 if(oActionLuxmetre->pingI2CLuxmetre()==0){//1
				 	 //Le test s'est bien passé et on le retient
				 oActionLuxmetre->setm_STATE(0, LUXMETRE_PING_I2C_OK);
					 //Test de la longueur d'onde de la LED verte
					 if(oActionLuxmetre->calibrationLuxmetre()==0){//2
						 //Le test s'est bien passé et on le retient
						 oActionLuxmetre->setm_STATE(1, LUXMETRE_CALIBRATION_OK);
						 //Test de la longueur d'onde de la LED bleue
							 if(oActionLuxmetre->lectureValeurSourceLumiere()==0){//3
								 //Le test s'est bien passé et on le retient
								 oActionLuxmetre->setm_STATE(2,LUXMETRE_LECTURE_VALEUR_SOURCE_OK);
							 }else{//3

								 oActionLuxmetre->setm_STATE(2,LUXMETRE_LECTURE_VALEUR_SOURCE_NOK);
								 retour=LUXMETRE_LECTURE_VALEUR_SOURCE_NOK;
							 }
					 }else{//2

						 oActionLuxmetre->setm_STATE(1, LUXMETRE_CALIBRATION_NOK);
						 retour=LUXMETRE_CALIBRATION_NOK;
			 	 	 }

			 }else{//1

				 oActionLuxmetre->setm_STATE(0, LUXMETRE_PING_I2C_NOK);
				 retour=LUXMETRE_PING_I2C_NOK;
			 }
	 }

	 //On construit le retour de la méthode
	 //La précondition est OK et la dernière action
	//réussie
	 	 if((precondition)&&((*(oActionLuxmetre->getm_STATE()+2))==LUXMETRE_LECTURE_VALEUR_SOURCE_OK)){

#ifdef DEBUG_PC
			cout<<"Transition de transition de SLuxmetre Vers SConsommation réussie"<<endl;
			cout<<"****************************************************************"<<endl;
			cout<<endl;
#endif
	 				 retour=1;

	 			/* }else{

	 				 //La dernière action a échoué
	 				 if(precondition==true)
	 				 {
	 					 retour=LUXMETRE_LECTURE_VALEUR_SOURCE_NOK;
	 				 }*/
	 		 }

	 	 return retour;

}






