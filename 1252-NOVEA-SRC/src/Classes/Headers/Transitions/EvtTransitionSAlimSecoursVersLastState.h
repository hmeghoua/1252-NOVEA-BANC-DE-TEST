/**
 * @file          EvtTransitionSAlimSecoursVersLastState.h
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
#ifndef CLASSES_SOURCES_TRANSITIONS_EVTTRANSITIONSALIMSECOURSVERSLASTSTATE_H_
#define CLASSES_SOURCES_TRANSITIONS_EVTTRANSITIONSALIMSECOURSVERSLASTSTATE_H_

//#include "../../Pattern/Headers/Transition.h"
#include <Transition.h>
#include "../Global.h"
class Graph;


class EvtTransitionSAlimSecoursVersLastState: public Transition {

public:
	EvtTransitionSAlimSecoursVersLastState();
	EvtTransitionSAlimSecoursVersLastState(Graph* agregGraphe):Transition(agregGraphe){};
	virtual ~EvtTransitionSAlimSecoursVersLastState();


private:
	const /*string uint */unsigned short int onTransitionEvent(CAction*argAction,CAction*argActionBefore);

};

#endif /* CLASSES_SOURCES_TRANSITIONS_EVTTRANSITIONSALIMSECOURSVERSLASTSTATE_H_ */
