/**
 * @file          CActionAccelerometre.cpp
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
#include "../../Headers/Actions/CActionAccelerometre.h"

CActionAccelerometre::CActionAccelerometre() {
	// TODO Auto-generated constructor stub

}

CActionAccelerometre::~CActionAccelerometre() {
	// TODO Auto-generated destructor stub
}



uint CActionAccelerometre::pingI2C(){


	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_ACCELEROMETRE_PING_I2C_OK
	res=0;
#endif
#ifdef UNIT_ACCELEROMETRE_PING_I2C_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Ping I2C"<<endl;
#endif

	return res;

}

uint CActionAccelerometre::lectureValeurFabricant(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK
	res=0;
#endif
#ifdef UNIT_ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Lecture valeur fabricant"<<endl;
#endif

	return res;
}

uint CActionAccelerometre::calibration(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_ACCELEROMETRE_CALIBRATION_OK
	res=0;
#endif
#ifdef UNIT_ACCELEROMETRE_CALIBRATION_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Calibration (mise à 0)"<<endl;
#endif

	return res;
}

uint CActionAccelerometre::testInterruptionESP32(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_ACCELEROMETRE_TEST_INTERRUPTION_OK
	res=0;
#endif
#ifdef UNIT_ACCELEROMETRE_TEST_INTERRUPTION_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Test d'interruption sur ESP32"<<endl;
#endif

	return res;
}

