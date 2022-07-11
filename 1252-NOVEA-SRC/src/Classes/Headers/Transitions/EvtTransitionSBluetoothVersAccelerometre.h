/**
 * @file          EvtTransitionSBluetoothVersAccelerometre.h
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright emkaelectronique
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
 *        (#) IDE          : Eclipse Papyrus - Decembre 2012 - Plugin CDT 
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
 * <h2><center>&copy; COPYRIGHT 2020 emkaELECTRONIQUE </center></h2>
 *
 ******************************************************************************
 *
 */
#ifndef EVTTRANSITIONSBLUETOOTHVERSACCELEROMETRE_H_
#define EVTTRANSITIONSBLUETOOTHVERSACCELEROMETRE_H_

//#include "../../Pattern/Headers/Transition.h"
#include <Transition.h>
#include "../Global.h"


class Graph;

class EvtTransitionSBluetoothVersAccelerometre: public Transition {
public:


	EvtTransitionSBluetoothVersAccelerometre();
	EvtTransitionSBluetoothVersAccelerometre(Graph* agregGraphe):Transition(agregGraphe){}
	virtual ~EvtTransitionSBluetoothVersAccelerometre();

private :

		const /*string uint */unsigned short int onTransitionEvent(CAction*argAction,CAction*argActionBefore);

};

#endif /* EVTTRANSITIONSBLUETOOTHVERSACCELEROMETRE_H_ */
