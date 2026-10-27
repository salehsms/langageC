#include <fstream>
#include "types.hpp"
#include "view.hpp"
#include "board.hpp"
#include "mask.hpp"
#include <iostream>
using namespace std;
/******* fonction permettant de vider**************************/

void empty(Plata plateau[taille_plateau][taille_plateau]) {

  for (int i = 0; i < taille_plateau; i++) {
    for (int j = 0; j < taille_plateau; j++) {
      plateau[i][j].type = case_vide;
    }
  }
}

Plata get_square(int x, int y, Plata pl[taille_plateau][taille_plateau]) {
  return pl[x][y];
}	
/********** fonction qui permet de modifier le contenu d'une case *******/

void set_square(int lig, int col, Plata p[taille_plateau][taille_plateau], Plata c) {
  p[lig][col] = c; 
}


/************la fonction qui permet d'initialiser le plateau avec ses piece***********/

void start(Plata plateau[taille_plateau][taille_plateau]) {
  empty(plateau);
  // initialisation des pions blancs
  for (int i = 0; i < taille_plateau; i++) {
    plateau[1][i].type = 'P';
    plateau[1][i].couleur = true;
  }

  // initialisation des pions noirs
  for (int i = 0; i < taille_plateau; i++) {
    plateau[6][i].type = 'p';
    plateau[6][i].couleur = false;
  }

  // Des tours blanches
  plateau[0][0].type = 'T';
  plateau[0][0].couleur = true;
  plateau[0][7].type = 'T';
  plateau[0][7].couleur = true;

  // Des tours noirs
  plateau[7][0].type = 't';
  plateau[7][0].couleur = false;
  plateau[7][7].type = 't';
  plateau[7][7].couleur = false;

  // Des cavaliers blancs
  plateau[0][1].type = 'C';
  plateau[0][1].couleur = true;
  plateau[0][6].type = 'C';
  plateau[0][6].couleur = true;

  // Des cavaliers noirs
  plateau[7][1].type = 'c';
  plateau[7][1].couleur = false;
  plateau[7][6].type = 'c';
  plateau[7][6].couleur = false;

  // Des fous blancs
  plateau[0][2].type = 'F';
  plateau[0][2].couleur = true;
  plateau[0][5].type = 'F';
  plateau[0][5].couleur = true;

  // Des fous noirs
  plateau[7][2].type = 'f';
  plateau[7][2].couleur = false;
  plateau[7][5].type = 'f';
  plateau[7][5].couleur = false;

  // Dame blanches et noirs
  plateau[0][3].type = 'D';
  plateau[0][3].couleur = true;
  plateau[7][3].type = 'd';
  plateau[7][3].couleur = false;

  // Roi blancs et noirs
  plateau[0][4].type = 'R';
  plateau[0][4].couleur = true;
  plateau[7][4].type = 'r';
  plateau[7][4].couleur = false;
}
/****************fonction qui verifie si le deplacement est posssible*********************/

void movie_piece(int depX, int depY, int arivX, int arivY,Plata plateau[taille_plateau][taille_plateau]) {
  // verification des coordonnées depart et d'arrivée

  if (depX < 0 || depX > 7 || depY < 0 || depY > 7 || arivX < 0 || arivX > 7 ||
      arivY < 0 || arivY > 7) {
    cout << "le deplacement peut pas avoir lieu ,coordonnées invalides";
    return;
  }

  // verifie si la case de depart n'est vide
  if (plateau[depX][depY].type == case_vide) {
    cout << "deplacement impossible car s'est une case vide ";
    return;
  } else {
    plateau[arivX][arivY].type=plateau[depX][depY].type ;
    plateau[depX][depY].type = case_vide;
  }
}
/*une fonction write FEN qui  ́ecrit l’ ́etat du plateau sous format FEN dans un fichier. Le plateau et le fichier sont des param`etres de la fonction.*/
void write_FEN(Plata p[taille_plateau][taille_plateau], char *file_name) {
  ofstream file(file_name);
  int cpt = 1;
  for (int i = 0; i < taille_plateau; i++) {
    for (int j = 0; j < taille_plateau; j++) {
      if (p[i][j].type != case_vide) {
        file << p[i][j].type;
      } else {
        cpt++;
        if (j == 7 || p[i][j + 1].type != case_vide) {
          file << cpt;
          cpt = 1;
        }
      }

      if (j == 7) {
        file << "/";
      }
    }
  }
  file.close();
}

/**********fonction de deplacement possible************************/
void highlight_possible_moves(int lig, int col,Plata pl[taille_plateau][taille_plateau],int mask [taille_plateau][taille_plateau]) {
  switch (pl[lig][col].type) {
  case 'R':
    highlight_possible_moves_king(lig, col, pl, mask);
    break;

  case 'r':
    highlight_possible_moves_king(lig, col, pl, mask);
    break;

  case 'T':
    highlight_possible_moves_rook(lig, col, pl, mask);
    break;

  case 't':
    highlight_possible_moves_rook(lig, col, pl, mask);
    break;
    case 'C' :
    highlight_possible_moves_knight(lig,col,pl,mask);
    break; 
    case 'c' :
    highlight_possible_moves_knight(lig,col,pl,mask);
    break;

    case 'D' :
    highlight_possible_moves_queen(lig,col,pl,mask);
    break;

    case 'd' :
    highlight_possible_moves_queen(lig,col,pl,mask);
    break;

    case 'F' : 
    highlight_possible_moves_bishop(lig,col,pl,mask);
    break;

    case 'f' : 
    highlight_possible_moves_bishop(lig,col,pl,mask);
    break;

    case 'P' :
    highlight_possible_moves_pawn(lig,col,pl,mask);
    break;

    case 'p' :
    highlight_possible_moves_pawn(lig,col,pl,mask);
    break;
  }
}


/****** deplacement possible du roi*********************/
void highlight_possible_moves_king(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) {

  // verifications de toute les cases adjacentes
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      cout<< i <<" "<< j <<endl;
      // verification si la case est dans le plateau
      if (lig + i >= 0 && lig + i < taille_plateau && col + j >= 0 && col + j < taille_plateau) {
        // verification si la case est vide ou occupé par une piece enemmie
        if (pl[lig + i][col + j].type == 'V' || pl[lig+i][col+j].couleur != pl[lig + i][col + j].couleur) {
          mask[i][j] = 1;
        }
      }
    }
  }
  cout<< " fini " <<endl;
}
/*****************************deplacement possible de la tour****************/
void highlight_possible_moves_rook(int x, int y,Plata pl[taille_plateau][taille_plateau],int mask [taille_plateau][taille_plateau]) {

  int color = pl[x][y].couleur;

  // Vérification des mouvements vers le haut
  for (int i = x - 1; i >= 0; i--) {
    if (pl[i][y].type == 'V') { // verifie si les cases au dessus de la piece sont vides ,si
      mask[i][y] = 1;                        // s'est le cas met le masque a 1 sur tous le dessus
      
    } else if (pl[i][y].couleur != color) { // si ya une piece adverse , met le
      mask[i][y] = 1;                       // masque a 1 et arrete la boucle
      break;
      
    }else {
      break;
    }
    
  }
//Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]
  // Vérification des mouvements vers le bas
  for (int i = x + 1; i < taille_plateau; i++) {
    if (pl[i][y].type == 'V') {
      mask[i][y] = 1;
    }

    else if (pl[i][y].couleur != color) {
      mask[i][y]= 1;
      break;
    }

    else {
      break;
    }
  }

  // Vérification des mouvements vers la gauche
  for (int j = y - 1; j >= 0; j--) {
    if (pl[x][j].type == 'V') {
      mask[x][j] = true;

    } else if (pl[x][j].couleur != color) {
      mask[x][j] = 1;
      break;
    }

    else {
      break;
    }
  }

  // Vérification des mouvements vers la droite
  for (int j = y + 1; j < taille_plateau; j++) {
    if (pl[x][j].type == 'V') {
      mask[x][j]= 1;
    } 
    else if (pl[x][j].couleur != color) {
      mask[x][j] = 1;
      break;
    } 
    else {
      break;
    }
  }
}

/*********deplacement possible du fou****************************/
void highlight_possible_moves_bishop(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) {
  // Déplacements diagonaux en haut à gauche
  for (int i = 1; lig - i >=  0 && col - i >= 0; i++) {
    if (pl[lig - i][col - i].type == 'V') {
      mask[lig - i][col - i]= 1;
    }
    else if (pl[lig - i][col - i].couleur != pl[lig][col].couleur) {
      mask[lig - i][col - i]= 1;
      break;
    }
    else {
      break;
    }
  }

  // Déplacements diagonaux en haut à droite
  for (int i = 1; lig - i >= 0 && col + i < taille_plateau; i++) {
    if (pl[lig - i][col + i].type == 'V') {
      mask[lig - i][col + i]= 1;
    }
    else if (pl[lig - i][col + i].couleur != pl[lig][col].couleur) {
      mask[lig - i][col + i] = 1;
      break;
    } 
    else {
      break;
    }
  }

  // Déplacements diagonaux en bas à gauche
  for (int i = 1; lig + i < taille_plateau && col - i >= 0; i++) {
    if (pl[lig + i][col - i].type == 'V') {
      mask [lig + i][col - i]= 1;
    }
    else if (pl[lig + i][col - i].couleur != pl[lig][col].couleur) {
      mask[lig + i][col - i]= 1;
      break;
    } 
    else {
      break;
    }
  }
  // Déplacements diagonaux en bas à droite
  for (int i = 1; lig + i < taille_plateau && col + i < taille_plateau; i++) {
    if (pl[lig + i][col + i].type == 'V') {
      mask[lig + i][col + i] = 1;
    } else if (pl[lig + i][col + i].couleur != pl[lig][col].couleur) {
      mask[lig + i][col + i] = 1;
      break;
    }
    else {
      break;
    }
  }
}



/***************deplacement de la reine**********************/
void highlight_possible_moves_queen(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]){
  highlight_possible_moves_bishop(lig,col,pl,mask);
  highlight_possible_moves_rook(lig,col,pl,mask);
}

/******************deplacement du cavalier********************/
void highlight_possible_moves_knight(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) {
    // Tableau des déplacements possibles du cavalier
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    // Parcours des déplacements possibles
    for (int i = 0; i < 8; i++) {
        int newX = lig + dx[i];
        int newY = col + dy[i];
        
        // Vérification si la case est dans le plateau
        if (newX >= 0 && newX < taille_plateau && newY >= 0 && newY < taille_plateau) {
            // Vérification si la case est vide ou occupée par une pièce adverse
            if (pl[newX][newY].type == 'V' || pl[newX][newY].couleur != pl[lig][col].couleur) {
                mask[newX][newY] = 1;
            }
        }
    }
}

/*******************deplacement possible du pion *****************************/
void highlight_possible_moves_pawn(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) {
    // Vérification de la couleur du pion
    char couleur = pl[lig][col].couleur;
    
    // Vérification de la direction de déplacement
    int direction = (couleur == 0) ? 1 : -1; // 'B' pour les pions noirs, 'N' pour les pions blancs
    
    // Vérification des cases adjacentes en diagonale pour les prises
    if (col > 0 && pl[lig+direction][col-1].couleur != couleur)
        mask[lig+direction][col-1] = 1;
    if (col < taille_plateau-1 && pl[lig+direction][col+1].couleur != couleur)
        mask[lig+direction][col+1] = 1;
    
    // Vérification du déplacement en avant
    if (pl[lig+direction][col].type == 'V') {
        mask[lig+direction][col] = 1;
        
        // Vérification du déplacement initial (deux cases)
        if ((lig == 1 && couleur == 0) || (lig == taille_plateau-2 && couleur == 1)) {
            if (pl[lig+2*direction][col].type == 'V')
                mask[lig+2*direction][col] = 1;
        }
    }
}





/***fonction qui permet de savoir toutes les pieces qui peuvent etre attaquées */
void highlight_attacked_pieces(Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]) {
    for (int i = 0; i < taille_plateau; i++) {
        for (int j = 0; j < taille_plateau; j++) {
            // Vérification si la case contient une pièce du joueur adverse
            if (pl[i][j].type != 'V' && pl[i][j].couleur != 1) {
                // Appel de la fonction highlight_possible_moves correspondante selon le type de pièce
                switch (pl[i][j].type) {
                    case 'R':
                        highlight_possible_moves_king(i, j, pl, mask);
                        break;
                    case 'T':
                        highlight_possible_moves_rook(i, j, pl, mask);
                        break;
                    case 'F':
                        highlight_possible_moves_bishop(i, j, pl, mask);
                        break;
                    case 'D':
                        highlight_possible_moves_queen(i, j, pl, mask);
                        break;
                    case 'C':
                        highlight_possible_moves_knight(i, j, pl, mask);
                        break;
                    case 'P':
                        highlight_possible_moves_pawn(i, j, pl, mask);
                        break;
                }
            }
            else if (pl[i][j].type != 'V' && pl[i][j].couleur != 0) {
                // Appel de la fonction highlight_possible_moves correspondante selon le type de pièce
                switch (pl[i][j].type) {
                    case 'r':
                        highlight_possible_moves_king(i, j, pl, mask);
                        break;
                    case 't':
                        highlight_possible_moves_rook(i, j, pl, mask);
                        break;
                    case 'f':
                        highlight_possible_moves_bishop(i, j, pl, mask);
                        break;
                    case 'd':
                        highlight_possible_moves_queen(i, j, pl, mask);
                        break;
                    case 'c':
                        highlight_possible_moves_knight(i, j, pl, mask);
                        break;
                    case 'p':
                        highlight_possible_moves_pawn(i, j, pl, mask);
                        break;
                }
            }
          
        }
    }
}

