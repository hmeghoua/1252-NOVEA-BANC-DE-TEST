/**
 * @file          CActionLora.cpp
 * @version       1.0
 * @date          Created on: 28 juin 2022
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
 *            1.00        28 juin 2022         H. MEGHOUACHE         Creation
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
#include "../../Headers/Actions/CActionLora.h"

CActionLora::CActionLora() {
	// TODO Auto-generated constructor stub


		m_STATE[0]= LORA_ACTIVATION_EMETTEUR_NOK;
		m_STATE[1]=LORA_MESURE_PUISSANCE_NOK;
		m_STATE[2]=LORA_COMPARAISON_FORME_ONDE_NOK;

}

CActionLora::~CActionLora() {
	// TODO Auto-generated destructor stub
}

uint CActionLora::activation_Emetteur(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_LORA_ACTIVATION_EMETTEUR_OK
	res=0;
#endif
#ifdef UNIT_LORA_ACTIVATION_EMETTEUR_NOK
	res=-1;
#endif

#ifdef DEBUG_PC

		cout<<"------"<<"Carte NOVCOM : Activation Emetteur"<<endl;

#endif

		return res;


}

uint CActionLora::Mesurer_puissance_lora(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_LORA_MESURE_PUISSANCE_OK
	res=0;
#endif
#ifdef UNIT_LORA_MESURE_PUISSANCE_NOK
	res=-1;
#endif

#ifdef DEBUG_PC

				cout<<"------"<<"Carte NOVCOM : Mesure puissance par système externe"<<endl;

#endif

	return res;

}

uint CActionLora::comparaison_forme_onde(){

	short int res=-2;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_LORA_COMPARAISON_FORME_ONDE_OK
	res=0;
#endif
#ifdef UNIT_LORA_COMPARAISON_FORME_ONDE_NOK
	res=-1;
#endif


#ifdef DEBUG_PC

				cout<<"------"<<"Carte NOVCOM : Comparaison de la forme de l'onde"<<endl;

#endif

	return res;

}

