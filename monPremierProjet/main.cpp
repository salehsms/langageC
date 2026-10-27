#include "board.hpp"
#include "types.hpp"
#include "view.hpp"
#include "mask.hpp"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  Plata pl[taille_plateau][taille_plateau];
  int mask[taille_plateau][taille_plateau];

  start(pl);

  //print_board(pl);
  
  print_square_color(pl,mask);
  
  //empty_mask(mask);
  //print_board(pl);
  cout << endl;

  /** mouvement des 4 pieces*****/
  movie_piece(0, 1, 2, 2, pl);
  movie_piece(1, 6, 3, 6, pl);
  movie_piece(7, 2, 5, 0, pl);
  movie_piece(6, 1, 4, 1, pl);

  /*for(int i = 0 ;i < taille_plateau; i++){
    for(int j = 0 ;j < taille_plateau;j++){
      set_mask(i,i,j,mask);
    }
  }*/

  //print_board(mask);
 //print_board(pl);
  
  
}