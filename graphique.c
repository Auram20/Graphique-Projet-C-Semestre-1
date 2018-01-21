
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "graphique.h"

void creerFenetre(){

	MLV_create_window( "Jeu de Stratégie", "Jeu", 721, 721 );
    MLV_draw_filled_rectangle(0, 0, 721, 721, MLV_rgba(206,206,206,255));
            }

void dessinerplateau(Monde monde){

    int x;
    int y;      
    MLV_Image *imageGB, *imageGR, *imageSB, *imageSR;
    
    imageGB = MLV_load_image( "GB.png" ); 
    imageGR = MLV_load_image( "GR.png" ); 
    imageSB = MLV_load_image( "SB.png" ); 
    imageSR = MLV_load_image( "SR.png" ); 
    MLV_resize_image_with_proportions( imageGB, 30, 30);
    MLV_resize_image_with_proportions( imageGR, 30, 30);
    MLV_resize_image_with_proportions( imageSB, 30, 30);
    MLV_resize_image_with_proportions( imageSR, 30, 30);
    
    for (x=1;x<=722;x=x+40){
        for (y=0;y<=482;y=y+40){
              MLV_draw_filled_rectangle(x, y, 40, 40, MLV_rgba(206,206,206,255));
                    }
                                }
for (x=0;x<=721;x=x+40){
             MLV_draw_line(x,0,x,480,MLV_COLOR_BLACK);
           }
 for (x=0;x<=481;x=x+40){
             MLV_draw_line(0,x,720,x,MLV_COLOR_BLACK);
           }




for (x = 0; x < LONG; x++){

		for (y = 0; y < LARG; y++) {

            if (monde.plateau[x][y] != NULL){

		
            if (monde.plateau[x][y]->couleur == ROUGE){
                 
			if (monde.plateau[x][y]->genre == SERF){
					 MLV_draw_image( imageSR, y*40+5 , x*40+5  );
				} 
                else {
					 MLV_draw_image( imageGR, y*40+5 , x*40+5  );
				        }
                    }
                
                 if (monde.plateau[x][y]->couleur == BLEU){

			if (monde.plateau[x][y]->genre == SERF){
				 MLV_draw_image( imageSB, y*40+5 , x*40+5  );
				} 
                     else {
					 MLV_draw_image( imageGB, y*40 +5, x*40 +5 );
				}
        }
            
            }
}

}




        MLV_actualise_window();

    	/*MLV_wait_seconds(30);

	   MLV_free_window();
*/
}


void quiCommence(){
   reinitialiseInterface();
   MLV_draw_text(290,600,"QUI COMMENCE ? ",MLV_rgba(191,63,63,255));
    MLV_draw_filled_rectangle(50, 591, 200, 100, MLV_rgba(191,63,63,255));
     MLV_draw_filled_rectangle(450, 591, 200, 100, MLV_rgba(63,127,191,255));
    MLV_actualise_window();
    
}

void reinitialiseInterface(){
     MLV_draw_filled_rectangle(0, 482, 720, 340, MLV_rgba(206,206,206,255));
 MLV_actualise_window();
}
void Pos(char couleur){
    if (couleur=='R'){
        reinitialiseInterface();
             MLV_draw_text(180,
		500,"ROUGE : POSITIONNES TES 2 SERFS PUIS TON GUERRIER",MLV_rgba(191,63,63,255));
    }
    
     if (couleur=='B'){
         reinitialiseInterface();
             MLV_draw_text(180,
		500,"BLEU : POSITIONNES TES 2 SERFS PUIS TON GUERRIER",MLV_rgba(63,127,191,255));
    }
    MLV_actualise_window();
}
void troisActions(){
   reinitialiseInterface();
    MLV_draw_text(200,
		500,"QUE VOULEZ-VOUS FAIRE AVEC CE PION",MLV_rgba(191,63,63,255));
    MLV_draw_text_box(
		100,591,100,50,
		"Déplacer",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    
     
    MLV_draw_text_box(
		300,591,100,50,
		"Attaquer",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    MLV_draw_text_box(
		500,591,100,50,
		"Attendre",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    
    
    MLV_actualise_window();
    
}


void hoverSelection(Unite unite){
      reinitialiseInterface();
    printf("%d et %d",unite.posX,unite.posY);
     MLV_draw_filled_rectangle((unite.posX)*40,(unite.posY)*40, 40, 40, MLV_rgba(127,191,63,100));
    
     MLV_draw_text_box(
		215,591,100,50,
		"OUI",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
          MLV_draw_text_box(
		415,591,100,50,
		"NON",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    if (unite.couleur=='R'){
     MLV_draw_text(200,
		500,"ROUGE :VEUX-TU SELECTIONNER CETTE UNITE ? ",MLV_rgba(191,63,63,255));
           }
    if (unite.couleur=='B'){
     MLV_draw_text(200,
		500,"BLEU :VEUX-TU SELECTIONNER CETTE UNITE ? ",MLV_rgba(191,63,63,255));
           }
    
    
    
    
    MLV_actualise_window();
    
     }

void action(char acte){
   reinitialiseInterface();
    if(acte=='D'){
    MLV_draw_text(200,
		500,"CLIQUE SUR LA CASE OÙ TU VEUX DÉPLACER TON UNITÉ",MLV_rgba(191,63,63,255));
    }
      if(acte=='A'){
    MLV_draw_text(200,
		500,"CLIQUE SUR L'UNITÉ QUE TU VEUX ATTAQUER",MLV_rgba(191,63,63,255));
    }
    
    MLV_actualise_window();
    
}

void arreterTour(){
   reinitialiseInterface();
    MLV_draw_text(240,
		500,"VEUX-TU ARRETER TON TOUR ? ",MLV_rgba(191,63,63,255));
    
     MLV_draw_text_box(
		215,591,100,50,
		"OUI",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
          MLV_draw_text_box(
		415,591,100,50,
		"NON",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    MLV_actualise_window();
    
}

void arreterPartieGr(){
   reinitialiseInterface();
    MLV_draw_text(200,
		500,"VOULEZ-VOUS ARRETER LA PARTIE ? ",MLV_rgba(191,63,63,255));
    
     MLV_draw_text_box(
		215,591,100,50,
		"OUI",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
          MLV_draw_text_box(
		415,591,100,50,
		"NON",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(63,127,191,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    MLV_actualise_window();
    
}


void Fin(char ecranfin){
      MLV_draw_filled_rectangle(0, 0, 721, 721, MLV_rgba(206,206,206,255));
    
     if(ecranfin=='B'){
             MLV_draw_text(240,
		360.5,"BLEU A GAGNÉ ",MLV_rgba(191,63,63,255));
         
         
     }
    if(ecranfin=='R'){
          MLV_draw_text(240,
		360.5,"ROUGE A GAGNÉ ",MLV_rgba(191,63,63,255));
         
     }
      if(ecranfin=='N'){
        MLV_draw_text(240,
		360.5,"FIN DE LA PARTIE PAS DE GAGNANT",MLV_rgba(191,63,63,255));
      }
    MLV_actualise_window();
    
}