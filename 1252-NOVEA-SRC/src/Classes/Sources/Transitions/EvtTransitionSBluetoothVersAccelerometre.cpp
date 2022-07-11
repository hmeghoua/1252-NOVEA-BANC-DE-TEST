/**
 * @file          EvtTransitionSBluetoothVersAccelerometre.cpp
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
#include "../../Headers/Transitions/EvtTransitionSBluetoothVersAccelerometre.h"

#include "../../Headers/Actions/CActionLora.h"
#include "../../Headers/Actions/CActionBluetooth.h"





EvtTransitionSBluetoothVersAccelerometre::EvtTransitionSBluetoothVersAccelerometre() {
	// TODO Auto-generated constructor stub

}

EvtTransitionSBluetoothVersAccelerometre::~EvtTransitionSBluetoothVersAccelerometre() {
	// TODO Auto-generated destructor stub
}

/**
  * @brief  Condition de garde entre les �tats SBluetooth et SAccelerometre
  * @brief  Pr�conditions : LORA_ACTIVATION_EMETTEUR_OK            :   l'Activation de l'emetteur Lora s'est bien pass�
  *          				LORA_MESURE_PUISSANCE_OK               :   La mesure de puissance a pu se faire
  *          				LORA_COMPARAISON_FORME_ONDE_OK         :   La forme de l'onde est conforme
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
  *          				BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK :  Echec de l'activation de l'emetteur
  *          				BLUETOOTH_MESURE_PUISSANCE_NOK          :  Echec de la mesure de puissance
  *          				BLUETOOTH_COMPARAISON_FORME_ONDE_NOK    :  Echec de la comparaison de forme d'onde
  */

const uint EvtTransitionSBluetoothVersAccelerometre::onTransitionEvent(CAction*argAction,CAction*argActionBefore){


	uint retour=100;    	     //Contient le retour des appels la m�thode : �chec par d�faut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'�tat de l'action pr�c�dente associ�e � l'�tat "Scan"
	CActionLora* oSLora=(CActionLora*)argActionBefore;
	uint *tabResEtatPrecedent=oSLora->getm_STATE();


	//L'objet "oActionLora pour r�aliser les actions pr�vues dans l'�tat SLora
	CActionBluetooth* oActionBluetooth=(CActionBluetooth*)argAction;


	//On teste alors la pr�condition : la condition de garde est-elle �tablie ?
	 if((*(tabResEtatPrecedent)==LORA_ACTIVATION_EMETTEUR_OK)
	   &&(*(tabResEtatPrecedent+1)==LORA_MESURE_PUISSANCE_OK)
	   &&(*(tabResEtatPrecedent+2)==LORA_COMPARAISON_FORME_ONDE_OK))
	 {

#ifdef DEBUG_PC
				cout<<"Je suis dans la transition de SBluetooth  Vers SAccelerometre"<<endl;
#endif

		 precondition=true; //Precondition �tablie

		 //On r�alise les actions associ�es � l'�tat "SBluetooth"
		 //Activation du Bluetooth
		 if(oActionBluetooth->actiovationEmissionESP32()==0){
			 //L'activation de l'emetteur s'est bien pass� et on le retient
			 oActionBluetooth->setm_STATE(0, BLUETOOTH_ACTIVATION_EMISSION_ESP32_OK);
			 //Mesure de la puissance Bluetooth
			 if(oActionBluetooth->mesurePuissanceBluetooth()==0){
				   //Mesure de la puissance Bluetooth s'est bien pass� et on le retient
					oActionBluetooth->setm_STATE(1, BLUETOOTH_MESURE_PUISSANCE_OK);
					//Comparaison de l'onde avec un r�f�rentiel
					 if(oActionBluetooth->comparaisonFormeOnde()==0){
						 //Comparaison de l'onde avec un r�f�rentiel s'est bien pass� et on le retient
						 oActionBluetooth->setm_STATE(2, BLUETOOTH_COMPARAISON_FORME_ONDE_OK);
					 }else{

						 oActionBluetooth->setm_STATE(2, BLUETOOTH_COMPARAISON_FORME_ONDE_NOK);
						 retour=BLUETOOTH_COMPARAISON_FORME_ONDE_NOK;
					 }
			 }else{

				 	 oActionBluetooth->setm_STATE(1, BLUETOOTH_MESURE_PUISSANCE_NOK);
					 retour=BLUETOOTH_MESURE_PUISSANCE_NOK;
			 }
		 }else{

			 oActionBluetooth->setm_STATE(0, BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK );
			 retour=BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK ;
		 }
	 }


	 //On construit le retour de la m�thode
	 //La pr�condition est OK et la derni�re action
	 //a r�ussi
	 if((precondition)&&((*(oActionBluetooth->getm_STATE()+2))==BLUETOOTH_COMPARAISON_FORME_ONDE_OK)){

#ifdef DEBUG_PC
				cout<<"Transition de transition de SBluetooth  Vers SAccelerometre r�ussie"<<endl;
				cout<<"****************************************************************"<<endl;
				cout<<endl;
#endif
				 retour=1;

			 }/*else{

				 //La derni�re action a �chou�
				 if(precondition==true)
				 {
					 retour=BLUETOOTH_COMPARAISON_FORME_ONDE_NOK;
				 }
		 }*/

	 return retour;

}






