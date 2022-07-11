/**
 * @file          CActionConsommation.cpp
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
#include "../../Headers/Actions/CActionConsommation.h"

CActionConsommation::CActionConsommation() {
	// TODO Auto-generated constructor stub

	this->m_STATE[0]=CONSOMMATION_MESURE_SOUS_5V_NOK;

}

CActionConsommation::~CActionConsommation() {
	// TODO Auto-generated destructor stub
}



uint CActionConsommation::messureConsommation5V(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_CONSOMMATION_MESURE_SOUS_5V_OK
	res=0;
#endif

#ifdef UNIT_CONSOMMATION_MESURE_SOUS_5V_NOK
	res=-1;
#endif


#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Mesure de la consommation du système sous 5V"<<endl;
#endif

	return res;

}


