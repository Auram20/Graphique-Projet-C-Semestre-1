#include "functions.h"
#include "structures.h"
#include "graphique.h"

#include <stdio.h>
#include <stdlib.h>


int main(void) {
  Monde monmonde;
    int mouseX, mouseY;
 
  if(!initialiserMonde(&monmonde)) {
    printf("Erreur Mémoire\n");
    return EXIT_FAILURE;
  }
    musique();
    Debut();
    MLV_wait_mouse(&mouseX, &mouseY); 
    if((mouseX<450 && mouseX>250 && mouseY<341 && mouseY>291)){ 
        gererPartie();
}
  return EXIT_SUCCESS;
}
