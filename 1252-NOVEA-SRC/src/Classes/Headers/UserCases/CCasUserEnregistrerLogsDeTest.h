/*
 * CCasUserEnregistrerLogsDeTest.h
 *
 *  Created on: 25 juil. 2022
 *      Author: hme
 */

#ifndef CCASUSERENREGISTRERLOGSDETEST_H_
#define CCASUSERENREGISTRERLOGSDETEST_H_

//#include <iostream>
#include <string>

using namespace std;


class CFichierCSV;

class CCasUserEnregistrerLogsDeTest {
private :

	CFichierCSV *m_CFichierCSV;


public:
	CCasUserEnregistrerLogsDeTest();
	virtual ~CCasUserEnregistrerLogsDeTest();
	void construireFichierCSV();
	void mettreAJourFichierCSV(string ArgResTest);
	void fermerFichierCSV();


	CFichierCSV * getm_CFichierCSV(){return m_CFichierCSV;}

};

#endif /* CCASUSERENREGISTRERLOGSDETEST_H_ */
