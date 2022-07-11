/**
 * @file          CStdString.h
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
#ifndef HEADERS_UTIL_CSTDSTRING_H_
#define HEADERS_UTIL_CSTDSTRING_H_

#include "CScreen.h"


using namespace std;

class CStdString: public CScreen {
public:
	CStdString();
	virtual ~CStdString();

private:

	bool write(ostream& os,/*const*/ CScreen& dt){

		//argflux::cout<<argValueToPrint;
		os<<dt.get_ma()<<endl;

		//os.write(__s, __n);


		return true;


	}
};

#endif /* HEADERS_UTIL_CSTDSTRING_H_ */
