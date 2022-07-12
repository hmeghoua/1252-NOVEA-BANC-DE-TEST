/**
 * @file          CActionLora.h
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
#ifndef CLASSES_HEADERS_ACTIONS_CACTIONLORA_H_
#define CLASSES_HEADERS_ACTIONS_CACTIONLORA_H_

#include <CAction.h>
#include "../Global.h"

class CActionLora: public CAction {
public:
	CActionLora();
	virtual ~CActionLora();
	uint activation_Emetteur();
	uint Mesurer_puissance_lora();
	uint comparaison_forme_onde();

	uint *getm_STATE(){return m_STATE;}
	void setm_STATE(uint argRang, uint argNewValue){

		m_STATE[argRang]=argNewValue;
		this->m_resultatActionCourante=argNewValue;
	}

private:
	uint m_STATE[3];
};

#endif /* CLASSES_HEADERS_ACTIONS_CACTIONLORA_H_ */
