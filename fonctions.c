#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define nbLin 20
#define nbCol 20
#define MINE 5

int i, j;
char  tab[nbLin+2][nbCol+2];//grille de jeu
char mines[nbLin+2][nbCol+2];//grille de mines
char autour[nbLin+2][nbCol+2]; // Grille donnant le nbre de mines autour

// intialisation du tableau
void init(void) {

  for(i=0; i<nbLin+2; i++)
    for(j=0;j<nbCol+2;j++) {
      tab [i][j] = '-';
      mines[i][j] = 0;

    }
}
// affichage tableau de jeu
void afficheJeu(void) {
  int i, j;
  printf("\n\n");
  for (i=1 ;i<=nbLin; i++) {
    printf("\t\t");
    for (j=1; j<=nbCol; j++)
      printf("%c ", tab[i][j]);
    printf("\n");
  }
}


// Fonction pour placer les mines
void placeM(int nbMines){
  int i,j;
  int m;
  while(nbMines){
    i = rand()%nbLin+1;
    j = rand()%nbCol+1;
    if (!mines[i][j]){//si la case est libre
      mines[i][j] = 'M'; //on place M
      nbMines--;//on décremente le nombre de mines
    }
  }
}
// fonction pour débuter le jeu
void jouer(){

  int Lig;
  int Col;
  int perdu = 0;
  int compteur = 0; // Pour compter combien de cases ont été découverte
  int nbcasesm = nbLin*nbCol - MINE; // Nombre de cases sans mine

  //printf("\nJeu du démineur\n\n");

  while ((perdu == 0) && (compteur != nbcasesm)){


    printf("Entre Numerro Ligne : ");
    scanf("%d",&Lig);
    while ((Lig < 0) || (Lig >= nbLin)){
      printf("Ligne invalide : ");
      scanf("%d",&Lig);
    }

    printf("Entrez Numero Colonne : ");
    scanf("%d",&Col);
    while ((Col < 0) || (Col >= nbCol)){
      printf("Colonne invalide : ");
      scanf("%d",&Col);
    }
    printf("\n");

    if (mines[Lig][Col] == 'M'){
      perdu = 1; //VOUS AVEZ PERDU!
      printf("C'est une mine :\n\n");
    }
  }

  if (perdu == 1){
    printf("Game Over\n\n");
  }else{
    printf("Vous avez gagné!\n\n");
  }


}
