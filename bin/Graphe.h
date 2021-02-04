/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 01/02/2021
    copyright            : (C) 2021 par Mohammed et Amine
*************************************************************************/

//---------- Interface de la classe <Graphe>  ------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H
#include <string>
#include <map>
#include <set>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Graphe>
//
//
//------------------------------------------------------------------------ 

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterLog(string cible, string refrer);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void GenererGraphe( string nomDuFichierDot);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void CalculerTopDix();
    // Mode d'emploi :
    //
    // Contrat :
    //
    set<string> DeterminerNoeuds();
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AfficherGraphe();
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AfficherTopDix();
    // Mode d'emploi :
    //
    // Contrat :
    //
//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



protected:
//----------------------------------------------------- Attributs protégés

    map <string, map<string,int>> graphe;

    multimap<int,string> topDix;

};

//----------------------------------------- Types dépendants de <Graphe>

#endif // GRAPHE_H