
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "graphique.h"



void musique(){
     MLV_init_audio();

        MLV_Music *music;
    music= MLV_load_music("dofus.mp3");
        
 
    MLV_play_music(music,1.0,-1); 
}


void creerFenetre(){
    

    MLV_Image *plateau;
    plateau=MLV_load_image("plateau.jpg");
    MLV_draw_image(plateau,0,0);
    
    MLV_actualise_window();

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
    
for (x=0;x<=721;x=x+40){
             MLV_draw_line(x,0,x,480,MLV_rgba(76,25,25,100));
           }
 for (x=0;x<=481;x=x+40){
             MLV_draw_line(0,x,720,x,MLV_rgba(76,25,25,100));
           }
 MLV_Image *plateau;
    plateau=MLV_load_image("interfaceplateau.jpg");
    MLV_draw_image(plateau,0,0);



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
   MLV_draw_text(260,500,"QUI POSITIONNE EN PREMIER ? ",MLV_rgba(191,63,63,255));
    MLV_draw_filled_rectangle(50, 591, 200, 100, MLV_rgba(191,63,63,255));
     MLV_draw_filled_rectangle(450, 591, 200, 100, MLV_rgba(63,127,191,255));
    MLV_actualise_window();
    
}

void reinitialiseInterface(){
MLV_Image *interface;
    interface=MLV_load_image("interface.jpg");
    MLV_draw_image(interface,0,482);
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
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    
     
    MLV_draw_text_box(
		300,591,100,50,
		"Attaquer",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    MLV_draw_text_box(
		500,591,100,50,
		"Attendre",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    
    
    MLV_actualise_window();
    
}


void hoverSelection(Unite unite,Monde monde){
        dessinerplateau(monde);
      reinitialiseInterface();
    printf("%d et %d",unite.posX,unite.posY);
     MLV_draw_rectangle((unite.posX)*40,(unite.posY)*40, 40, 40, MLV_rgba(219,0,0,250));
    MLV_draw_rectangle((unite.posX)*40+1,(unite.posY)*40+1, 38, 38, MLV_rgba(219,0,0,250));
    
     MLV_draw_text_box(
		215,591,100,50,
		"OUI",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
          MLV_draw_text_box(
		415,591,100,50,
		"NON",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
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
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
          MLV_draw_text_box(
		415,591,100,50,
		"NON",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
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
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
          MLV_draw_text_box(
		415,591,100,50,
		"NON",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    MLV_actualise_window();
    
}


void Debut(){
    MLV_create_window( "Jeu de Stratégie", "Jeu", 721, 721 );
      MLV_Image *accueil;
    accueil=MLV_load_image("accueil.jpg");
    MLV_draw_image(accueil,0,0);
            MLV_Font* font = MLV_load_font( "Cardinal.ttf" , 80 );
        MLV_draw_text_with_font(
                100, 20,
                "LA GUERRE", 
                font, MLV_rgba(84,71,65,255)
        ); 
       MLV_draw_text_with_font(
                270, 100,
                "DES", 
                font, MLV_rgba(84,71,65,255)
        ); 
       MLV_draw_text_with_font(
                120, 180,
                "HAMEAUX", 
                font, MLV_rgba(84,71,65,255)
        ); 
    
    MLV_draw_text_box(
		250,291,200,50,
		"LANCER UNE PARTIE",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
     MLV_draw_text_box(
		250,391,200,50,
		"COMMENT JOUER ?",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
           MLV_draw_text_box(
250,491,200,50,
		"QUITTER ?",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    
    MLV_actualise_window();
    
}

void Rules(){

      MLV_Image *accueil;
    accueil=MLV_load_image("accueil.jpg");
    MLV_draw_image(accueil,0,0);
            MLV_Font* font = MLV_load_font( "Cardinal.ttf" , 80 );
        MLV_draw_text_with_font(
                100, 20,
                "LA GUERRE", 
                font, MLV_rgba(84,71,65,255)
        ); 
       MLV_draw_text_with_font(
                270, 100,
                "DES", 
                font, MLV_rgba(84,71,65,255)
        ); 
       MLV_draw_text_with_font(
                120, 180,
                "HAMEAUX", 
                font, MLV_rgba(84,71,65,255)
        ); 
    
            MLV_draw_adapted_text_box(
                50, 320, "Bonjour et bienvenue sur notre jeu. \n Le but est simple, il faut décimer les unités ennemies. \n \n \n  Chacun des deux joueurs a trois unités. Deux de types Serf, une de type guerrier. \n \n Vous ne pouvez vous déplacer ou attaquer que dans les 8 \n cases adjascentes. \n \n  Les Guerriers sont les plus forts, ne les attaquez pas avec vos Serfs. \n Les Guerriers déciment toutes les unités. Attaquer le meme type d'unité vous fait vaiqueur. \n \n Le joueur ROUGE commence toujours en premier.\n Il vous faut au moins jouer une unité avant de pouvoir passer votre tour. \n  \n \n Que le meilleur gagne.", 2,
               MLV_rgba(84,71,65,0),  MLV_COLOR_WHITE, MLV_rgba(84,71,65,120),
                MLV_TEXT_CENTER
        );
    
            MLV_draw_text_box(
250,641,200,50,
		"LANCER UNE PARTIE ?",
		5,
		MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_rgba(84,71,65,255),
			MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
	);
    
    
    MLV_actualise_window();
    
    
    
}

void Fin(char ecranfin){
    
    MLV_Image *accueil;
    accueil=MLV_load_image("accueil.jpg");
    MLV_draw_image(accueil,0,0);
    MLV_Font* font = MLV_load_font( "Cardinal.ttf" , 80 );
        MLV_draw_text_with_font(
                100, 20,
                "LA GUERRE", 
                font, MLV_rgba(84,71,65,255)
        ); 
       MLV_draw_text_with_font(
                270, 100,
                "DES", 
                font, MLV_rgba(84,71,65,255)
        ); 
       MLV_draw_text_with_font(
                120, 180,
                "HAMEAUX", 
                font, MLV_rgba(84,71,65,255)
        ); 
    
    
     if(ecranfin=='B'){
                  MLV_draw_adapted_text_box(
                240, 360.5, "BLEU A GAGNÉ", 2,
               MLV_rgba(84,71,65,0),  MLV_COLOR_WHITE, MLV_rgba(84,71,65,120),
                MLV_TEXT_CENTER
        );
         
         
     }
    if(ecranfin=='R'){
                MLV_draw_adapted_text_box(
                240, 360.5, "ROUGE A GAGNÉ", 2,
               MLV_rgba(84,71,65,0),  MLV_COLOR_WHITE, MLV_rgba(84,71,65,120),
                MLV_TEXT_CENTER
        );
         
     }
      if(ecranfin=='N'){
                 MLV_draw_adapted_text_box(
                240, 360.5, "FIN DE LA PARTIE, PAS DE GAGNANTS.", 2,
               MLV_rgba(84,71,65,0),  MLV_COLOR_WHITE, MLV_rgba(84,71,65,120),
                MLV_TEXT_CENTER
        );
      }
    
       
    MLV_actualise_window();
    
}


