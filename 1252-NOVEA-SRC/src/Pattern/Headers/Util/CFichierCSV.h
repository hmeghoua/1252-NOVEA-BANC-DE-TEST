/*
 * CFichierCSV.h
 *
 *  Created on: 25 juil. 2022
 *      Author: hme
 */

#ifndef CFICHIERCSV_H_
#define CFICHIERCSV_H_

#include <iostream>
#include <fstream>
#include "CFichierCSV.h"

using namespace std;


class CFichierCSV {

private:

	fstream m_fichier;
	string m_nomFichier;


public:
	CFichierCSV();
	short int creerFichier(string ArgNomFichier);
	short int ecrireNomColonne(string ArgValAEcrire);
	short int mettreAJour(/*short int ArgNumTest, short int ArgColonne,*/string ArgResTest);
	void fermerFichier(){ m_fichier.close();}
	void openFichier(){m_fichier.open(m_nomFichier/*, ios::in*/);}
	void ligneSuivante(){m_fichier<<endl;}
	virtual ~CFichierCSV();
};

#endif /* CFICHIERCSV_H_ */
