/**
 * @file          EvtTransistionSMisEnPlaceCarteVersSCan.cpp
 * @version       1.0
 * @date          Created on: 16 juin 2022
 * @author        hme
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
  * @brief  Condition de garde entre les �tats SMisEnPlaceCarte et SCan
  * @brief  Pr�conditions :
  * @brief  Postconditions: FLASH_QR_CODE_OK            :  Le QR Code est OK
  *                         ALIMENTATION_5V_OK          :  L'alimentation de la carte en 5V est OK
  * @brief  Invariants    : DETECTION_PRESENCE_CARTE_OK :  La carte � tester est toujours pr�sente
  * @param  entr�e        : aucun
  * @param  sortie        : aucun
  * @param  entr�e/sortie : argAction                    : contient les m�thodes m�tiers qui g�rent la transition
  * @retval  1                                           : La condition de garde s'est bien pass�e
  *          100                                         : Echec de la transition
  *          DETECTION_PRESENCE_CARTE_NOK                : Invariant pas v�rifi� : absence de carte
  *          FLASH_QR_CODE_NOK                           : Echec de lecture du QR Code
  *          ALIMENTATION_5V_NOK                         : Echec de l'alimentation de la carte en 5 volts
  */

const /*string*/uint Evt_Transistion_SMisEnPlaceCarte_Vers_SCan::onTransitionEvent(CAction*argAction, CAction*argActionBefore)
{

	uint retour=100; 	     //Echec de la condition de garde de la transition par defaut
	bool invariant=false;                //Echec de l'invariant par defaut

	//L'objet "oMiseEnPlaceCarte" pour r�aliser les actions pr�vues dans l'�tat SMisEnPlaceCarte
	CActionMiseEnPlaceCarte* oMiseEnPlaceCarte=(CActionMiseEnPlaceCarte*)argAction;

#ifdef DEBUG_PC
	cout<<"Je suis dans la transition de SMisEnPlaceCarte vers SCan"<<endl;
#endif

	//On r�alise les actions associ�es � l'�tat "Scan"
    //Mais avant, on teste si il y a bien une carte pr�sente
	//On teste l'invariant
	if(oMiseEnPlaceCarte->detecterPresenceCarte()==0){

		//L'invariant est v�rifi� : on positionne la valeur de retour..
		invariant=true;
		//..Et on le retient
		oMiseEnPlaceCarte->setm_STATE(0, DETECTION_PRESENCE_CARTE_OK);
		//oMiseEnPlaceCarte->setm_STATE_MEMOIRE(DETECTION_PRESENCE_CARTE_OK, DETECTION_PRESENCE_CARTE_OK);

		//argAction->setm_resultatActionCourante(DETECTION_PRESENCE_CARTE_OK);
	//	cout<<oMiseEnPlaceCarte->getm_resultatActionCourante()<<endl;
		//Flash du QRCode
		if(oMiseEnPlaceCarte->flacherQRCode()==0){
			//Le Flash du QRCode a r�ussi et le retient
			oMiseEnPlaceCarte->setm_STATE(1, FLASH_QR_CODE_OK);
			//oMiseEnPlaceCarte->setm_resultatActionCourante(FLASH_QR_CODE_OK);
			//Alimentation de la carte en 5 volts
			if(oMiseEnPlaceCarte->alimenterCarteEnCinqVolts()==0){
				//L'alimentation de la carte en 5V a r�ussi et on le retient
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
	cout<<"Transition de transition de SMisEnPlaceCarte vers SCan r�ussie"<<endl;
	cout<<"****************************************************************"<<endl;
	cout<<endl;
#endif

	 	 //On construit le retour de la m�thode : invariant r�sussi et derni�re action
	     //"alimenterCarteEnCinqVolts" r�ussie
		 if((invariant)&&((*(oMiseEnPlaceCarte->getm_STATE()+2))==ALIMENTATION_5V_OK)){

			 //Tout est OK
			 retour=1;

		 }else{

			 if(!invariant){

				 retour=DETECTION_PRESENCE_CARTE_NOK; //Pas de carte : on ne peut continuer

			 }else{

				 	 	 //La derni�re action a �chou�
				 	 	 retour=ALIMENTATION_5V_NOK;
			 }
		 }

		return retour;
}



Evt_Transistion_SMisEnPlaceCarte_Vers_SCan::~Evt_Transistion_SMisEnPlaceCarte_Vers_SCan() {
	// TODO Auto-generated destructor stub
}

