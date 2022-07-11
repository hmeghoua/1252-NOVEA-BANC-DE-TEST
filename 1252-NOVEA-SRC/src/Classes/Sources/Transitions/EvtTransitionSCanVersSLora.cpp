/**
 * @file          EvtTransitionSCanVersSLora.cpp
 * @version       1.0
 * @date          Created on: 20 juin 2022
 * @author        H. MEGHOUACHE
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
	//Echecs de la postcondition de transition par défaut

}

/**
  * @brief  Condition de garde entre les états SCan et SLora
  * @brief  Préconditions : DETECTION_PRESENCE_CARTE_OK :  L'alimentation de la carte en 5 volts est OK
  *                         FLASH_QR_CODE_OK            :  Le QR Code est OK
  *                         ALIMENTATION_5V_OK          :  L'alimentation de la carte est OK
  * @brief  Postconditions: PING_CAN_NOK;
  *							ECRITURE_NUM_SERIE_NOK;
  *							RELECTURE_NUM_SERIE_NOK;
  *							LECTURE_UUI_NOK;
  *							PING_MEM_FLASH_NOK;
  *
  * @brief  Invariants    : Présence de la carte
  * @param  entrée        : aucun
  * @param  sortie        : aucun
  * @param  entrée/sortie : argAction : contient les méthodes métiers qui gèrent la transition
  * @retval     1                                    :  La condition de garde s'est bien passée
  *          100			                         :  La précondition a échoué (l'état précédent a échoué)
  *			 PING_CAN_NOK                            :  Echec du ping de la carte
  *          ECRITURE_NUM_SERIE_NOK                  :  Echec de l'écriture du numéro de série
  *          RELECTURE_NUM_SERIE_NOK                 :  Echec de la relecture du numéro de série
  *          LECTURE_UUI_NOK                         :  Echec de la lecture du UUID
  *          PING_MEM_FLASH_NOK                      :  Echec de la lecture de la mémoire flash
  */

const /*string*/uint EvtTransitionSCanVersSLora::onTransitionEvent(CAction*argAction,CAction*argActionBefore){

	uint retour=100;    	          //Contient le retour des appels la méthode : échec par défaut
	bool precondition=false;     //Echec de la precondition par defaut

	//Condition de garde : on lit l'état de l'action précédente associée à l'état "StateMiseEnPlaceCarte"
	CActionMiseEnPlaceCarte* oMiseEnPlaceCarte=(CActionMiseEnPlaceCarte*)argActionBefore;
	uint *tabResEtatPrecedent=oMiseEnPlaceCarte->getm_STATE();
	//for(int i=0;i<3;i++) { tabResEtatPrecedent[i]= oMiseEnPlaceCarte->getm_STATE(i);}


	//L'objet "oActionCan" pour réaliser les actions prévues dans l'état SMisEnPlaceCarte
	CActionCan* oActionCan=(CActionCan*)argAction;

	//On teste alors la précondition : la condition de garde est-elle établie ?
	 if((*(tabResEtatPrecedent)==DETECTION_PRESENCE_CARTE_OK)&&(*(tabResEtatPrecedent+1)==FLASH_QR_CODE_OK)
			 &&(*(tabResEtatPrecedent+2)==ALIMENTATION_5V_OK))

	 {	 precondition=true; //Precondition établie

#ifdef DEBUG_PC
			cout<<"Je suis dans la transition de SCan vers SLora"<<endl;
#endif

			//On réalise les actions associées à l'état "Scan"
			//Ping de la carte
			if(oActionCan->ping()==0){
				//Le ping a réussi et le retient
				oActionCan->setm_STATE(0, PING_CAN_OK);
				//Ecriture du numéro de série
				if(oActionCan->ecritureNumeroDeSerie()==0){
					//L'écriture du numéro de série  a réussi et le retient
					oActionCan->setm_STATE(1, ECRITURE_NUM_SERIE_OK);
					  //Relecture du numéro de série
				 	  if(oActionCan->relectureNumeroDeSerie()==0){
				 		 //La relecture du numéro de série  a réussi et le retient
				 		 oActionCan->setm_STATE(2, RELECTURE_NUM_SERIE_OK);
				 		  //Lecture de l'UUID de la carte
				 		  if(oActionCan->lectureIdentifiant()==0){
				 			 //La Lecture de l'UUID de la carte a réussi et le retient
				 			 oActionCan->setm_STATE(3, LECTURE_UUI_OK);
				 			 	//Ping de la mémoire Flash
				 			    if(oActionCan->pingMemoireFlash()==0){
				 			    	 //Le Ping de la mémoire Flash a réussi et le retient
				 			    	oActionCan->setm_STATE(4, PING_MEM_FLASH_OK);
				 			    	  //On pépare la valeur de retour car toutes les actions associées à l'état
				 			    	  //SCan ont réussi
				 			    	// retour="allActionsOK";
							}else{
								//Le Ping de la mémoire Flash a échoué
								oActionCan->setm_STATE(4, PING_MEM_FLASH_NOK);
								retour=PING_MEM_FLASH_NOK;
							}
						}else{
							//La Lecture de l'UUID a échoué
							 oActionCan->setm_STATE(3, LECTURE_UUI_NOK);
							retour=LECTURE_UUI_NOK;
						}
					}else{
						//La relecture du numéro de série  a échoué
						oActionCan->setm_STATE(2, RELECTURE_NUM_SERIE_NOK);
						retour=RELECTURE_NUM_SERIE_NOK;
					}
				}else{
					//L'écriture du numéro de série a échoué
					oActionCan->setm_STATE(1, ECRITURE_NUM_SERIE_NOK);
					retour=ECRITURE_NUM_SERIE_NOK;
				}
			}else{
				//Le ping de la carte a échoué
				oActionCan->setm_STATE(0, PING_CAN_NOK);

				retour=PING_CAN_NOK;
			}

	 }

	 //On construit le retour de la méthode
	 //La précondition est OK et la dernière action
	 // a réussi
	 if((precondition)&&(*((oActionCan->getm_STATE())+4)==PING_MEM_FLASH_OK)){

#ifdef DEBUG_PC
			cout<<"Transition de transition de SCan vers SLora réussie"<<endl;
			cout<<"****************************************************************"<<endl;
			cout<<endl;
#endif
		 retour=1;

	 }else{

		 //La dernière action a échoué
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



















