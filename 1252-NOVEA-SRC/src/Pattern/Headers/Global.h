/**
 * @file          Global.h
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
#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <map>
#include <string>
#include "Util/CScreen.h"


//CStdString fluxDeSortie/*=new CStdString*/ ;


//TEST_GRAPHE : On v�rifie que l"on passe dans tous les ETATS
//DEBUG_PC : On entre dans chaque �tat pour v�rifier les actions r�alis�es

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


typedef unsigned short int uint;

string LcdToPrint[57]={

		"",//0
		"",//1
		"T1 CARTE OK",//2
		"T1 CARTE NOK",
		"T2 QR CODE OK",
		"T2 QR CODE NOK",
		"T3 ALIM 5V OK",
		"T3 ALIM 5V NOK",

		"T4 CAN OK",//8
		"T4 CAN NOK",
		"T5 NUM SERIE OK",
		"T5 NUM SERIE NOK",
		"T6 RELECTURE OK",
		"T6 RELECTURE NOK",
		"T7 UUI OK",
		"T7 UUI NOK",
		"T8 MEM FLASH OK",
		"T8 MEM FLASH NOK",

		"T9 EMET LORA OK",//18
		"T9 EMET LORA NOK",
		"T10 P LORA OK",
		"T10 P LORA NOK",
		"T11 OND LORA OK",
		"T11 OND LORA NOK",

		"T12 BLUE OK", //24
		"T12 BLUE NOK",
		"T13 P BLUE OK",
		"T13 P BLUE NOK",
		"T14 OND BLUE OK",
		"T14 OND BLUE NOK",

		"T15 ACCE OK", //30
		"T15 ACCE OK",
		"T16 ACCE FAB OK",
		"T16 ACCE FAB NOK",
		//"T17 ACCE FAB OK",
		//"T17 ACCE FAB NOK",
		"T17 ACCE INT OK",
		"T17 ACCE INT NOK",


		"T18 LED R OK",//38
		"T18 LED R NOK",
		"T19 LED G OK",
		"T19 LED G NOK",
		"T20 LED B OK",
		"T20 LED B NOK",

		"T21 LUX OK",//44
		"T21 LUX NOK",
		"T22 CAL OK",
		"T22 CAL NOK",
		//"T23 CAL OK",
		//"T23 CAL NOK",

		"T23 CONS 5V OK",//50
		"T23 CONS 5V NOK",

		"T24 SEC 30V OK",//52
		"T24 SEC 30V NOK",
		"T25 HAUSSE OK",
		"T25 HAUSSE NOK"

};


#endif /* GLOBAL_H_ */
