/**
 * @file          CActionLuxmetre.cpp
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
#include "../../Headers/Actions/CActionLuxmetre.h"

CActionLuxmetre::CActionLuxmetre() {

	// TODO Auto-generated constructor stub
	this->m_STATE[0]=LUXMETRE_PING_I2C_NOK;
	this->m_STATE[1]=LUXMETRE_CALIBRATION_NOK;
	this->m_STATE[2]=LUXMETRE_LECTURE_VALEUR_SOURCE_NOK;

}

CActionLuxmetre::~CActionLuxmetre() {
	// TODO Auto-generated destructor stub
}

uint CActionLuxmetre::pingI2CLuxmetre(){


	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_LUXMETRE_PING_I2C_OK
	res=0;
#endif
#ifdef LUXMETRE_PING_I2C_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM LUXMETRE : Ping I2C"<<endl;
#endif

	return res;

}
uint CActionLuxmetre::calibrationLuxmetre(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_LUXMETRE_CALIBRATION_OK
	res=0;
#endif
#ifdef LUXMETRE_CALIBRATION_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM LUXMETRE : Calibration (mise à 0)"<<endl;
#endif

	return res;
}
uint CActionLuxmetre::lectureValeurSourceLumiere(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif
#ifdef UNIT_LUXMETRE_LECTURE_VALEUR_SOURCE_OK
	res=0;
#endif
#ifdef LUXMETRE_LECTURE_VALEUR_SOURCE_NOK
	res=-1;
#endif
#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM LUXMETRE : Lecture de la valeur d'une source de lumière"<<endl;
#endif

	return res;
}

