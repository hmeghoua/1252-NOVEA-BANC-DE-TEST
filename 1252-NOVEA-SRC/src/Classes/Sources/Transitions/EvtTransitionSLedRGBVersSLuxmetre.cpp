/**
 * @file          EvtTransitionSLedRGBVersSLuxmetre.cpp
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
#include "../../Headers/Transitions/EvtTransitionSLedRGBVersSLuxmetre.h"
#include "../../Headers/Actions/CActionAccelerometre.h"
#include "../../Headers/Actions/CActionLedRGB.h"

EvtTransitionSLedRGBVersSLuxmetre::EvtTransitionSLedRGBVersSLuxmetre() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSLedRGBVersSLuxmetre::~EvtTransitionSLedRGBVersSLuxmetre() {
	// TODO Auto-generated destructor stub
}

/**
  * @brief  Condition de garde entre les états SLedRGB vers SLuxmetre
  * @brief  Préconditions :
  *          				ACCELEROMETRE_PING_I2C_OK 				    :  Succès du ping sur l'accéléromètre
  *          				ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK 	:  Succès Echec de la lecture de la valeur du fabricant
  *          				ACCELEROMETRE_CALIBRATION_OK    			:  Succès de la calibration de l'accéléromètre
  *          				ACCELEROMETRE_TEST_INTERRUPTION_OK			: Succès du test d'interruption
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
  *          				LED_RGB_R_NOK 				    			:  Echec de la lecture de la longueur d'onde LED R
  *          				LED_RGB_G_NOK								:  Echec de la lecture de la longueur d'onde LED G
  *          				LED_RGB_B_NOK				    			:  Echec de la lecture de la longueur d'onde LED B
  */

const /*string*/uint EvtTransitionSLedRGBVersSLuxmetre::onTransitionEvent(CAction*argAction,CAction*argActionBefore){


	uint retour=100;    	     //Contient le retour des appels la méthode : échec par défaut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'état de l'action précédente associée à l'état "SAccelerometre"
	CActionAccelerometre* oActionAccelerometre=(CActionAccelerometre*)argActionBefore;
	uint *tabResEtatPrecedent= oActionAccelerometre->getm_STATE();


	//L'objet "oActionLedRGB pour réaliser les actions prévues dans l'état SLedRGB
	CActionLedRGB* oActionLedRGB=(CActionLedRGB*)argAction;


		//On teste alors la précondition : la condition de garde est-elle établie ?
	 if((*(tabResEtatPrecedent)==ACCELEROMETRE_PING_I2C_OK)
	 &&(*(tabResEtatPrecedent+1)==ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK)
	 &&(*(tabResEtatPrecedent+2)=ACCELEROMETRE_CALIBRATION_OK )
	 &&(*(tabResEtatPrecedent+3)==ACCELEROMETRE_TEST_INTERRUPTION_OK))
	 {//0
		#ifdef DEBUG_PC
		 	 cout<<"Je suis dans la transition de SLedRGB Vers SLuxmetre"<<endl;
		#endif


		 	 precondition=true; //Precondition établie

			 //On réalise les actions associées à l'état "SLedRGB"
			 //Test de la longueur d'onde de la LED rouge
			 if(oActionLedRGB->testLedR()==0){//1
				 	 //Le test s'est bien passé et on le retient
					 oActionLedRGB->setm_STATE(0, LED_RGB_R_OK);
					 //Test de la longueur d'onde de la LED verte
					 if(oActionLedRGB->testLedG()==0){//2
						 //Le test s'est bien passé et on le retient
						 oActionLedRGB->setm_STATE(1, LED_RGB_G_OK);
						 //Test de la longueur d'onde de la LED bleue
							 if(oActionLedRGB->testLedB()==0){//3
								 //Le test s'est bien passé et on le retient
								 oActionLedRGB->setm_STATE(2, LED_RGB_B_OK);
							 }else{//3

								 oActionLedRGB->setm_STATE(2, LED_RGB_B_NOK);
								 retour= LED_RGB_B_NOK;
							 }
					 }else{//2

						 oActionLedRGB->setm_STATE(1, LED_RGB_G_NOK);
						 retour=LED_RGB_G_NOK;
			 	 	 }

			 }else{//1

				 oActionLedRGB->setm_STATE(0, LED_RGB_R_NOK);
				 retour=LED_RGB_R_NOK;
			 }
	 }//0

	 //On construit le retour de la méthode
	 //La précondition est OK et la dernière action
	 //réussi
	 if((precondition)&&((*(oActionLedRGB->getm_STATE()+2))==LED_RGB_B_OK)){

#ifdef DEBUG_PC
		 cout<<"Transition de transition de SLedRGB Vers SLuxmetre réussie"<<endl;
		 cout<<"****************************************************************"<<endl;
		 cout<<endl;
#endif
				 retour=1;

			/* }else{

				 //La dernière action a échoué
				 if(precondition==true)
				 {
					 retour=LED_RGB_B_NOK;
				 }*/
		 }

	 return retour;

}

