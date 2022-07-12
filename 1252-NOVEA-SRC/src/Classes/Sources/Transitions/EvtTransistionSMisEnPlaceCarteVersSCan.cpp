/**
 * @file          EvtTransistionSMisEnPlaceCarteVersSCan.cpp
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
 * <h2><center>&copy; COPYRIGHT 2020 emkaELECTRONIQUE </center></h2>
 *
 ******************************************************************************
 *
 */
#include "../../Headers/Global.h"
#include "../../Headers/Transitions/EvtTransistionSMisEnPlaceCarteVersSCan.h"
//#include "../../Pattern/Headers/Transition.h"
//#include "../../Pattern/Headers/Graph.h"
#include "../../Headers/Actions/CActionMiseEnPlaceCarte.h"

#include <Transition.h>
#include <Graph.h>
#include <CAction.h>


Evt_Transistion_SMisEnPlaceCarte_Vers_SCan::Evt_Transistion_SMisEnPlaceCarte_Vers_SCan()
	// TODO Auto-generated constructor stub
{

}

/**
  * @brief  Condition de garde entre les états SMisEnPlaceCarte et SCan
  * @brief  Préconditions :
  * @brief  Postconditions: FLASH_QR_CODE_OK            :  Le QR Code est OK
  *                         ALIMENTATION_5V_OK          :  L'alimentation de la carte en 5V est OK
  * @brief  Invariants    : DETECTION_PRESENCE_CARTE_OK :  La carte à tester est toujours présente
  * @param  entrée        : aucun
  * @param  sortie        : aucun
  * @param  entrée/sortie : argAction                    : contient les méthodes métiers qui gèrent la transition
  * @retval  1                                           : La condition de garde s'est bien passée
  *          100                                         : Echec de la transition
  *          DETECTION_PRESENCE_CARTE_NOK                : Invariant pas vérifié : absence de carte
  *          FLASH_QR_CODE_NOK                           : Echec de lecture du QR Code
  *          ALIMENTATION_5V_NOK                         : Echec de l'alimentation de la carte en 5 volts
  */

const /*string*/uint Evt_Transistion_SMisEnPlaceCarte_Vers_SCan::onTransitionEvent(CAction*argAction, CAction*argActionBefore)
{

	uint retour=100; 	     //Echec de la condition de garde de la transition par defaut
	bool invariant=false;                //Echec de l'invariant par defaut

	//L'objet "oMiseEnPlaceCarte" pour réaliser les actions prévues dans l'état SMisEnPlaceCarte
	CActionMiseEnPlaceCarte* oMiseEnPlaceCarte=(CActionMiseEnPlaceCarte*)argAction;

#ifdef DEBUG_PC
	cout<<"Je suis dans la transition de SMisEnPlaceCarte vers SCan"<<endl;
#endif

	//On réalise les actions associées à l'état "Scan"
    //Mais avant, on teste si il y a bien une carte présente
	//On teste l'invariant
	if(oMiseEnPlaceCarte->detecterPresenceCarte()==0){

		//L'invariant est vérifié : on positionne la valeur de retour..
		invariant=true;
		//..Et on le retient
		oMiseEnPlaceCarte->setm_STATE(0, DETECTION_PRESENCE_CARTE_OK);


		//argAction->setm_resultatActionCourante(DETECTION_PRESENCE_CARTE_OK);
	//	cout<<oMiseEnPlaceCarte->getm_resultatActionCourante()<<endl;
		//Flash du QRCode
		if(oMiseEnPlaceCarte->flacherQRCode()==0){
			//Le Flash du QRCode a réussi et le retient
			oMiseEnPlaceCarte->setm_STATE(1, FLASH_QR_CODE_OK);
			//oMiseEnPlaceCarte->setm_resultatActionCourante(FLASH_QR_CODE_OK);
			//Alimentation de la carte en 5 volts
			if(oMiseEnPlaceCarte->alimenterCarteEnCinqVolts()==0){
				//L'alimentation de la carte en 5V a réussi et on le retient
				oMiseEnPlaceCarte->setm_STATE(2, ALIMENTATION_5V_OK);
				//oMiseEnPlaceCarte->setm_resultatActionCourante(ALIMENTATION_5V_OK);

			}else{
					oMiseEnPlaceCarte->setm_STATE(2, ALIMENTATION_5V_NOK);
					//oMiseEnPlaceCarte->setm_resultatActionCourante(ALIMENTATION_5V_NOK);
					retour=ALIMENTATION_5V_NOK;
			}

		}else{

			oMiseEnPlaceCarte->setm_STATE(1, FLASH_QR_CODE_NOK);
		//	oMiseEnPlaceCarte->setm_resultatActionCourante(FLASH_QR_CODE_NOK);
			retour=FLASH_QR_CODE_NOK;
		}

	}else{
			oMiseEnPlaceCarte->setm_STATE(0, DETECTION_PRESENCE_CARTE_NOK);
			//oMiseEnPlaceCarte->setm_resultatActionCourante(DETECTION_PRESENCE_CARTE_NOK);
			retour=DETECTION_PRESENCE_CARTE_NOK;
	}



#ifdef DEBUG_PC
	cout<<"Transition de transition de SMisEnPlaceCarte vers SCan réussie"<<endl;
	cout<<"****************************************************************"<<endl;
	cout<<endl;
#endif

	 	 //On construit le retour de la méthode : invariant résussi et dernière action
	     //"alimenterCarteEnCinqVolts" réussie
		 if((invariant)&&((*(oMiseEnPlaceCarte->getm_STATE()+2))==ALIMENTATION_5V_OK)){

			 //Tout est OK
			 retour=1;

		 }else{

			 if(!invariant){

				 retour=DETECTION_PRESENCE_CARTE_NOK; //Pas de carte : on ne peut continuer

			 }else{

				 	 	 //La dernière action a échoué
				 	 	 retour=ALIMENTATION_5V_NOK;
			 }
		 }

		return retour;
}



Evt_Transistion_SMisEnPlaceCarte_Vers_SCan::~Evt_Transistion_SMisEnPlaceCarte_Vers_SCan() {
	// TODO Auto-generated destructor stub
}

