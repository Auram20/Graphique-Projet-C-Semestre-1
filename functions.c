#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "graphique.h"


int initialiserMonde(Monde *monde){
    monde->tour = 0;
    initialiserPlateau(monde->plateau);
    (monde->rouge) = calloc(1, sizeof(*(monde->rouge)));
    if((monde->rouge) == NULL) {
      return 0;
    }
    (monde->rouge)->couleur = ROUGE;
    (monde->rouge)->unites = NULL;
    (monde->bleu) = calloc(1, sizeof(*(monde->bleu)));
    if((monde->bleu) == NULL) {
      return 0;
    }
    (monde->bleu)->couleur = BLEU;
    (monde->bleu)->unites = NULL;
    return 1;
}

/*Je suis obligé de mettre les tailles du tableau pour une raison que j'ignore*/
void initialiserPlateau(Unite *plateau[LONG][LARG]) {
  size_t i, j;
  for(i = 0; i < LONG; ++i) {
    for(j = 0; j < LARG; ++j) {
      plateau[i][j] = NULL;
    }
  }
}

Unite *creerUnite(char genre, UListe *uliste) {
  Unite *temp;
  temp = calloc(1, sizeof(*(uliste->unites)));
  if(temp != NULL) {
    temp->genre = genre;
    temp->couleur = uliste->couleur;
    temp->suiv = NULL;
    if(uliste->unites == NULL) {
      uliste->unites = temp;
    } else {
      temp->suiv = uliste->unites;
      uliste->unites = temp;
    }
  }

  return temp;

}
Unite *dernier(UListe uliste) {
  Unite *unite;
  unite = uliste.unites;
  while(unite != NULL && unite->suiv != NULL) {
    unite = (unite->suiv);
  }
  return unite;
}

int placerAuMonde(Unite *unite, Monde *monde, size_t posX, size_t posY) {
  if(unite == NULL || monde->plateau[posY][posX] != NULL || posY >= LONG || posX >= LARG) {
    return 0;
  } else {
    unite->posX = posX;
    unite->posY = posY;
    monde->plateau[posY][posX] = unite;
    return 1;
  }
}

void affichePlateau(Monde monde) {
  int i, j;
  afficheNumH(LARG);
  ligne();
  for(i = 0; i < LONG; ++i) {
    printf("|");
    for(j = 0; j < LARG; ++j) {
      if(monde.plateau[i][j] == NULL) {
        printf("    ");
      } else {
        char *symbol = getSymbol(monde.plateau[i][j]->genre);
        printf(" %s%c", symbol, monde.plateau[i][j]->couleur);
        free(symbol);
      }
      printf("|");
    }
    printf("  %d", i);
    printf("\n");
    ligne();
  }
}

void afficheNumH(int n) {
  int i;
  for(i = 0; i < n; ++i) {
    printf("  %2d ", i);
  }
  printf("\n");
}

/*À libérer avec free*/
char *getSymbol(char genre) {
  char *string;
  string = malloc(3 * sizeof(*string));
  switch(genre) {
    case(GUERRIER):
      strcpy(string, "()");
      break;
    case(SERF):
      strcpy(string, "00");
      break;
    default:
      strcpy(string, "xx");
      break;
  }
  return string;
}

void ligne() {
  int i;
  for(i = 0; i < LARG * 5 + 1; ++i) {
    printf("-");
  }
  printf("\n");

}

void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){
    if(monde->plateau[destY][destX] == NULL && destX <= LONG && destY <= LARG && abs(destX-(unite->posX))<=1 && abs(destY-(unite->posY))<=1 ) /* On verifie que la destination existe et est vide et que c'est un déplacement adjacent */
    {
                    monde->plateau[unite->posY][unite->posX]=NULL;
                    unite->posX = destX;
                    unite->posY = destY;
                    monde->plateau[destY][destX] = unite;

        }
dessinerplateau(*monde);
}

void enleverUnite(Unite *unite, Monde *monde) {
  UListe *uliste = getUListe(unite->couleur, monde);
  Unite *unitePrec = getUnitePrec(unite, uliste);
  if(unitePrec == unite) {
    uliste->unites = unite->suiv;
  } else if(unitePrec != NULL) {
    unitePrec->suiv = unite->suiv;
  }
  monde->plateau[unite->posY][unite->posX] = NULL;
  free(unite);
}

UListe *getUListe(char couleur, Monde *monde) {
  if(couleur == (monde->rouge)->couleur) {
    return (monde->rouge);
  }
  else if(couleur == (monde->bleu)->couleur) {
    return (monde->bleu);
  }
  else {
    return NULL;
  }

}

Unite *getUnitePrec(Unite *unite, UListe *uliste) {
  Unite *search;
  search = uliste->unites;
  while(search != NULL && search->suiv != unite && search != unite) {
    search = search->suiv;
  }
  return search;
}

void gererTourJoueur(char couleur, Monde *monde) {
  int selection;
  char c='N';
  UListe uliste = *getUListe(couleur, monde);
  int nUnite = nombreUnite(uliste);
  Unite **uniteSelect = creerSelection(uliste);
  int mouseX=414;
  int mouseY=590;
  if(nUnite!=0) {
      affichePlateau(*monde);
    dessinerplateau(*monde);
    printf("Tour : %d | Joueur : %c\n", monde->tour, couleur);
    printf("Tour : %d | Joueur : %c\n", monde->tour, couleur);
    do {
      selection = parcourirUniteSelect(uniteSelect, nUnite, *monde);
      if(selection != -1) {
        actionUnite(uniteSelect[selection], monde);
        nUnite = enleverSelect(uniteSelect, selection, nUnite);
        affichePlateau(*monde);
        dessinerplateau(*monde);
        printf("Voulez-vous arreter votre tour ? (o/n)\n");
        
       
        arreterTour();  
        while (!(mouseX<315 && mouseX>215 && mouseY<641 && mouseY>591) && !(mouseX<515 && mouseX>415 && mouseY<641 && mouseY>591)){
        MLV_wait_mouse(&mouseX, &mouseY);  
            printf("test \n");
        if((mouseX<315 && mouseX>215 && mouseY<641 && mouseY>591)){
            c='O';
        printf("Arret du tour !\n"); 
      }
        else if((mouseX<515 && mouseX>415 && mouseY<641 && mouseY>591))
        {
            c='N';
            printf("PAS arret du tour !\n");
        }
    }
    }}
      while( (c=='N') && (selection > -1) && (nombreUnite(*(monde->rouge)) > 0 && nombreUnite(*(monde->bleu)) > 0));
            printf("ça sort de la boucle ! \n");
          free(uniteSelect);
      
}
}

Unite **creerSelection(UListe uliste) {
  int n = nombreUnite(uliste);
  int i;
  Unite **tab = calloc(n, sizeof(*tab));
  Unite *unite = uliste.unites;
  for(i = 0; i < n && unite != NULL; ++i) {
    tab[i] = unite;
    unite = unite->suiv;
  }

  return tab;
}

int nombreUnite(UListe uliste) {
  Unite *unite;
  int n = 0;
  unite = uliste.unites;
  n += (unite != NULL);
  while(unite != NULL && unite->suiv != NULL) {
    unite = (unite->suiv);
    n++;
  }
  return n;
}

int parcourirUniteSelect(Unite **tab, int length, Monde monde) {
    
  int i = -1;
  char c='N';    
  int mouseX, mouseY; /* Pour permettre l'entrée dans la boucle While*/
   
  printf("--------LISTE UNITES--------\n");
  if(length <= 0) {
    printf("Plus aucune unite selectionnable\n");
    printf("----------------------------\n");
  } 
    else {

          if(i + 1 < length) {
            ++i;  
          } else {
            i = 0;
          }
          hoverSelection(*tab[i],monde);  
          afficherUnite(*tab[i]);    
          printf("Voulez-vous le selectionner ? (o/n)\n");
           MLV_wait_mouse(&mouseX, &mouseY);  

          printf("----------------------------\n");
    while(c=='N') 
    {
 
        if(mouseX<515 && mouseX>415 && mouseY<641 && mouseY>591) {

          if(i + 1 < length) {
            ++i;  
          } else {
            i = 0;
          }
          hoverSelection(*tab[i],monde);  
          afficherUnite(*tab[i]);    
          printf("Voulez-vous le selectionner ? (o/n)\n");
           MLV_wait_mouse(&mouseX, &mouseY);  

          printf("----------------------------\n");
        } else if(mouseX<315 && mouseX>215 && mouseY<641 && mouseY>591) {
            c='O';
        } else {
            MLV_wait_mouse(&mouseX, &mouseY); 
        }
            
    }
              
  }

   
  return i;

}

int enleverSelect(Unite **tab, size_t indice, size_t length) {
  if(indice < length - 1) {
    decaleSelect(tab, indice, length);
  }
  return (length - 1);
}

void decaleSelect(Unite **tab, size_t debut, size_t length) {
  size_t i;
  for(i = debut; i < length - 1; ++i) {
    tab[i] = tab[i + 1];
  }
}

void actionUnite(Unite *unite, Monde *monde) {
  char c='P';       
  troisActions();
  int mouseX, mouseY;
  
    while (c=='P'){
        MLV_wait_mouse(&mouseX, &mouseY);    
      if(mouseX>100 && mouseX<200 && mouseY<641 && mouseY>591){ 
      c='D';
      action(c);
    int posX, posY;
    MLV_wait_mouse(&posX, &posY);
    deplacerUnite(unite, monde, posX/40, posY/40);
  } 
        else if(mouseX>300 && mouseX<400 && mouseY<641 && mouseY>591) {
     
      c='A';
      action(c);
     int attX,attY;
   MLV_wait_mouse(&attX, &attY);
    attaquer(unite, monde, attX/40, attY/40);
  }
        
        
       else if(mouseX>500 && mouseX<600 && mouseY<641 && mouseY>591)  {
           c='T';
   
           
        }   
    }
}

void afficherUnite(Unite unite) {
  printf("\tGenre : %c\n", unite.genre);
  printf("\tPositions x,y : %d,%d\n", unite.posX, unite.posY);
}

int attaquer(Unite *unite, Monde *monde, int destX, int destY){
    if(monde->plateau[destY][destX] !=NULL && unite->couleur!= monde->plateau[destY][destX]->couleur ){
                if (unite->genre==GUERRIER || unite->genre==monde->plateau[destY][destX]->genre){
                    enleverUnite(monde->plateau[destY][destX],monde);
                    deplacerUnite(unite,monde,destX,destY);
                    dessinerplateau(*monde);
                    return 1;
                        }
                    enleverUnite(unite,monde);
        dessinerplateau(*monde);
                    return 0;
    }
dessinerplateau(*monde);
   return 0;

}

int deplacerOuAttaquer(Unite *unite, Monde *monde, int destX, int destY){
    if( destX >= LONG || destY >= LARG){
        return -1;
    }

    if( destX <= LONG && destY <= LARG && abs(destX-(unite->posX))>=1 && abs(destY-(unite->posY))>=1 ){
        return -2;
    }

       if(monde->plateau[destY][destX]->genre == unite->genre){
        return -3;
    }

    if(monde->plateau[destY][destX] == NULL && destX <= LONG && destY <= LARG && abs(destX-(unite->posX))<=1 && abs(destY-(unite->posY))<=1 ) /* On verifie que la destination existe et est vide et que c'est un déplacement adjascent */
    {   deplacerUnite(unite,monde,destX,destY);

        return 1;
    }

    if(monde->plateau[destY][destX]->genre != unite->genre  && destX <= LONG && destY <= LARG && abs(destX-(unite->posX))<=1 && abs(destY-(unite->posY))<=1 ){
        attaquer(unite,monde,destX,destY);
        if ((attaquer(unite,monde,destX,destY))==1){
            return 2;
        }
        return 3;
    }
    return 0;
}

void viderMonde(Monde *monde) {
  viderUListe(monde->rouge);
  viderUListe(monde->bleu);
  initialiserPlateau(monde->plateau);
}

void viderUListe(UListe *uliste) {
  Unite *temp, *unite;
  temp = uliste->unites;
  if(temp != NULL) {
    while(temp->suiv != NULL) {
      unite = temp;
      temp = temp->suiv;
      free(unite);
    }
    free(uliste);
  }

}

void gererTour(Monde *monde) {
    
    ++(monde->tour);
    
    if (nombreUnite(*(monde->rouge)) > 0){
    gererTourJoueur(ROUGE, monde);
    }
    if (nombreUnite(*(monde->bleu)) > 0){
    gererTourJoueur(BLEU, monde);
        }

}

void placerUnite(Monde *monde, UListe *uliste, char genre){
    int posX, posY;
  	MLV_wait_mouse(&posX, &posY);
    printf("%d,%d \n",posX/40,posY/40);
    while (!placerAuMonde(creerUnite(genre, uliste), monde, posX/40, posY/40)){
      printf("Position indisponible \n");
  	MLV_wait_mouse(&posX, &posY);
    }
    
    dessinerplateau(*monde);

}

void placementParJoueur(Monde *monde, char couleur){
    UListe *uliste=getUListe(couleur,monde);

    printf("Où voulez-vous positionner vos deux serfs ? \n ");
    placerUnite(monde,uliste,SERF);
    placerUnite(monde,uliste,SERF);
    printf(" Placez votre guerrier. \n");
    placerUnite(monde,uliste,GUERRIER);
}

void placementInitial(Monde *monde){
    char couleur='N';
    printf("Qui commence ? (R/B) \n");
    int posX, posY;
  	MLV_wait_mouse(&posX, &posY);
      if(posX<250 && posX>50 && posY<691 && posY>591){   
        reinitialiseInterface();
        couleur='R';
    
    }
     if(posX<650 && posX>450 && posY<691 && posY>591){   
         reinitialiseInterface();
        couleur='B';
          
   
    }
    while(couleur != ROUGE && couleur != BLEU) {
           printf("Veuillez appuyer sur une couleur!\n");
        MLV_wait_mouse(&posX, &posY);  
    if(posX<250 && posX>50 && posY<691 && posY>591){   
        reinitialiseInterface();
        couleur='R';
    
    }
     if(posX<650 && posX>450 && posY<691 && posY>591){   
         reinitialiseInterface();
        couleur='B';
          
   
    }
    
    }
     Pos(couleur);
     placementParJoueur(monde,couleur);
   
    printf("À l'autre joueur de placer ses unités :) \n");
    if('B' == couleur){
        Pos('R');
    placementParJoueur(monde,ROUGE);
          
  } else {
        Pos('B');
    placementParJoueur(monde,BLEU);
  }
}

int arreterPartie(Monde monde){
    if (nombreUnite(*(monde.rouge)) > 0 && nombreUnite(*(monde.bleu)) > 0){
    arreterPartieGr();
    char c='N';
    printf("Voulez vous quitter la partie ? (o/n)\n");
    int mouseX, mouseY;
    MLV_wait_mouse(&mouseX, &mouseY);  
    
     while(c=='N') 
    {
         
    if((mouseX<515 && mouseX>415 && mouseY<641 && mouseY>591)){
    return 0;
        }
    else if(mouseX<315 && mouseX>215 && mouseY<641 && mouseY>591) {
            c='O';
        return 1;

        } 
    else {
           
    MLV_wait_mouse(&mouseX, &mouseY); 
        }
}

}
    return 0;
    }



void gererPartie(void){
    printf("ça rentre dans gererpartie \n");
    Monde mondejeu;
    int arret = 0;
    char gagnant;
    initialiserMonde(&mondejeu);
    creerFenetre();
  
    quiCommence(); 
    affichePlateau(mondejeu);
    dessinerplateau(mondejeu);
    /*3PIONS 1 GUERRIER 2 SERFS */
    placementInitial(&mondejeu);
    printf("Début de la partie \n ");
    affichePlateau(mondejeu);
    dessinerplateau(mondejeu);
    
    
    while( arret==0 && (nombreUnite(*(mondejeu.rouge)) > 0 && nombreUnite(*(mondejeu.bleu)) > 0)) {
    gererTour(&mondejeu);
    arret = arreterPartie(mondejeu);
    }
        /*viderMonde(&mondejeu);*/


     if (nombreUnite(*(mondejeu.bleu)) <= 0)
      {   	gagnant='R';
            Fin(gagnant);
         MLV_wait_seconds(5);

	   MLV_free_window();
          printf("Fin de la partie, le joueur ROUGE a gagne !");
      } 
    
      if (nombreUnite(*(mondejeu.rouge)) <= 0) 
    {     gagnant='B';
            Fin(gagnant);
          
          MLV_wait_seconds(5);

	   MLV_free_window();
          printf("Fin de la partie, le joueur BLEU a gagne !");
      }
    
         gagnant='N';
         Fin(gagnant);
         MLV_wait_seconds(5);

	   MLV_free_window();
        printf("Fin de la partie, pas de gagnants.");
        
      
    
    
}


