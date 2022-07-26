/**
 * @file          1252-NOVEA-SRC.cpp
 * @author        MEGHOUACHE
 * @version       1.0
 * @date          14 juin 2022
 * @brief         Copyright   : EMKA ELECTRONIQUE.
 *
 * @details       Programme du Banc de test
 * @details       Remarque : inclure la biblioth�que "libPatternStateMachine"
 *
 */
#include "Classes/Headers/Global.h"


//Le diagramme Etat/Transition
#include <Graph.h>
#include <Transition.h>
#include <CStateBanc.h>
#include <CAction.h>
//Les transitions qui g�rent les conditions de garde
#include "Classes/Headers/Transitions/EvtTransistionSMisEnPlaceCarteVersSCan.h"
#include "Classes/Headers/Transitions/EvtTransitionSCanVersSLora.h"
#include "Classes/Headers/Transitions/EvtTransitionSLoraVersSBluetooth.h"
#include "Classes/Headers/Transitions/EvtTransitionSBluetoothVersAccelerometre.h"
#include "Classes/Headers/Transitions/EvtTransitionSAccelerometreVersSLedRGB.h"
#include "Classes/Headers/Transitions/EvtTransitionSLedRGBVersSLuxmetre.h"
#include "Classes/Headers/Transitions/EvtTransitionSLuxmetreVersSConsommation.h"
#include "Classes/Headers/Transitions/EvtTransitionSConsommationVersSAlimSecours.h"
//#include "Classes/Headers/Transitions/EvtLastState.h"
#include "Classes/Headers/Transitions/EvtTransitionSAlimSecoursVersLastState.h"


//Les �tats
#include "Classes/Headers/States/CStateAMiseEnPlaceCarte.h"
#include "Classes/Headers/States/CStateCan.h"
#include "Classes/Headers/States/CStateLora.h"
#include "Classes/Headers/States/CStateBluetooth.h"
#include "Classes/Headers/States/CStateAccelerometre.h"
#include "Classes/Headers/States/CStateLedRGB.h"
#include "Classes/Headers/States/CStateLuxmetre.h"
#include "Classes/Headers/States/CStateConsommation.h"
#include "Classes/Headers/States/CStateAlimSecours.h"

//Les actions associ�es � chaque �tat
#include "Classes/Headers/Actions/CActionMiseEnPlaceCarte.h"
#include "Classes/Headers/Actions/CActionCan.h"
#include "Classes/Headers/Actions/CActionLora.h"
#include "Classes/Headers/Actions/CActionBluetooth.h"
#include "Classes/Headers/Actions/CActionAccelerometre.h"
#include "Classes/Headers/Actions/CActionLedRGB.h"
#include "Classes/Headers/Actions/CActionLuxmetre.h"
#include "Classes/Headers/Actions/CActionConsommation.h"
#include "Classes/Headers/Actions/CActionAlimSecours.h"

//Pour g�n�rer le rapport de tests
//#include "Classes/Headers/Util/CXml.h"


//using namespace std;



int main()
{

    map<string, CStateBanc*> listeEtats;
    map<string,Transition*> listeTransitions;
    map<string,CAction*> listeDesActions;

    //Liste Des Actions
    listeDesActions["StateAMiseEnPlaceCarte"]=new CActionMiseEnPlaceCarte;
    listeDesActions["StateCan"]=new CActionCan;
    listeDesActions["StateLora"]=new CActionLora;
    listeDesActions["StateBluetooth"]=new CActionBluetooth;
    listeDesActions["StateAccelerometre"]=new CActionAccelerometre;
    listeDesActions["StateLedRGB"]=new CActionLedRGB;
    listeDesActions["StateLuxmetre"]=new CActionLuxmetre;
    listeDesActions["StateConsommation"]=new CActionConsommation;
    listeDesActions["StateAlimSecours"]=new CActionAlimSecours;


    //Liste des �tats du banc de test
    listeEtats["StateAMiseEnPlaceCarte"] = new CStateAMiseEnPlaceCarte;
    listeEtats["StateCan"]=new CStateCan;
    listeEtats["StateLora"] = new CStateLora;
    listeEtats["StateBluetooth"] = new CStateBluetooth;
    listeEtats["StateAccelerometre"] = new CStateAccelerometre;
    listeEtats["StateLedRGB"] = new CStateLedRGB;
    listeEtats["StateLuxmetre"] = new CStateLuxmetre;
    listeEtats["StateConsommation"] = new CStateConsommation;
    listeEtats["StateAlimSecours"] = new CStateAlimSecours;

    Graph graph(listeEtats,listeDesActions);

    //Liste des transitions du banc de test

    listeTransitions["StateAMiseEnPlaceCarte"]=new Evt_Transistion_SMisEnPlaceCarte_Vers_SCan(&graph);
    listeTransitions["StateCan"]= new EvtTransitionSCanVersSLora(&graph);
    listeTransitions["StateLora"]= new EvtTransitionSLoraVersSBluetooth(&graph);
    listeTransitions["StateBluetooth"]= new EvtTransitionSBluetoothVersAccelerometre(&graph);
    listeTransitions["StateAccelerometre"]= new EvtTransitionSAccelerometreVersSLedRGB(&graph);
    listeTransitions["StateLedRGB"]= new EvtTransitionSLedRGBVersSLuxmetre(&graph);
    listeTransitions["StateLuxmetre"]= new EvtTransitionSLuxmetreVersSConsommation(&graph);
    listeTransitions["StateConsommation"]= new EvtTransitionSConsommationVersSAlimSecours(&graph);
    listeTransitions["StateAlimSecours"]= new EvtTransitionSAlimSecoursVersLastState(&graph);




    //On informe le graphe des transitions
     graph.setListeTransitions(listeTransitions);

    //Lancement du graphe
    graph.StartGraph();


#ifdef TEST_GRAPHE
    cout <<"end";
#endif


    return 0;
}

