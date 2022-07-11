/**
 * @file          CScreen.h
 * @version       1.0
 * @date          Created on: 23 juin 2022
 * @author        H. MEGHOUACHE
 * @brief         Copyright Emkaelectronique
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
 *        (#) IDE          : Eclipse Papyrus - Decembre 2022 - Plugin CDT 
 *
 * ===================================================================
 *                 ##### Historique des modifications #####
 * ===================================================================
 * 
 *        (#) Version   | Date           | Auteur              | Nature de la modification
 *            1.00        23 juin 2022         H. MEGHOUACHE         Creation
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
#ifndef HEADERS_UTIL_CSCREEN_H_
#define HEADERS_UTIL_CSCREEN_H_

#include <iostream>
#include <string>

using namespace std;


class CScreen
{
private:

	int m_a;
	int m_b;

public:


	CScreen();
	virtual ~CScreen();

	friend 	ostream& operator<<(ostream& os,/*const*/CScreen& dt){

		dt.write(os, dt);

		return os;

	}

	int get_ma(){return this->m_a;}
	int get_mb(){return this->m_b;}




private:

	 virtual  bool write(ostream& os,/*const*/ CScreen& dt)=0;

};



#endif /* HEADERS_UTIL_CSCREEN_H_ */
