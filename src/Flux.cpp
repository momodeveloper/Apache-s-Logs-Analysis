/*************************************************************************
                            Flux  -  description
                             -------------------
    début                : 14/01/2021
    copyright            : (C) 2020 par Sabil Mohamed Amine et Mohammed Nassik
    e-mail               : mohamed.sabil@insa-lyon.fr
                           mohammed.nassik@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Flux> (fichier Flux.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <fstream>
#include <cstring>
#include <string>
//------------------------------------------------------ Include personnel
#include "Flux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Flux :: Eof()
// Algorithme :
//
{
   return canal.peek()==EOF ;
}


bool Flux :: Good()
// Algorithme :
//
{
   return canal.good();
}

Log* Flux :: LireProchainLog(){
// Algorithme :
//
       string Ip,Nom,user,Date,Cible,Status,donnee,Refer,Navigateur,unwanted;
       char c;
       getline(canal,Ip,' ');
       getline(canal,Nom,' ');
       getline(canal,user,' ');
       canal.get(c);
       getline(canal,Date,']');
       canal.get(c);
       getline(canal,unwanted,' ');
       getline(canal,Cible,' ');
       getline(canal,unwanted,' ');
       getline(canal,Status,' ');
       getline(canal,donnee,' ');
       canal.get(c);
       getline(canal,Refer,'/');
       canal.get(c);
       getline(canal,Refer,'/');
       if (Refer == urlBase){
            getline(canal,unwanted,'"');
            Refer = "/" + unwanted;
       }
       else{
          getline(canal,unwanted,'"');
          Refer = "http://" + Refer+ "/" +unwanted;
       }
       canal.get(c); canal.get(c);
       getline(canal,Navigateur,'"');
       canal.get(c);
       Log * leLog= new Log(Ip,Nom,user,Date,Cible,Status,donnee,Refer,Navigateur);
       return leLog;
}


Flux :: Flux(string NomFichier,string UrlBase) :
   nomFichier(NomFichier), canal(nomFichier.c_str()), urlBase(UrlBase)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Flux>" << endl;
  #endif
}

Flux :: ~Flux ()
// Algorithme
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <Flux>" << endl;
  #endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
