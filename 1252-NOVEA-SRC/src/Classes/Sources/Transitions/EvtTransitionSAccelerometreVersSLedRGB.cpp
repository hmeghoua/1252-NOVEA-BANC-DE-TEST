/**
 * @file          EvtTransitionSAccelerometreVersSLedRGB.cpp
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
#include "../../Headers/Transitions/EvtTransitionSAccelerometreVersSLedRGB.h"
#include "../../Headers/Actions/CActionAccelerometre.h"
#include "../../Headers/Actions/CActionBluetooth.h"

EvtTransitionSAccelerometreVersSLedRGB::EvtTransitionSAccelerometreVersSLedRGB() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSAccelerometreVersSLedRGB::~EvtTransitionSAccelerometreVersSLedRGB() {
	// TODO Auto-generated destructor stub
}

/**
  * @brief  Condition de garde entre les états SAccelerometre vers SLedRGB
  * @brief  Préconditions : BLUETOOTH_ACTIVATION_EMISSION_ESP32_OK      :   l'Activation de l'emetteur bluetooth s'est bien passé
  *          				BLUETOOTH_MESURE_PUISSANCE_OK               :   La mesure de puissance a pu se faire
  *          				BLUETOOTH_COMPARAISON_FORME_ONDE_OK         :   La forme de l'onde est conforme
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
  *          				ACCELEROMETRE_PING_I2C_NOK 				    :  Echec du ping sur l'accéléromètre
  *          				ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_NOK  :  Echec de la lecture de la valeur du fabricant
  *          				ACCELEROMETRE_CALIBRATION_NOK    			:  Echec de la calibration de l'accéléromètre
  *          				ACCELEROMETRE_TEST_INTERRUPTION_NOK			 : Echec du test d'interruption
  */

const /*string*/uint EvtTransitionSAccelerometreVersSLedRGB::onTransitionEvent(CAction*argAction,CAction*argActionBefore){



		uint retour=100;    	     //Contient le retour des appels la méthode : échec par défaut
		bool precondition=false;     //Echec de la precondition par defaut

		//Condition de garde : on lit l'état de l'action précédente associée à l'état "Scan"
		CActionBluetooth* oActionBluetooth=(CActionBluetooth*)argActionBefore;
		uint *tabResEtatPrecedent=oActionBluetooth->getm_STATE();


		//L'objet "oActionLora pour réaliser les actions prévues dans l'état SLora
		CActionAccelerometre* oActionAccelerometre=(CActionAccelerometre*)argAction;


		//On teste alors la précondition : la condition de garde est-elle établie ?
		 if((*(tabResEtatPrecedent)==BLUETOOTH_ACTIVATION_EMISSION_ESP32_OK)
		 &&(*(tabResEtatPrecedent+1)==BLUETOOTH_MESURE_PUISSANCE_OK)
		 &&(*(tabResEtatPrecedent+2)==BLUETOOTH_COMPARAISON_FORME_ONDE_OK ))
		 {
#ifdef DEBUG_PC
				cout<<"Je suis dans la transition de SAccelerometre Vers SLedRGB"<<endl;
#endif
			 precondition=true; //Precondition établie

					 //On réalise les actions associées à l'état "SAccelerometre"
					 if(oActionAccelerometre->pingI2C()==0){//4
						 //Le ping I2C s'est bien passé et on le retient
						 oActionAccelerometre->setm_STATE(0, ACCELEROMETRE_PING_I2C_OK);
						 //Lecture de la valeur du fabricant
						 if(oActionAccelerometre->lectureValeurFabricant()==0){//3
							   //Lecture de la valeur du fabricant s'est bien passé et on le retient
							 	 oActionAccelerometre->setm_STATE(1, ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK);
								//Calibration de l'accéléromètre
								 if(oActionAccelerometre->calibration()==0){//2
									 //La Calibration de l'accéléromètre s'est bien passé et on le retient
									 oActionAccelerometre->setm_STATE(2, ACCELEROMETRE_CALIBRATION_OK);
									 //Test de l'interruption
									 if(oActionAccelerometre->testInterruptionESP32()==0){//1
										 //L"interruption s"est bien passé  et on le retient
										 oActionAccelerometre->setm_STATE(3, ACCELEROMETRE_TEST_INTERRUPTION_OK);
									 }else{//1 Echec interruption

										 oActionAccelerometre->setm_STATE(3, ACCELEROMETRE_TEST_INTERRUPTION_NOK);
									 }

								 }else{//2 Echec Calibration de l'accéléromètre

									 oActionAccelerometre->setm_STATE(2, ACCELEROMETRE_CALIBRATION_NOK);
									 retour=ACCELEROMETRE_CALIBRATION_NOK;
								 	 }
						 	 }else{//3 Echec Lecture de la valeur du fabricant

							 oActionAccelerometre->setm_STATE(1, ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_NOK);
							 retour=ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_NOK;
						 	 }
					 }else{//Echec ping accelemrometre

						 oActionAccelerometre->setm_STATE(0, ACCELEROMETRE_PING_I2C_NOK );
						 retour=ACCELEROMETRE_PING_I2C_NOK ;
					 }
		}//if

		 //On construit le retour de la méthode
		 //La précondition est OK et la dernière action
		 //réussi
		 if((precondition)&&((*(oActionAccelerometre->getm_STATE()+3))==ACCELEROMETRE_TEST_INTERRUPTION_OK)){

	#ifdef DEBUG_PC
			 cout<<"Transition de transition de SAccelerometre Vers SLedRGB réussie"<<endl;
			 cout<<"****************************************************************"<<endl;
			 cout<<endl;
	#endif
					 retour=1;

				/* }else{

					 //La dernière action a échoué
					 if(precondition==true)
					 {
						 retour=ACCELEROMETRE_TEST_INTERRUPTION_NOK;
					 }*/
			 }

		 return retour;
}

