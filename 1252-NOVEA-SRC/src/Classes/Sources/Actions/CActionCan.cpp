/**
 * @file          CActionCan.cpp
 * @version       1.0
 * @date          Created on: 23 juin 2022
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
 *            1.00        23 juin 2022         H. MEGHOUACHE         Creation
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
#include "../../Headers/Actions/CActionCan.h"

CActionCan::CActionCan() {
	// TODO Auto-generated constructor stub

	m_STATE[0]= PING_CAN_NOK;
	m_STATE[1]=ECRITURE_NUM_SERIE_NOK;
	m_STATE[2]=RELECTURE_NUM_SERIE_NOK;
	m_STATE[3]=LECTURE_UUI_NOK;
	m_STATE[4]=PING_MEM_FLASH_NOK;

}

CActionCan::~CActionCan() {
	// TODO Auto-generated destructor stub
}
uint CActionCan::ping(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_PING_CAN_OK
	res=0;
#endif

#ifdef UNIT_PING_CAN_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Traitement Ping"<<endl;
#endif


	return res;


}
uint CActionCan::ecritureNumeroDeSerie(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_ECRITURE_NUM_SERIE_OK
	res=0;
#endif

#ifdef  UNIT_ECRITURE_NUM_SERIE_NOK
	res=-1;
#endif



#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Ecriture Numero de serie"<<endl;
#endif

	return res;
}
uint CActionCan::relectureNumeroDeSerie(){
	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_RELECTURE_NUM_SERIE_OK
	res=0;
#endif

#ifdef  UNIT_RELECTURE_NUM_SERIE_NOK
	res=-1;
#endif



#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Relecture Numero de serie"<<endl;
#endif

	return res;

}
uint CActionCan::lectureIdentifiant(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_LECTURE_UUI_OK
	res=0;
#endif

#ifdef  UNIT_LECTURE_UUI_NOK
	res=-1;
#endif


#ifdef DEBUG_PC
	cout<<"------"<<"Lecture Identifiant Unique"<<endl;
#endif

	return res;

}
uint CActionCan::pingMemoireFlash(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_PING_MEM_FLASH_OK
	res=0;
#endif

#ifdef   UNIT_PING_MEM_FLASH_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Ping memoire Flash"<<endl;
#endif

	return res;

}

