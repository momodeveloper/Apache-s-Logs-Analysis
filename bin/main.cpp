#include "Log.h"
#include "Flux.h"
#include "Graphe.h"
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

bool estUnFichierLog(char * nomFichier);

bool estUnFichierDot(char * nomFichier);

bool estUneOptionValide(char * option_1 , char * complementOption);

bool optionsValides(int arg , char * options[]);

bool respecte_E(Log * unLog);

bool respecte_T(Log * unLog , int heure);

int main(int arg , char* argv[]){
    if(arg<2){// le cas où l'utilisateur ne fournit pas de fichier log
      cerr<<"il manque le fichier log."<<endl;
    }


    else if(arg==2){ // le cas où l'utilisateur ne rentre pas d'options
      if(!estUnFichierLog(argv[arg-1])){
        cerr<<" le fichier fourni n'est pas un fichier log."<<endl;
      }else{
        Flux leFlux(argv[arg-1],"intranet-if.insa-lyon.fr");
        Graphe * leGraphe=new Graphe();
        while (leFlux.Eof()==false ){
          Log * unLog = leFlux.LireProchainLog();
          leGraphe->AjouterLog(unLog->GetCible(),unLog->GetRefer());
          delete unLog;
        }
        leGraphe->AfficherTopDix();
        delete leGraphe;
      }
    }


    else if(arg>2){  //le cas où l'utilisateur rentre des options
      if(!estUnFichierLog(argv[arg-1])){
        cerr<<" le fichier fourni n'est pas un fichier .log ."<<endl;
      }else{
        // il faut d'abord s'assurer que les options rentés sont valides
        if(!optionsValides(arg , argv)){
          cerr<< "une ou plusieurs des options que vous avez saisies est/sont non valide/s"<<endl;
        }else{
          bool optionG=false, optionT=false, optionE=false;
          int heure;
          string nomFichierDot;
          for(int i=1;i<arg-1;++i){
            if( strcmp(argv[i],"-t") == 0){
                optionT=true;
                heure= atoi(argv[i+1]);
            }
            if( strcmp(argv[i],"-e") == 0){
                optionE=true;
            }
            if( strcmp(argv[i],"-g") == 0){
                optionG=true;
                nomFichierDot = argv[i+1];
            }
          }
          Flux leFlux(argv[arg-1],"intranet-if.insa-lyon.fr");
          Graphe * leGraphe=new Graphe();
          while (leFlux.Eof()==false ){
            Log * unLog = leFlux.LireProchainLog();
            if (optionE && optionT){
                if  ( !respecte_E(unLog) || !respecte_T(unLog,heure) )
                      continue;
            }
            else if (optionE){
                if  ( !respecte_E(unLog) )
                     continue;
                
            }
            else if (optionT){
                if (! respecte_T(unLog,heure))
                     continue;
            }
            leGraphe->AjouterLog(unLog->GetCible(),unLog->GetRefer());
            delete unLog;
          }
          if (optionG)
              leGraphe->GenererGraphe( nomFichierDot);
          leGraphe->AfficherTopDix();
          delete leGraphe;
        }
      }
    }
    return 0;
}

bool respecte_T(Log * unLog , int heure)
{
  char * uneDateEntiere=new char[(unLog->GetDate()).length()+1];
  strcpy(uneDateEntiere,(unLog->GetDate()).c_str());
  char lHeure[2];
  int i=0;
  while(uneDateEntiere[i++]!=':'){
  }
  lHeure[0]=uneDateEntiere[i];
  lHeure[1]=uneDateEntiere[i+1];
  delete [] uneDateEntiere;
  if(heure==atoi(lHeure))
    return true;
  return false;

}

bool respecte_E(Log * unLog)
{
   char * refer = new char[(unLog->GetRefer()).length()+1];
   strcpy(refer,(unLog->GetRefer()).c_str());
   char * cible = new char[(unLog->GetCible()).length()+1];
   strcpy(cible,(unLog->GetCible()).c_str());
   int longueurRefer=strlen(refer);
   int longueurCible=strlen(cible);
   if ( (refer[longueurRefer-3]=='.') && (refer[longueurRefer-2]=='j') && (refer[longueurRefer-1]=='s') ){
         delete [] refer;
         delete [] cible;
         return false;
    
  }if ( (refer[longueurRefer-4]=='.') && (refer[longueurRefer-3]=='c') && (refer[longueurRefer-2]=='s') && (refer[longueurRefer-1]=='s') ){
         delete [] refer;
         delete [] cible;
         return false;
  }if ( (refer[longueurRefer-4]=='.') && (refer[longueurRefer-3]=='b') && (refer[longueurRefer-2]=='m') && (refer[longueurRefer-1]=='p') ){
         delete [] refer;
         delete [] cible;
         return false;
  }if ( (refer[longueurRefer-4]=='.') && (refer[longueurRefer-3]=='i') && (refer[longueurRefer-2]=='c') && (refer[longueurRefer-1]=='o') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (refer[longueurRefer-4]=='.') && (refer[longueurRefer-3]=='g') && (refer[longueurRefer-2]=='i') && (refer[longueurRefer-1]=='f') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (refer[longueurRefer-4]=='.') && (refer[longueurRefer-3]=='p') && (refer[longueurRefer-2]=='n') && (refer[longueurRefer-1]=='g') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (refer[longueurRefer-5]=='.') && (refer[longueurRefer-4]=='j') && (refer[longueurRefer-3]=='p') && (refer[longueurRefer-2]=='e') && (refer[longueurRefer-1]=='g')){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (refer[longueurRefer-4]=='.') && (cible[longueurRefer-3]=='j') && (cible[longueurRefer-2]=='p') && (cible[longueurRefer-1]=='g') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-3]=='.') && (cible[longueurCible-2]=='j') && (cible[longueurCible-1]=='s') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-4]=='.') && (cible[longueurCible-3]=='c') && (cible[longueurCible-2]=='s') && (cible[longueurCible-1]=='s') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-4]=='.') && (cible[longueurCible-3]=='b') && (cible[longueurCible-2]=='m') && (cible[longueurCible-1]=='p') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-4]=='.') && (cible[longueurCible-3]=='i') && (cible[longueurCible-2]=='c') && (cible[longueurCible-1]=='o') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-4]=='.') && (cible[longueurCible-3]=='g') && (cible[longueurCible-2]=='i') && (cible[longueurCible-1]=='f') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-4]=='.') && (cible[longueurCible-3]=='p') && (cible[longueurCible-2]=='n') && (cible[longueurCible-1]=='g') ){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-5]=='.') && (cible[longueurCible-4]=='j') && (cible[longueurCible-3]=='p') && (cible[longueurCible-2]=='e') && (cible[longueurCible-1]=='g')){
        delete [] refer;
        delete [] cible;
        return false;
  }if ( (cible[longueurCible-4]=='.') && (cible[longueurCible-3]=='j') && (cible[longueurCible-2]=='p') && (cible[longueurCible-1]=='g') ){
        delete [] refer;
        delete [] cible;
        return false;
  }
  delete [] refer;
  delete [] cible;
  return true;
}

bool estUnFichierLog(char * nomFichier)
{
  int longueur=strlen(nomFichier);
  if(nomFichier[longueur-4]!='.' || nomFichier[longueur-3]!='l' || nomFichier[longueur-2]!='o' || nomFichier[longueur-1]!='g'){
    return false;
  }
  return true;
}

bool estUnFichierDot(char * nomFichier)
{
  int longueur=strlen(nomFichier);
  if(nomFichier[longueur-4]!='.' || nomFichier[longueur-3]!='d' || nomFichier[longueur-2]!='o' || nomFichier[longueur-1]!='t'){
    return false;
  }
  return true;
}

bool estUneOptionValide(char * option_1 , char * complementOption)
{
    if(!strcmp(option_1,"-g")){
      if(estUnFichierDot(complementOption))
        return true;
    }else if(!strcmp(option_1,"-t")){
      if(strlen(complementOption)<=2 && isdigit(complementOption[0]) && isdigit(complementOption[1]))
        return true;
    }
    return false;
}

bool optionsValides(int arg , char * options[])
{
  int e=0,g=0,t=0;
  for(int i=1;i<arg-1;++i){
    if(!strcmp(options[i],"-e")){
      e++;
      if(e>1)
        return false;
    }else if(!strcmp(options[i],"-t")){
      if(estUneOptionValide(options[i],options[i+1])){
        i=i+1;
        t++;
        if(t>1)
          return false;
      }
      else 
        return false;
    }else if(!strcmp(options[i],"-g")){
      if(estUneOptionValide(options[i],options[i+1])){
        i=i+1;
        g++;
        if(g>1)
          return false;
      }
      else 
        return false;
    }else{
      return false;
    }
  }
  return true;
}
