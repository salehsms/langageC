#include "board.hpp"
#include "types.hpp"
#include "view.hpp"
#include <iostream>
using namespace std;


/********************affichage du plateau***********************/


void print_square(int x,int y, Plata pl[taille_plateau][taille_plateau]){
  cout<< pl[x][y].type;
}

void print_board(Plata pl[taille_plateau][taille_plateau]) {
  cout << "  a  b  c  d  e  f  g  h" << endl;
  for (int i = 0; i < taille_plateau; i++) {
    cout << taille_plateau - i << " ";
    for (int j = 0; j < taille_plateau; j++) {
      if(pl[i][j].type == 'V'){
        cout<<".  ";
      }
      else {
        cout<<pl[i][j].type<<"  ";
      }
    }
    cout << taille_plateau - i << endl;
  }
  cout << "  a  b  c  d  e  f  g  h" << endl;
}

void print_symbol(char t) {
      switch (t) {
      case 'P':
        cout << "\u2659 "; // pion blanc
        break;
      case 'T':
        cout << "\u2656 "; // tour blanche
        break;
      case 'C':
        cout << "\u2658 "; // cavalier blanc
        break;
      case 'F':
        cout << "\u2657 "; // fou blanc
        break;
      case 'D':
        cout << "\u2655 "; // reine blanche
        break;
      case 'R':
        cout << "\u2654 "; // roi blanc
        break;
      case 'p':
        cout << "\u265F "; // pion noir
        break;
      case 't':
        cout << "\u265C "; // tour noire
        break;
      case 'c':
        cout << "\u265E "; // cavalier noir
        break;
      case 'f':
        cout << "\u265D "; // fou noir
        break;
      case 'd':
        cout << "\u265B "; // reine noire
        break;
      case 'r':
        cout << "\u265A "; // roi noir
        break;
      case 'V':
        cout << "  ";
        break;
      
      }

}

/*  fonction qui permet d'afficher les couleurs et les symboles des pieces*/
void print_square_color(Plata pl[taille_plateau][taille_plateau],
int mask[taille_plateau][taille_plateau]) {
  // Affichage des lettres pour identifier les colonnes
  
  cout << "    ";
  for (int col = 0; col < 8; col++) {
    cout << " " << char('a' + col) << "  ";
  }
  cout << endl;
  for (int i = 0; i < 8; i++) {
    // Affichage des chiffres pour identifier les lignes
    cout << " " << 8 - i << "  ";
    for (int j = 0; j < 8; j++) {
      set_background((i + j) % 2);

      //set_foreground(pl[i][j].type);
     // if(mask[i][j] == 1) cout<< "\x1b[44m";
      cout << "  ";
      print_symbol(pl[i][j].type);
    }
    cout << "\033[0m"; // reset de la couleur
    cout << " " << 8 - i << endl;
  }
  // Affichage des lettres pour identifier les colonnes
  cout << "    ";
  for (int col = 0; col < 8; col++) {
    cout << " " << char('a' + col) << "  ";
  }

  cout << endl;
}

  
/* fonction qui s'occupe de la couleur de fond d'une case*/
void set_background( int color) {
  
  switch (color) {
    case 0:     cout << "\x1b[48;5;208m";  break;
    case 1:     cout << "\x1b[48;5;3m";  break;
    case 2:     cout << "\x1b[44m";  break;
    case 3:     cout << "\x1b[50m";  break;
    case 4:     cout << "\x1b[51m";  break;
    case 5:     cout << "\x1b[52m";  break;
    case 6:     cout << "\x1b[53m";  break;
    case 7:     cout << "\x1b[54m";  break;
  }
  
  /*
  //int mask[taille_plateau][taille_plateau];
  if ((i + j) % 2 == 0) {
    cout << "\x1b[48;5;205m";// fond rose
  } 
  
  else {
    cout << "\x1b[48;5;225m"; // rouge
  }
  */
}

/*fonction qui affiche la piece */
void set_foreground(bool color) {
  if (color == 1) {
    cout << "\x1b[38;5;m"; // piece blanc color blanche
  } else {
    cout << "\x1b[38;5;0m"; // piece noir color blanc grise
  }
}
//\x1b[38;5;30m

/***affichage d'une case du masque*********/

void print_square(int x, int y, int mask [taille_plateau][taille_plateau]) {
  cout<< mask[x][y];
}

/******************** affichage du masque*************/
/*void print_board(int mask [taille_plateau][taille_plateau]) {
  for (int i = 0; i < taille_plateau; i++) {
    for (int j = 0; j < taille_plateau; j++) {
      cout << mask[i][j];
      if (j == 7)
        cout << endl;
    }
  }
}*/
void print_board(Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]) {
  //cout << "  a  b  c  d  e  f  g  h" << endl;
  cout << "    ";
  for (int col = 0; col < 8; col++) {
    cout << " " << char('a' + col) << "  ";
  }
  cout << endl;
  for (int i = 0; i < taille_plateau; i++) {
    cout << taille_plateau - i << " ";
    for (int j = 0; j < taille_plateau; j++) {
      if(mask[i][j] == 0 ) {
      set_background( (i+j) % 2);
      }
      else{
        set_background(mask[i][j]+1);
      }
      if(pl[i][j].type == 'V'){
        cout<<".  ";
      }
      else {
        cout<<pl[i][j].type<<"  ";
      }
    }  cout << "\033[0m"; // reset de la couleur
    cout << " " << 8 - i << endl;     
    //cout << taille_plateau - i << endl;
  }
  cout << "    ";
  for (int col = 0; col < 8; col++) {
    cout << " " << char('a' + col) << "  ";
  }

  cout << endl;
  //cout << "  a  b  c  d  e  f  g  h" << endl;
}