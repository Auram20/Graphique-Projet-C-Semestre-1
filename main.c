#include "functions.h"
#include "structures.h"
#include "graphique.h"

#include <stdio.h>
#include <stdlib.h>


int main(void) {
  Monde monmonde;
  int mouseX, mouseY;
  char c='T';
  if(!initialiserMonde(&monmonde)) {
    printf("Erreur Mémoire\n");
    return EXIT_FAILURE;
  }
    musique();
    Debut();

    
    while (c=='T'){
            MLV_wait_mouse(&mouseX, &mouseY); 
    if((mouseX<450 && mouseX>250 && mouseY<341 && mouseY>291)){ 
        gererPartie();
        
        c='P';
        }
    else if(((mouseX<450 && mouseX>250 && mouseY<441 && mouseY>391))){
           Rules();
           c='R';
           char d='T';
           int mouseX2,mouseY2;     
            while (d=='T'){    
           MLV_wait_mouse(&mouseX2, &mouseY2); 
           if((mouseX2<450 && mouseX2>250  && mouseY2<691 && mouseY2>641)){
               d='P';    
               gererPartie();
                }
                }
                }
    
     else if(((mouseX<450 && mouseX>250 && mouseY<541 && mouseY>491))){
        c='Q';     
     }
         }
    
  return EXIT_SUCCESS;
}
