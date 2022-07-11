/**
 * @file          EvtTransistionSMisEnPlaceCarteVersSCan.h
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
 *            1.00        29/03/2022     H. MEGHOUACHE         Creation
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
#ifndef EVTTRANSISTIONSMISENPLACECARTEVERSSCAN_H_
#define EVTTRANSISTIONSMISENPLACECARTEVERSSCAN_H_

//#include "../../Pattern/Headers/Transition.h"
#include <Transition.h>
#include "../Global.h"


class Graph;
class CAction;

class Evt_Transistion_SMisEnPlaceCarte_Vers_SCan: public Transition
{
public:

	Evt_Transistion_SMisEnPlaceCarte_Vers_SCan();
	Evt_Transistion_SMisEnPlaceCarte_Vers_SCan(Graph* agregGraphe):Transition(agregGraphe){}
	virtual ~Evt_Transistion_SMisEnPlaceCarte_Vers_SCan();

private :

		const /*string uint */unsigned short int onTransitionEvent(CAction*argAction,CAction*argActionBefore);

};

#endif /* EVTTRANSISTIONSMISENPLACECARTEVERSSCAN_H_ */
