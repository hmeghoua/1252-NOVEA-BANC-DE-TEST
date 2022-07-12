/**
 * @file          CActionCan.h
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
#ifndef HEADERS_ACTIONS_CACTIONCAN_H_
#define HEADERS_ACTIONS_CACTIONCAN_H_

#include <CAction.h>
#include "../Global.h"


class CActionCan: public CAction {

private:

	uint m_STATE[5];

public:

	CActionCan();
	virtual ~CActionCan();

	uint ping();
	uint ecritureNumeroDeSerie();
	uint relectureNumeroDeSerie();
	uint lectureIdentifiant();
	uint pingMemoireFlash();
	uint *getm_STATE(){return m_STATE;}
	void setm_STATE(uint argRang, uint argNewValue){

		m_STATE[argRang]=argNewValue;
		this->m_resultatActionCourante=argNewValue;
	}


};

#endif /* HEADERS_ACTIONS_CACTIONCAN_H_ */
