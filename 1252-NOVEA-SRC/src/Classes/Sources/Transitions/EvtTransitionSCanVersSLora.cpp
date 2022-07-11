/**
 * @file          EvtTransitionSCanVersSLora.cpp
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
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
 *            1.00        20 juin 2022         H. MEGHOUACHE         Creation
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
#include "../../Headers/Transitions/EvtTransitionSCanVersSLora.h"
#include "../../Headers/Actions/CActionMiseEnPlaceCarte.h"


#include "../../Headers/Global.h"
#include "../../Pattern/Headers/Transition.h"
#include "../../Pattern/Headers/Graph.h"
#include "../../Headers/Actions/CActionCan.h"



EvtTransitionSCanVersSLora::EvtTransitionSCanVersSLora() {

	// TODO Auto-generated constructor stub
	//Echecs de la postcondition de transition par d�faut

}

/**
  * @brief  Condition de garde entre les �tats SCan et SLora
  * @brief  Pr�conditions : DETECTION_PRESENCE_CARTE_OK :  L'alimentation de la carte en 5 volts est OK
  *                         FLASH_QR_CODE_OK            :  Le QR Code est OK
  *                         ALIMENTATION_5V_OK          :  L'alimentation de la carte est OK
  * @brief  Postconditions: PING_CAN_NOK;
  *							ECRITURE_NUM_SERIE_NOK;
  *							RELECTURE_NUM_SERIE_NOK;
  *							LECTURE_UUI_NOK;
  *							PING_MEM_FLASH_NOK;
  *
  * @brief  Invariants    : Pr�sence de la carte
  * @param  entr�e        : aucun
  * @param  sortie        : aucun
  * @param  entr�e/sortie : argAction : contient les m�thodes m�tiers qui g�rent la transition
  * @retval     1                                    :  La condition de garde s'est bien pass�e
  *          100			                         :  La pr�condition a �chou� (l'�tat pr�c�dent a �chou�)
  *			 PING_CAN_NOK                            :  Echec du ping de la carte
  *          ECRITURE_NUM_SERIE_NOK                  :  Echec de l'�criture du num�ro de s�rie
  *          RELECTURE_NUM_SERIE_NOK                 :  Echec de la relecture du num�ro de s�rie
  *          LECTURE_UUI_NOK                         :  Echec de la lecture du UUID
  *          PING_MEM_FLASH_NOK                      :  Echec de la lecture de la m�moire flash
  */

const /*string*/uint EvtTransitionSCanVersSLora::onTransitionEvent(CAction*argAction,CAction*argActionBefore){

	uint retour=100;    	          //Contient le retour des appels la m�thode : �chec par d�faut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'�tat de l'action pr�c�dente associ�e � l'�tat "StateMiseEnPlaceCarte"
	CActionMiseEnPlaceCarte* oMiseEnPlaceCarte=(CActionMiseEnPlaceCarte*)argActionBefore;
	uint *tabResEtatPrecedent=oMiseEnPlaceCarte->getm_STATE();
	//for(int i=0;i<3;i++) { tabResEtatPrecedent[i]= oMiseEnPlaceCarte->getm_STATE(i);}


	//L'objet "oActionCan" pour r�aliser les actions pr�vues dans l'�tat SMisEnPlaceCarte
	CActionCan* oActionCan=(CActionCan*)argAction;

	//On teste alors la pr�condition : la condition de garde est-elle �tablie ?
	 if((*(tabResEtatPrecedent)==DETECTION_PRESENCE_CARTE_OK)&&(*(tabResEtatPrecedent+1)==FLASH_QR_CODE_OK)
			 &&(*(tabResEtatPrecedent+2)==ALIMENTATION_5V_OK))

	 {	 precondition=true; //Precondition �tablie

#ifdef DEBUG_PC
			cout<<"Je suis dans la transition de SCan vers SLora"<<endl;
#endif

			//On r�alise les actions associ�es � l'�tat "Scan"
			//Ping de la carte
			if(oActionCan->ping()==0){
				//Le ping a r�ussi et le retient
				oActionCan->setm_STATE(0, PING_CAN_OK);
				//Ecriture du num�ro de s�rie
				if(oActionCan->ecritureNumeroDeSerie()==0){
					//L'�criture du num�ro de s�rie  a r�ussi et le retient
					oActionCan->setm_STATE(1, ECRITURE_NUM_SERIE_OK);
					  //Relecture du num�ro de s�rie
				 	  if(oActionCan->relectureNumeroDeSerie()==0){
				 		 //La relecture du num�ro de s�rie  a r�ussi et le retient
				 		 oActionCan->setm_STATE(2, RELECTURE_NUM_SERIE_OK);
				 		  //Lecture de l'UUID de la carte
				 		  if(oActionCan->lectureIdentifiant()==0){
				 			 //La Lecture de l'UUID de la carte a r�ussi et le retient
				 			 oActionCan->setm_STATE(3, LECTURE_UUI_OK);
				 			 	//Ping de la m�moire Flash
				 			    if(oActionCan->pingMemoireFlash()==0){
				 			    	 //Le Ping de la m�moire Flash a r�ussi et le retient
				 			    	oActionCan->setm_STATE(4, PING_MEM_FLASH_OK);
				 			    	  //On p�pare la valeur de retour car toutes les actions associ�es � l'�tat
				 			    	  //SCan ont r�ussi
				 			    	// retour="allActionsOK";
							}else{
								//Le Ping de la m�moire Flash a �chou�
								oActionCan->setm_STATE(4, PING_MEM_FLASH_NOK);
								retour=PING_MEM_FLASH_NOK;
							}
						}else{
							//La Lecture de l'UUID a �chou�
							 oActionCan->setm_STATE(3, LECTURE_UUI_NOK);
							retour=LECTURE_UUI_NOK;
						}
					}else{
						//La relecture du num�ro de s�rie  a �chou�
						oActionCan->setm_STATE(2, RELECTURE_NUM_SERIE_NOK);
						retour=RELECTURE_NUM_SERIE_NOK;
					}
				}else{
					//L'�criture du num�ro de s�rie a �chou�
					oActionCan->setm_STATE(1, ECRITURE_NUM_SERIE_NOK);
					retour=ECRITURE_NUM_SERIE_NOK;
				}
			}else{
				//Le ping de la carte a �chou�
				oActionCan->setm_STATE(0, PING_CAN_NOK);

				retour=PING_CAN_NOK;
			}

	 }

	 //On construit le retour de la m�thode
	 //La pr�condition est OK et la derni�re action
	 // a r�ussi
	 if((precondition)&&(*((oActionCan->getm_STATE())+4)==PING_MEM_FLASH_OK)){

#ifdef DEBUG_PC
			cout<<"Transition de transition de SCan vers SLora r�ussie"<<endl;
			cout<<"****************************************************************"<<endl;
			cout<<endl;
#endif
		 retour=1;

	 }else{

		 //La derni�re action a �chou�
		 if(precondition==true)
		 {
			 retour=PING_MEM_FLASH_NOK;
		 }
	 }

	return retour;
}










EvtTransitionSCanVersSLora::~EvtTransitionSCanVersSLora() {
	// TODO Auto-generated destructor stub
}



















