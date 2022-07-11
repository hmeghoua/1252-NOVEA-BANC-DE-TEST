/**
 * @file          CActionMiseEnPlaceCarte.h
 * @version       1.0
 * @date          Created on: 20 juin 2022
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
 *            1.00        20 juin 2022         H. MEGHOUACHE         Creation
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
#ifndef CACTIONMISEENPLACECARTE_H_
#define CACTIONMISEENPLACECARTE_H_

#include "../Global.h"
//#include "../../Pattern/Headers/CAction.h"
#include <CAction.h>


class CActionMiseEnPlaceCarte: public CAction {
private:
	uint m_STATE[3];
public:

	CActionMiseEnPlaceCarte();
	virtual ~CActionMiseEnPlaceCarte();

	uint detecterPresenceCarte();
	uint flacherQRCode();
	uint alimenterCarteEnCinqVolts();

	uint *getm_STATE(){return m_STATE;}
	void setm_STATE(uint argRang, uint argNewValue){m_STATE[argRang]=argNewValue;}



};

#endif /* CACTIONMISEENPLACECARTE_H_ */
