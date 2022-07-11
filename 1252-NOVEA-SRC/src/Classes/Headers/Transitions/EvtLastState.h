/**
 * @file          EvtLastState.h
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
#ifndef EVTLASTSTATE_H_
#define EVTLASTSTATE_H_

//#include "../../Pattern/Headers/Transition.h"
#include <Transition.h>
#include "../Global.h"

class Graph;

class EvtLastState: public Transition {
public:
	EvtLastState();
	EvtLastState(Graph* agregGraphe):Transition(agregGraphe){}
	virtual ~EvtLastState();

private :



		const /*string uint */unsigned short int onTransitionEvent(CAction*argAction,CAction*argActionBefore){

#ifdef DEBUG_PC
				cout<<"Je suis dans la dernière transition"<<endl;
				cout<<"------"<<"Carte NOVCOM : Alimentation en 30V"<<endl;
				cout<<"------"<<"Carte NOVCOM : Mesure d'une hausse d'alimentation"<<endl;
				cout<<"Dernière transition réussie"<<endl;
				cout<<"****************************************************************"<<endl;
				cout<<endl;
#endif



				//return "ok";
				return 1;


		}


		 unsigned short int m_STATE[3];
};

#endif /* EVTLASTSTATE_H_ */
