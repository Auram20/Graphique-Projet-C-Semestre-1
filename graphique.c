
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "graphique.h"


void dessinerplateau(){

	MLV_create_window( "Jeu de Stratégie", "Jeu", 722, 482 );
    int x;
    for (x=1;x<=722;x=x+40){
        
        MLV_draw_line(x,0,x,480,MLV_COLOR_WHITE);  
        MLV_draw_line(0,x,720,x,MLV_COLOR_WHITE); 
        
    }
    
   MLV_actualise_window();                        
    
}
                      

