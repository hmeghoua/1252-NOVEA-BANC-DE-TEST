/**
 * @file          EvtTransitionSLedRGBVersSLuxmetre.cpp
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
  * @brief  Condition de garde entre les �tats SLedRGB vers SLuxmetre
  * @brief  Pr�conditions :
  *          				ACCELEROMETRE_PING_I2C_OK 				    :  Succ�s du ping sur l'acc�l�rom�tre
  *          				ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK 	:  Succ�s Echec de la lecture de la valeur du fabricant
  *          				ACCELEROMETRE_CALIBRATION_OK    			:  Succ�s de la calibration de l'acc�l�rom�tre
  *          				ACCELEROMETRE_TEST_INTERRUPTION_OK			: Succ�s du test d'interruption
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
  *          				LED_RGB_R_NOK 				    			:  Echec de la lecture de la longueur d'onde LED R
  *          				LED_RGB_G_NOK								:  Echec de la lecture de la longueur d'onde LED G
  *          				LED_RGB_B_NOK				    			:  Echec de la lecture de la longueur d'onde LED B
  */

const /*string*/uint EvtTransitionSLedRGBVersSLuxmetre::onTransitionEvent(CAction*argAction,CAction*argActionBefore){


	uint retour=100;    	     //Contient le retour des appels la m�thode : �chec par d�faut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'�tat de l'action pr�c�dente associ�e � l'�tat "SAccelerometre"
	CActionAccelerometre* oActionAccelerometre=(CActionAccelerometre*)argActionBefore;
	uint *tabResEtatPrecedent= oActionAccelerometre->getm_STATE();


	//L'objet "oActionLedRGB pour r�aliser les actions pr�vues dans l'�tat SLedRGB
	CActionLedRGB* oActionLedRGB=(CActionLedRGB*)argAction;


		//On teste alors la pr�condition : la condition de garde est-elle �tablie ?
	 if((*(tabResEtatPrecedent)==ACCELEROMETRE_PING_I2C_OK)
	 &&(*(tabResEtatPrecedent+1)==ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK)
	 &&(*(tabResEtatPrecedent+2)=ACCELEROMETRE_CALIBRATION_OK )
	 &&(*(tabResEtatPrecedent+3)==ACCELEROMETRE_TEST_INTERRUPTION_OK))
	 {//0
		#ifdef DEBUG_PC
		 	 cout<<"Je suis dans la transition de SLedRGB Vers SLuxmetre"<<endl;
		#endif


		 	 precondition=true; //Precondition �tablie

			 //On r�alise les actions associ�es � l'�tat "SLedRGB"
			 //Test de la longueur d'onde de la LED rouge
			 if(oActionLedRGB->testLedR()==0){//1
				 	 //Le test s'est bien pass� et on le retient
					 oActionLedRGB->setm_STATE(0, LED_RGB_R_OK);
					 //Test de la longueur d'onde de la LED verte
					 if(oActionLedRGB->testLedG()==0){//2
						 //Le test s'est bien pass� et on le retient
						 oActionLedRGB->setm_STATE(1, LED_RGB_G_OK);
						 //Test de la longueur d'onde de la LED bleue
							 if(oActionLedRGB->testLedB()==0){//3
								 //Le test s'est bien pass� et on le retient
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

	 //On construit le retour de la m�thode
	 //La pr�condition est OK et la derni�re action
	 //r�ussi
	 if((precondition)&&((*(oActionLedRGB->getm_STATE()+2))==LED_RGB_B_OK)){

#ifdef DEBUG_PC
		 cout<<"Transition de transition de SLedRGB Vers SLuxmetre r�ussie"<<endl;
		 cout<<"****************************************************************"<<endl;
		 cout<<endl;
#endif
				 retour=1;

			/* }else{

				 //La derni�re action a �chou�
				 if(precondition==true)
				 {
					 retour=LED_RGB_B_NOK;
				 }*/
		 }

	 return retour;

}

