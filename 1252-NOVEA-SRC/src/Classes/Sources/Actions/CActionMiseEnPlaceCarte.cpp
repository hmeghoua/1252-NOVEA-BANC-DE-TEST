/**
 * @file          CActionMiseEnPlaceCarte.cpp
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright Emkaelectronique
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
 *        (#) IDE          : Eclipse Papyrus - Decembre 2022 - Plugin CDT 
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
 * <h2><center>&copy; COPYRIGHT 2022 EmkaELECTRONIQUE </center></h2>
 *******************************************************************************
 *
 */
#include "../../Headers/Actions/CActionMiseEnPlaceCarte.h"
using namespace std;

CActionMiseEnPlaceCarte::CActionMiseEnPlaceCarte() {
	// TODO Auto-generated constructor stub

	/*Echecs de la postcondition de transition par d�faut*/
	m_STATE[0]= DETECTION_PRESENCE_CARTE_NOK;
	m_STATE[1]=FLASH_QR_CODE_NOK;
	m_STATE[2]=ALIMENTATION_5V_NOK;

}



CActionMiseEnPlaceCarte::~CActionMiseEnPlaceCarte() {
	// TODO Auto-generated destructor stub
}

/**
  * @brief  D�tection pr�sence de la carte
  * @brief  Pr�conditions :
  * @brief  Postconditions:
  * @brief  Invariants    :
  * @param  entr�e        : aucun
  * @param  sortie        : aucun
  * @param  entr�e/sortie : aucun
  * @retval  0 si La carte est d�tect�e
  *          1 si La carte n'est pas d�tect�e
  *         -1 Erreur de d�tection de la pr�sence carte
  */
uint CActionMiseEnPlaceCarte::detecterPresenceCarte(){

	short int res=100;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_TEST_PRESENCE_CARTE_OK
	res=0;
#endif
#ifdef UNIT_TEST_PRESENCE_CARTE_NOK
	res=-1;
#endif

#if defined (DEBUG_PC)
	cout<<"------"<<"Carte NOVCOM : D�tection pr�sence carte"<<endl;
#endif

	return res;

}

/**
  * @brief  Flash le QRCode de la carte
  * @brief  Pr�conditions :
  * @brief  Postconditions:
  * @brief  Invariants    : Pr�sence de la carte
  * @param  entr�e        : aucun
  * @param  sortie        : aucun
  * @param  entr�e/sortie : aucun
  * @retval  0 Le QR Code de la carte est OK
  *          1 Le QR Code de la carte est NOK
  *         -1 Erreur de lecture du QR Code
  */
uint CActionMiseEnPlaceCarte::flacherQRCode(){

	short int res=100;

#ifdef MODE_PROD
	res=0;
#endif

#ifdef UNIT_TEST_FLASH_QR_CODE_OK
	res=0;
#endif
#ifdef UNIT_TEST_FLASH_QR_CODE_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
		cout<<"------"<<"Carte NOVCOM : Flash QR code sur embase"<<endl;
#endif

	return res;

}

/**
  * @brief  Alimente la carte en 5 volts
  * @brief  Pr�conditions :
  * @brief  Postconditions:
  * @brief  Invariants    : Pr�sence de la carte
  * @param  entr�e        : aucun
  * @param  sortie        : aucun
  * @param  entr�e/sortie : aucun
  * @retval  0 L'alimentation de la carte en 5 volts est OK
  *          1 L'alimentation de la carte en 5 volts est NOK
  *         -1 Erreur de tentative d'alimentation de la carte en 5 volts
  */

uint CActionMiseEnPlaceCarte::alimenterCarteEnCinqVolts()
{

	short int res=100;

#ifdef MODE_PROD
	res=0;
#endif


#ifdef UNIT_TEST_ALIMENTATION_5V_OK
	res=0;
#endif

#ifdef UNIT_TEST_ALIMENTATION_5V_NOK
	res=-1;
#endif

#ifdef DEBUG_PC
	cout<<"------"<<"Carte NOVCOM : Alimentation en 5V"<<endl;
#endif


	return res;

}

