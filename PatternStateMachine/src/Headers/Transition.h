/**
 * @file          Transition.h
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
#ifndef TRANSITION_H_
#define TRANSITION_H_


//#include "../../Global.h"
#include <iostream>
using namespace std;

class Graph;
class CStateBanc;
class CAction;


class Transition {

public:
	Transition();
	virtual ~Transition();

	Transition(Graph* agregGraphe);

	   	void setSourceState( CStateBanc * ArgNewValue){ this->m_SourceState=ArgNewValue;}
	   	void setTargetState(CStateBanc *ArgNewValue){ this->m_TargetState=ArgNewValue;}
	   	bool triggered(CAction*argAction,CAction*argActionBefore){

#ifdef DEBUG_PC
	   		cout<<"Test de la transition"<<endl;
#endif
	   	     //Test si la transition est Ok
	   		/*unsigned short int ret=this->onTransitionEvent(argAction,argActionBefore);
	   		cout<<"Retour de la transition : "<<ret<<endl;
	   	    if(ret==1){

	   	    	return true;
	   	    }else{

	   	    	return false;
	   	    }*/

	   		if(this->onTransitionEvent(argAction,argActionBefore)==1){return true;}
	   	    else{

	   	    	return false;
	   	    }

	 }

private:

   	Graph      * m_AgregGraphe;
    CStateBanc * m_SourceState;
    CStateBanc * m_TargetState;
    virtual const /*string*/unsigned short int onTransitionEvent(CAction*argAction,CAction*argActionBefore)=0;
};

#endif /* TRANSITION_H_ */
