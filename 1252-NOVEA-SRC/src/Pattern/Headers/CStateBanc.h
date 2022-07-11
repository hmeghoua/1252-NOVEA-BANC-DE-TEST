/**
 * @file          CStateBanc.h
 * @version       1.0
 * @date          Created on: 15 juin 2022
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
#ifndef CSTATEBANC_H_
#define CSTATEBANC_H_


#include <string>
using namespace std;

class Transition;
class CAction;
class CStateBanc {
public:

		CStateBanc();
		virtual ~CStateBanc();

		const string Action( CAction*argAction,CAction*argActionBefore ) { return DoSomething(argAction,argActionBefore); }
		const string Entry( CAction*argAction ) { return onEntry(argAction); }
		const string Exit( CAction*argAction ) { return onExit(argAction); }
		const string SetTransition(Transition* ArgEvt){return addTransition(ArgEvt);}
		virtual void setnomEtat(string ArgNewValue)=0;



private:

    	virtual const string DoSomething(CAction*argAction,CAction* argActionBefore ) = 0;
    	virtual const string onEntry(CAction*argAction)=0;
    	virtual const string onExit(CAction*argAction)=0;
    	virtual const string addTransition(Transition* ArgEvt)=0;


};

#endif /* CSTATEBANC_H_ */
