/*************************************************************************
                            Log  -  description
                             -------------------
    début                : 14/01/2021
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ----------------
#if ! defined ( LOG_H )
#define LOG_H
#include <iostream>
using namespace std;
#include <string>

// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publique
 
//-------------------------------------------- Constructeurs - destructeur
    string GetCible() const;
    // Mode d'emploi  :
    // Contrat : Aucun
    //


    string GetDate() const;
    // Mode d'emploi  :
    // Contrat : Aucun
    //

    string GetRefer() const;
    // Mode d'emploi  :
    // Contrat : Aucun
    //

    Log( string Ip, string Nom, string user, string Date, string Cible, string Status, string donnee, string Refer, string Navigateur);
    // Mode d'emploi  :
    // Contrat : Aucun
    //


    virtual ~Log ( );
    // Mode d'emploi :
    // Contrat :Aucun
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
  string ip;
  string userLogName;
  string authentificatedUser;
  string date;
  string cible;
  string status;
  string quantiteDonnee;
  string refer;
  string navigateur;
};

#endif // LOG_H
