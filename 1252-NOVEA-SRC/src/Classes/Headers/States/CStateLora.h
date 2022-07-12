/**
 * @file          CStateLora.h
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
 *            1.00        29/03/2022     H. MEGHOUACHE         Creation
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
#ifndef CSTATELORA_H_
#define CSTATELORA_H_

//#include "../../Pattern/Headers/CStateBanc.h"
#include <CStateBanc.h>
#include "../Transitions/EvtTransitionSLoraVersSBluetooth.h"

class CAction;

class CStateLora: public CStateBanc {


public:
	CStateLora();
	virtual ~CStateLora();
	void setnomEtat(string ArgNewValue){m_nomEtat=ArgNewValue;}
	Transition* getm_transition(){return this->m_transition;}


private:

    const string DoSomething( CAction*argAction,CAction* argActionBefore ) {

#ifdef TEST_GRAPHE
        cout << "StateLora --> ";
#endif


        if(getm_transition()->triggered(argAction,argActionBefore)==true){return "StateBluetooth";}

            	else{return "testError";}


    }

    const string onEntry( CAction*argAction/*,CAction*argActionBefore */){

#ifdef DEBUG_PC
    	cout<<"****************************************************************"<<endl;
    	cout << "Entree Etat StateLora:"<<endl;
#endif
    	return "ok";
    }

    const string onExit( CAction*argAction ){

#ifdef DEBUG_PC
       	cout << "Sortie Etat StateLora"<<endl;
#endif
       	return "ok";
   }

    const string addTransition(Transition* ArgEvt){


     	this->m_transition=ArgEvt;
     	return "ok";

   }

       CStateBanc* m_destState;
       Transition* m_transition;
       string m_nomEtat;
};

#endif /* CSTATELORA_H_ */
