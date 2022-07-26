/*
 * CFichierCSV.cpp
 *
 *  Created on: 25 juil. 2022
 *      Author: hme
 */

#include "../../Headers/Util/CFichierCSV.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

CFichierCSV::CFichierCSV() {
	// TODO Auto-generated constructor stub



}

short int CFichierCSV::creerFichier(string ArgNomFichier){

	m_fichier.open(ArgNomFichier, ios::out | ios::app);
	this->m_nomFichier=ArgNomFichier;


}

short int CFichierCSV::ecrireNomColonne(string ArgValAEcrire){

	m_fichier << ArgValAEcrire /*<< ", "<< "\n"*/;


}

short int CFichierCSV::mettreAJour(/*short int ArgNumTest,short int ArgColonne,*/string ArgResTest){


	//m_fichier << endl;
	m_fichier <<ArgResTest;



}

CFichierCSV::~CFichierCSV() {
	// TODO Auto-generated destructor stub

	m_fichier.close();
}

