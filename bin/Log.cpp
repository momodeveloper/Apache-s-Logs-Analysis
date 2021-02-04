/*************************************************************************
                            Log  -  description
                             -------------------
    début                : 14/01/2021
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <string>
//------------------------------------------------------ Include personnel
#include "Log.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Log::GetRefer() const
// Algorithme :
//
{
   return refer;
}

string Log::GetCible() const
// Algorithme :
//
{
   return cible;
}


string Log::GetDate() const
// Algorithme :
//
{
   return date;
}

Log :: Log( string Ip, string Nom,string user,string Date , string Cible, string Status, string donnee, string Refer, string Navigateur)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Log>" << endl;
  #endif
  ip = Ip;
  userLogName = Nom ;
  authentificatedUser = user ;
  date = Date;
  cible = Cible;
  status = Status ;
  quantiteDonnee = donnee ;
  refer = Refer;
  navigateur= Navigateur;
}

Log :: ~Log()
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <Log>" << endl;
  #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
