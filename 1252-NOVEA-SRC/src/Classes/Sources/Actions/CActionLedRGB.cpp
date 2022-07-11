/**
 * @file          CActionLedRGB.cpp
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
#include "../../Headers/Actions/CActionLedRGB.h"

CActionLedRGB::CActionLedRGB() {
	// TODO Auto-generated constructor stub
	this->m_STATE[0]=LED_RGB_R_NOK;
	this->m_STATE[1]=LED_RGB_G_NOK;
	this->m_STATE[2]=LED_RGB_B_NOK;

}


CActionLedRGB::~CActionLedRGB() {
	// TODO Auto-generated destructor stub
}


uint CActionLedRGB::testLedR(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

	#ifdef UNIT_LED_RGB_R_OK
		res=0;
	#endif
	#ifdef UNIT_LED_RGB_R_NOK
		res=-1;
	#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Vérification de la couleur R"<<endl;
#endif

	return res;


}
uint CActionLedRGB::testLedG(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

	#ifdef UNIT_LED_RGB_G_OK
		res=0;
	#endif
	#ifdef UNIT_LED_RGB_G_NOK
		res=-1;
	#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Vérification de la couleur G"<<endl;
#endif


	return res;


}
uint CActionLedRGB::testLedB(){


	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

	#ifdef UNIT_LED_RGB_B_OK
		res=0;
	#endif
	#ifdef UNIT_LED_RGB_B_NOK
		res=-1;
	#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Vérification de la couleur B"<<endl;
#endif
	return res;
}

