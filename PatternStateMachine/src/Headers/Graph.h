/**
 * @file          Graph.h
 * @version       1.0
 * @date          Created on: 16 juin 2022
 * @author        hme
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
 *            1.00        20/06/2022     H. MEGHOUACHE         Creation
 *
 * @endverbatim
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2022 emkaELECTRONIQUE </center></h2>
 *
 ******************************************************************************
 *
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include "CStateBanc.h"
#include "Global.h"
#include "CAction.h"
#include "Transition.h"
#include "Util/CScreen.h"
#include <iostream>
#include <map>
#include <string>


class Graph {

public:

	Graph(map<string, CStateBanc*> argListeEtat, map<string,CAction*> argListeActions) ;

		void setListeTransitions( map<string,Transition*> argNewValue){

				transitions_=argNewValue;

		}

	    void StartGraph();




	virtual ~Graph();

private:


    map<string, CStateBanc*> states_;
    map<string,Transition*>  transitions_;
    map<string,CAction*> listeDesActions_;
    Transition* currentTransition_;
    CStateBanc * currentState_;
    CAction * currentAction_,*currentActionBefore_;
    string nextState_;
    CScreen *lcd_;

};

#endif /* GRAPH_H_ */
