/**
 * @file          CActionBluetooth.cpp
 * @version       1.0
 * @date          Created on: 29 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright Emkaelectronique
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
 *        (#) IDE          : Eclipse Papyrus - Decembre 2022 - Plugin CDT 
 *
 * ===================================================================
 *                 ##### Historique des modifications #####
 * ===================================================================
 * 
 *        (#) Version   | Date           | Auteur              | Nature de la modification
 *            1.00        29 juin 2022         H. MEGHOUACHE         Creation
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
#include "../../Headers/Actions/CActionBluetooth.h"

CActionBluetooth::CActionBluetooth() {
	// TODO Auto-generated constructor stub

	//Echecs par défaut
	this->m_STATE[0]=BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK;
	this->m_STATE[1]=BLUETOOTH_MESURE_PUISSANCE_NOK;
	this->m_STATE[2]=BLUETOOTH_COMPARAISON_FORME_ONDE_NOK;
}

CActionBluetooth::~CActionBluetooth() {
	// TODO Auto-generated destructor stub
}


uint CActionBluetooth::actiovationEmissionESP32(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_BLUETOOTH_ACTIVATION_EMISSION_ESP32_OK
	res=0;
#endif
#ifdef BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Activation émission ESP32"<<endl;
#endif


	return res;
}

uint CActionBluetooth::mesurePuissanceBluetooth()
{
	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_BLUETOOTH_MESURE_PUISSANCE_OK
	res=0;
#endif
#ifdef UNIT_BLUETOOTH_MESURE_PUISSANCE_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Mesure puissance par système externe"<<endl;
#endif

	return res;

}



uint CActionBluetooth:: comparaisonFormeOnde()
{
	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_BLUETOOTH_COMPARAISON_FORME_ONDE_OK
	res=0;
#endif
#ifdef UNIT_BLUETOOTH_COMPARAISON_FORME_ONDE_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Comparaison de la forme de l'onde"<<endl;
#endif

	return res;
}


