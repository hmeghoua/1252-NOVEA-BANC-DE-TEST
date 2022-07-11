/**
 * @file          EvtTransitionSCanVersSLora.h
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright emkaelectronique
 * @details       � compl�ter
 *
 *
 * @verbatim
 * ===================================================================
 *                 ##### Client et projet #####
 * ===================================.================================
 * 
 *        (#) Client    : NOVEA
 *        (#) Projet    : BANC DE TEST NOVCOM Z
 *        (#) R�f�rence : BC 1252 002 000 800
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
#ifndef EVTTRANSITIONSCANVERSSLORA_H_
#define EVTTRANSITIONSCANVERSSLORA_H_

#include "../Global.h"
//#include "../../Pattern/Headers/Transition.h"
#include <Transition.h>

class Graph;

class EvtTransitionSCanVersSLora: public Transition {
public:


	EvtTransitionSCanVersSLora();
	EvtTransitionSCanVersSLora(Graph* agregGraphe):Transition(agregGraphe){}

	virtual ~EvtTransitionSCanVersSLora();


private :



		const /*string uint */unsigned short int onTransitionEvent(CAction*argAction,CAction*argActionBefore);
};

#endif /* EVTTRANSITIONSCANVERSSLORA_H_ */
