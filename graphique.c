
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

				MLV_Color color;

            if (monde.plateau[x][y]->couleur == ROUGE){
					color = MLV_rgba(191,63,63,255);

				} else {
					color = MLV_rgba(63,127,191,255);
				}

				if (monde.plateau[x][y]->genre == SERF){
					MLV_draw_filled_ellipse(y*40 + 15, x*40 + 15, 7, 7, color);
				} else {
					MLV_draw_filled_rectangle(y*40 + 12, x*40 + 12, 12, 12, color);
				}
        }}
}






        MLV_actualise_window();

    	/*MLV_wait_seconds(30);

	   MLV_free_window();
*/
}


void quiCommence(){
   
    MLV_draw_text(300,
		700,"Qui commence ?",MLV_rgba(191,63,63,255));
    MLV_draw_filled_rectangle(50, 591, 200, 100, MLV_rgba(191,63,63,255));
     MLV_draw_filled_rectangle(450, 591, 200, 100, MLV_rgba(63,127,191,255));
    
    
}

void reinitialiseInterface(){
     MLV_draw_filled_rectangle(0, 480, 720, 340, MLV_rgba(206,206,206,255));
      MLV_draw_text(300,
		700,"AZY POSITIONNE TA RACE",MLV_rgba(191,63,63,255));
}