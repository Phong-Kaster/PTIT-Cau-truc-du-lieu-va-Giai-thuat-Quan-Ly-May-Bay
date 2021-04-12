#pragma once
#include"UserInterfaceTP.h"
#include"AirplaneTP.h"
#include<fstream>
#include"FlightTP.h"
#include"PassengerTP.h"
/*Gioi thieu*/
void Introduction();
void ThankYouAndGoodBye();
/*Xu li may bay*/
void ReadOneAirplane(Airplane &A,ifstream &filein);
void ReadAirplaneFile(ListAirplane &LA);
void WriteAirplaneToFile(ListAirplane &LA);
/*Xu li chuyen bay*/
void ReadFlightFileFromFile(FlightList &FL,ListAirplane &LA);
void SaveTicketListOfOneFlight(Flight &F);
void SaveFlight( Flight &F,ofstream &fileout);
void WriteFlightToFile(FlightList &FL);
/*Xu li hanh khach*/
void ReadPassengerFromFile(AVLTree &root);
void SaveOnePassenger( AVLTree &root,ofstream &fileout);
void SavePassengerList( AVLTree &root,ofstream &fileout);
void SavePassengerToFile(AVLTree &root);