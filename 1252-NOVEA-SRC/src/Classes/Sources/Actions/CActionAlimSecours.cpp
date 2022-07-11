/**
 * @file          CActionAlimSecours.cpp
 * @version       1.0
 * @date          Created on: 30 juin 2022
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
 *            1.00        30 juin 2022         H. MEGHOUACHE         Creation
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
#include "../../Headers/Actions/CActionAlimSecours.h"

CActionAlimSecours::CActionAlimSecours() {
	// TODO Auto-generated constructor stub

	//Echec des actions par défaut
	this->m_STATE[0]=ALIM_SECOURS_30V_NOK;
	this->m_STATE[1]=ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK;

}

CActionAlimSecours::~CActionAlimSecours() {
	// TODO Auto-generated destructor stub
}


uint CActionAlimSecours::alimenterCarteEn30V(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_ALIM_SECOURS_30V_OK
	res=0;
#endif
#ifdef UNIT_ALIM_SECOURS_30V_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Alimentation de secours en 30v OK"<<endl;
#endif

	return res;

}


uint CActionAlimSecours::mesurerHausseAlimentation(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_ALIM_SECOURS_MESURE_HAUSSE_ALIM_OK
	res=0;
#endif
#ifdef UNIT_ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : mesure de la hausse d'alimentation OK"<<endl;
#endif
	return res;

}

