/**
 * @file          Global.h
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
#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <map>
#include <string>
#include "Util/CScreen.h"


//CStdString fluxDeSortie/*=new CStdString*/ ;


//TEST_GRAPHE : On vérifie que l"on passe dans tous les ETATS
//DEBUG_PC : On entre dans chaque état pour vérifier les actions réalisées

//#ifdef DEBUG_PC

#ifdef TEST_GRAPHE

	#include <iostream>
	using namespace std;


#endif

enum  EVTS_TRANSITIONS{

	DETECTION_PRESENCE_CARTE_OK=2,
	DETECTION_PRESENCE_CARTE_NOK,
	FLASH_QR_CODE_OK,
	FLASH_QR_CODE_NOK,
	ALIMENTATION_5V_OK,
	ALIMENTATION_5V_NOK,

	PING_CAN_OK,
	PING_CAN_NOK,
	ECRITURE_NUM_SERIE_OK,
	ECRITURE_NUM_SERIE_NOK,
	RELECTURE_NUM_SERIE_OK,
	RELECTURE_NUM_SERIE_NOK,
	LECTURE_UUI_OK,
	LECTURE_UUI_NOK,
	PING_MEM_FLASH_OK,
	PING_MEM_FLASH_NOK,

	LORA_ACTIVATION_EMETTEUR_OK,
	LORA_ACTIVATION_EMETTEUR_NOK,
	LORA_MESURE_PUISSANCE_OK,
	LORA_MESURE_PUISSANCE_NOK,
	LORA_COMPARAISON_FORME_ONDE_OK,
	LORA_COMPARAISON_FORME_ONDE_NOK,

	BLUETOOTH_ACTIVATION_EMISSION_ESP32_OK,
	BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK,
	BLUETOOTH_MESURE_PUISSANCE_OK,
	BLUETOOTH_MESURE_PUISSANCE_NOK,
	BLUETOOTH_COMPARAISON_FORME_ONDE_OK,
	BLUETOOTH_COMPARAISON_FORME_ONDE_NOK,

	ACCELEROMETRE_PING_I2C_OK,
	ACCELEROMETRE_PING_I2C_NOK,
	ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK,
	ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_NOK,
	ACCELEROMETRE_CALIBRATION_OK,
	ACCELEROMETRE_CALIBRATION_NOK,
	ACCELEROMETRE_TEST_INTERRUPTION_OK,
	ACCELEROMETRE_TEST_INTERRUPTION_NOK,

	LED_RGB_R_OK,
	LED_RGB_R_NOK,
	LED_RGB_G_OK,
	LED_RGB_G_NOK,
	LED_RGB_B_OK,
	LED_RGB_B_NOK,


	LUXMETRE_PING_I2C_OK,
	LUXMETRE_PING_I2C_NOK,
	LUXMETRE_CALIBRATION_OK,
	LUXMETRE_CALIBRATION_NOK,
	LUXMETRE_LECTURE_VALEUR_SOURCE_OK,
	LUXMETRE_LECTURE_VALEUR_SOURCE_NOK,

	CONSOMMATION_MESURE_SOUS_5V_OK,
	CONSOMMATION_MESURE_SOUS_5V_NOK,

	ALIM_SECOURS_30V_OK,
	ALIM_SECOURS_30V_NOK,
	ALIM_SECOURS_MESURE_HAUSSE_ALIM_OK,
	ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK

};
/*
string LcdToPrint[57]={

		"",//0
		"",//1
		"DETECTION_PRESENCE_CARTE_OK",//2
		"DETECTION_PRESENCE_CARTE_NOK",
		"FLASH_QR_CODE_OK",
		"FLASH_QR_CODE_NOK",
		"ALIMENTATION_5V_OK",
		"ALIMENTATION_5V_NOK",

		"PING_CAN_OK",//8
		"PING_CAN_NOK",
		"ECRITURE_NUM_SERIE_OK",
		"ECRITURE_NUM_SERIE_NOK",
		"RELECTURE_NUM_SERIE_OK",
		"RELECTURE_NUM_SERIE_NOK",
		"LECTURE_UUI_OK",
		"LECTURE_UUI_NOK",
		"PING_MEM_FLASH_OK",
		"PING_MEM_FLASH_NOK",

		"LORA_ACTIVATION_EMETTEUR_OK",//18
		"LORA_ACTIVATION_EMETTEUR_NOK",
		"LORA_MESURE_PUISSANCE_OK",
		"LORA_MESURE_PUISSANCE_NOK",
		"LORA_COMPARAISON_FORME_ONDE_OK",
		"LORA_COMPARAISON_FORME_ONDE_NOK",

		"BLUETOOTH_ACTIVATION_EMISSION_ESP32_OK", //24
		"BLUETOOTH_ACTIVATION_EMISSION_ESP32_NOK",
		"BLUETOOTH_MESURE_PUISSANCE_OK",
		"BLUETOOTH_MESURE_PUISSANCE_NOK",
		"BLUETOOTH_COMPARAISON_FORME_ONDE_OK",
		"BLUETOOTH_COMPARAISON_FORME_ONDE_NOK",

		"ACCELEROMETRE_PING_I2C_OK", //30
		"ACCELEROMETRE_PING_I2C_NOK",
		"ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_OK",
		"ACCELEROMETRE_LECTURE_VALEUR_FABRICANT_NOK",
		"ACCELEROMETRE_CALIBRATION_OK",
		"ACCELEROMETRE_CALIBRATION_NOK",
		"ACCELEROMETRE_TEST_INTERRUPTION_OK",
		"ACCELEROMETRE_TEST_INTERRUPTION_NOK",


		"LED_RGB_R_OK",//38
		"LED_RGB_R_NOK",
		"LED_RGB_G_OK",
		"LED_RGB_G_NOK",
		"LED_RGB_B_OK",
		"LED_RGB_B_NOK",

		"LUXMETRE_PING_I2C_OK",//44
		"LUXMETRE_PING_I2C_NOK",
		"LUXMETRE_CALIBRATION_OK",
		"LUXMETRE_CALIBRATION_NOK",
		"LUXMETRE_LECTURE_VALEUR_SOURCE_OK",
		"LUXMETRE_LECTURE_VALEUR_SOURCE_NOK",

		"CONSOMMATION_MESURE_SOUS_5V_OK",//50
		"CONSOMMATION_MESURE_SOUS_5V_NOK",

		"ALIM_SECOURS_30V_OK",//52
		"ALIM_SECOURS_30V_NOK",
		"ALIM_SECOURS_MESURE_HAUSSE_ALIM_OK",
		"ALIM_SECOURS_MESURE_HAUSSE_ALIM_NOK"

};*/



typedef unsigned short int uint;



#endif /* GLOBAL_H_ */
