/*************************************************************************
                            Flux  -  description
                             -------------------
    début                : 14/01/2021
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Flux> (fichier Flux.h) ----------------
#if ! defined ( FLUX_H )
#define FLUX_H
#include <iostream>
using namespace std;
#include <string>
#include "Log.h"
#include <fstream>
// Rôle de la classe <FLUX>
//
//
//------------------------------------------------------------------------

class Flux
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
    bool Eof();
    // Mode d'emploi  :
    // Contrat : Aucun
    //

    bool Good();
    // Algorithme :
    //

    Log * LireProchainLog();
    // Mode d'emploi  :
    // Contrat : Aucun
    //

    Flux( string NomFichier,string urlBase = "intranet-if.insa-lyon.fr");
    // Mode d'emploi :
    // Contrat :Aucun
    //


    virtual ~Flux ( );
    // Mode d'emploi :
    // Contrat :Aucun
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string nomFichier;
    ifstream canal;
    string urlBase;
};

#endif // FLUX_H
