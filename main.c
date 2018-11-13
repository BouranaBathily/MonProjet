#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "fonctions.c"

int main()
{
  int nbMines=0;
  int i, j;
  srand(time(NULL)); //Afficher le début du jeu
  printf("|____________________________________________________|\n");
  printf("|_____________________LE DEMINEUR____________________|\n");
  printf("|____________________________________________________|\n\n");
  init();// appel fonction init
  do {
    printf("\nCombien de mines voulez-vous ?\n\n");
    scanf("%d", &nbMines);
  }
  while( (nbMines < MINE) || (nbMines >= (nbLin*nbCol)) );
  printf("Vous avez choisi de jouer avec %d mines\n\n", nbMines);
  placeM(nbMines);
  printf("Voici la grille des mines :\n");

  for (i=1; i<=nbLin; i++) {
    printf("\t\t");
    for (j=1; j<=nbCol; j++)
      if (mines[i][j])
	printf("M ");
      else
	printf(". ");
    printf("\n");
  }


  printf("\nVoici la grille de jeu:\n");
  afficheJeu();
  jouer();
  return 0;
}
