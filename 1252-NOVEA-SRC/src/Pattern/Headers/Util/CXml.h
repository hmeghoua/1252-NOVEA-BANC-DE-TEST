/**
 * @file          CXml.h
 * @version       1.0
 * @date          Created on: 28 juin 2022
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
 *            1.00        28 juin 2022         H. MEGHOUACHE         Creation
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
#ifndef CLASSES_HEADERS_UTIL_CXML_H_
#define CLASSES_HEADERS_UTIL_CXML_H_

#include "./tinyxml/tinyxml.h"
#include <iostream>
using namespace std;





class CXml {
public:
	CXml();
	virtual ~CXml();

 /*  int lireFichier(){

	  TiXmlDocument doc("D:\\r.xml");


	   Parcourir( doc.RootElement() );

	    return 1;

   }

   void Parcourir( TiXmlNode* node, int level = 0 )
   {
       cout << string( level*3, ' ' ) << "[" << node->Value() << "]";
       if ( node->ToElement() )
       {
           TiXmlElement* elem = node->ToElement();
           for ( const TiXmlAttribute* attr = elem->FirstAttribute(); attr; attr = attr->Next() )
               cout << " (" << attr->Name() << "=" << attr->Value() << ")";
       }
       cout << "\n";



       for( TiXmlNode* elem = node->FirstChild(); elem; elem = elem->NextSibling() )
           Parcourir( elem, level + 1 );
   }*/









};

#endif /* CLASSES_HEADERS_UTIL_CXML_H_ */
