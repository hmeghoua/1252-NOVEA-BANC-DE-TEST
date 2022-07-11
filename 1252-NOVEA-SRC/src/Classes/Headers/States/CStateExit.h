/**
 * @file          CStateExit.h
 * @version       1.0
 * @date          Created on: 24 juin 2022
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
 *            1.00        24 juin 2022         H. MEGHOUACHE         Creation
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
#ifndef CLASSES_HEADERS_STATES_CSTATEEXIT_H_
#define CLASSES_HEADERS_STATES_CSTATEEXIT_H_

#include <CStateBanc.h>

class CStateExit: public CStateBanc {
public:
	CStateExit();
	virtual ~CStateExit();

private:

	const string DoSomething( CAction*argAction,CAction*argActionBefore ) {

		return "lastState";

	}
};

#endif /* CLASSES_HEADERS_STATES_CSTATEEXIT_H_ */
