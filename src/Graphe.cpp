/*************************************************************************
                            Graphe -  description
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
#include <string>
#include <map>
#include <set>
#include "Graphe.h"
//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
   void Graphe::AjouterLog(string cible,string refrer)
   //Algorithme:
   //
    {
        if(!graphe.count(cible)){
            map<string,int> interne;
            interne.insert(make_pair(refrer,1));
            graphe.insert( make_pair (cible,interne) );
        }else{
            map<string,map<string,int>>::iterator it;
            it=graphe.find(cible);
            if(!(it->second.count(refrer))){
                it->second.insert(pair<string,int>(refrer,1));
            }else{
                map <string,int>::iterator itInterne;
                itInterne=(it->second).find(refrer);
                (itInterne->second)++;
            }
        }
    }
    set<string> Graphe::DeterminerNoeuds()
    //Algorithme:
    //
   {
       map<string,map<string,int>>::iterator it;
       map<string,int>::iterator itInterne;
       set<string> ensembleDeNoeuds;
       for(it=graphe.begin();it!=graphe.end();++it){
           ensembleDeNoeuds.insert(it->first);
           for(itInterne=(it->second).begin();itInterne!=(it->second).end();++itInterne){
               ensembleDeNoeuds.insert(itInterne->first);
           }
       }
       return ensembleDeNoeuds;
   }
    void Graphe::GenererGraphe( string nomDuFichierDot)
    //Algorithme:
    //
   {
       ofstream out(nomDuFichierDot);
       out<<"digraph {"<<endl;
       set<string> ensembleDeNoeuds=DeterminerNoeuds();
       set<string>::iterator itNoeuds;
       for(itNoeuds=ensembleDeNoeuds.begin();itNoeuds!=ensembleDeNoeuds.end();++itNoeuds){
           out<<'"'<<(*itNoeuds)<<'"'<<";"<<endl;
       }

       map<string,map<string,int>>::iterator itCible;
       map<string,int>::iterator itRefrer;
       for(itCible=graphe.begin();itCible!=graphe.end();++itCible){
           for(itRefrer=(itCible->second).begin();itRefrer!=(itCible->second).end();++itRefrer){
               out<<'"'<<itRefrer->first<<'"'<<" -> "<<'"'<<itCible->first<<'"'<<" [label=\""<<itRefrer->second<<"\"];"<<endl;
           }
       }
       out<<"}";

       out.close();
   }

   void Graphe::CalculerTopDix()
   //Algorithme:
    //
   {
       map<string,map<string,int>>::iterator it;
       map<string,int>::iterator itInterne;
       multimap <int ,string> mTmp;
       for(it=graphe.begin();it!=graphe.end();++it){
           int nbOccurence=0;
           for(itInterne=(it->second).begin();itInterne!=(it->second).end();++itInterne){
               nbOccurence+=itInterne->second;
           }
            mTmp.insert(pair <int , string>(nbOccurence,it->first));
       }

       multimap <int ,string>::reverse_iterator itTopDix;
       int i=0;
       for(itTopDix=mTmp.rbegin(); itTopDix!=mTmp.rend() && i<10 ; ++itTopDix , ++i){
           topDix.insert(pair<int,string>(itTopDix->first,itTopDix->second));
       }
       
   }

    void Graphe::AfficherGraphe()
    //Algorithme:
    //
    {
        map<string,map<string,int>>::iterator it;
        map<string,int>::iterator itInterne;
        for(it=graphe.begin();it!=graphe.end();++it){
            cout<<"la cible est: "<<it->first<<endl;
            for(itInterne=(it->second).begin();itInterne!=(it->second).end();++itInterne){
                cout<<"\t"<<"un refrer est : "<<itInterne->first<< " avec "<<itInterne->second<<" occurences"<<endl;
            }
        }
    }
    void Graphe::AfficherTopDix()
    //Algorithme:
    //
    {
        CalculerTopDix();
        map<int,string>::reverse_iterator it;
        for(it=topDix.rbegin();it!=topDix.rend();++it){
            cout<<"\t" <<it->second<<" avec "<<it->first<< " occurences"<<endl;
        }
    }

    Graphe :: Graphe(const Graphe& unGraphe)
    //Algorithme:
    //
   {
       #ifdef MAP
            cout << "Appel au constructeur de copie de <Graphe>" << endl;
       #endif
       delete this;
   }

   Graphe :: Graphe( )
   // Algorithme :
   //
   {
       #ifdef MAP
            cout << "Appel au constructeur de <Graphe>" << endl;
       #endif
   }

   Graphe:: ~Graphe ()
   // Algorithme :
   //
   {
       #ifdef MAP
            cout << "Appel au destructeur de <Graphe>" << endl;
       #endif
   }


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
