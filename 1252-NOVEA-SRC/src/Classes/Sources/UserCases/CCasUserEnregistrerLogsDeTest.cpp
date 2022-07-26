/*
 * CCasUserEnregistrerLogsDeTest.cpp
 *
 *  Created on: 25 juil. 2022
 *      Author: hme
 */

#include "../../Headers/UserCases/CCasUserEnregistrerLogsDeTest.h"
#include "../../../Pattern/Headers/Util/CFichierCSV.h"
#include "../../Headers/Global.h"
#include <ctime>
#include <time.h>
#include <string>



CCasUserEnregistrerLogsDeTest::CCasUserEnregistrerLogsDeTest() {
	// TODO Auto-generated constructor stub

	 // date / heure actuelle basée sur le système actuel
	   string s;
	   time_t actuel = time(0);
	   tm *ltm = localtime(&actuel);
	    s=to_string(1 + ltm->tm_hour);
	   s+="-";
	   s+=to_string( 1 + ltm->tm_mon);
	   s+="-";
	   s+=to_string(1900+ltm->tm_year);
	   s+="-";
	   s+=NOM_FICHIER_CSV;

	m_CFichierCSV=new CFichierCSV();
	m_CFichierCSV->creerFichier(/*NOM_FICHIER_CSV*/s);
	m_CFichierCSV->fermerFichier();


}

void CCasUserEnregistrerLogsDeTest::mettreAJourFichierCSV(string ArgResTest){


	m_CFichierCSV->ecrireNomColonne(ArgResTest);

}



void CCasUserEnregistrerLogsDeTest::construireFichierCSV(){

	m_CFichierCSV->openFichier();
	//m_CFichierCSV->ecrireNomColonne(";");
	m_CFichierCSV->ecrireNomColonne("T1 : PRESENCE CARTE;");
	m_CFichierCSV->ecrireNomColonne("T2 : FLASH QR CODE;");
	m_CFichierCSV->ecrireNomColonne("T3 : ALIMENTATION 5V;");
	m_CFichierCSV->ecrireNomColonne("T4 PING CAN;");
	m_CFichierCSV->ecrireNomColonne("T5 ECRITURE NUM SERIE;");
	m_CFichierCSV->ecrireNomColonne("T6 RELECTURE NUM SERIE;");
	m_CFichierCSV->ecrireNomColonne("T7 UUI;");
	m_CFichierCSV->ecrireNomColonne("T8 MEM FLASH;");
	m_CFichierCSV->ecrireNomColonne("T9 EMET LORA;");
	m_CFichierCSV->ecrireNomColonne("T10 P LORA;");
	m_CFichierCSV->ecrireNomColonne("T11 ONDE LORA;");
	m_CFichierCSV->ecrireNomColonne("T12 EM BLUETOOTH;");
	m_CFichierCSV->ecrireNomColonne("T13 P BLUETOOTH;");
	m_CFichierCSV->ecrireNomColonne("T14 ONDE BLUETOOTH OK;");
	m_CFichierCSV->ecrireNomColonne("T15 ACCELEROMETRE;");
	m_CFichierCSV->ecrireNomColonne("T16 ACCELEROMETRE FABRICANT;");



	m_CFichierCSV->ecrireNomColonne("T17 ACCELEROMETRE INT;");
	m_CFichierCSV->ecrireNomColonne("T18 LED R;");
	m_CFichierCSV->ecrireNomColonne("T19 LED G;");
	m_CFichierCSV->ecrireNomColonne("T20 LED B;");
	m_CFichierCSV->ecrireNomColonne("T21 LUXMETRE;");
	m_CFichierCSV->ecrireNomColonne("T22 CALIBRATION;");
	m_CFichierCSV->ecrireNomColonne("T23 CONSOMMATION 5V;");
	m_CFichierCSV->ecrireNomColonne("T24 SEC 30V;");
	m_CFichierCSV->ecrireNomColonne("T25 HAUSSE TENSION;");
	m_CFichierCSV->ligneSuivante();


}
void CCasUserEnregistrerLogsDeTest::fermerFichierCSV(){

	m_CFichierCSV->fermerFichier();

}


CCasUserEnregistrerLogsDeTest::~CCasUserEnregistrerLogsDeTest() {
	// TODO Auto-generated destructor stub

	delete m_CFichierCSV;
}

