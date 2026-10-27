#include "board.hpp"
#include "types.hpp"
#include "view.hpp"
#include"mask.hpp"

#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  Plata pl[taille_plateau][taille_plateau];
  int mask[taille_plateau][taille_plateau];

  start(pl);

  print_board(pl);
  
  
  
  empty_mask(mask);
  //print_board(pl);
  cout << endl;

  /** mouvement des 4 pieces*****/
  movie_piece(0, 0, 4, 4, pl);
  movie_piece(1, 6, 3, 6, pl);
  movie_piece(7, 3, 5, 5, pl);
  movie_piece(0,1, 3, 3, pl);

  /***Tester les Tours*/
  /*highlight_possible_moves(4,4,pl,mask); 
  print_board(pl,mask);*/

  /***Tester les Pions */
  /*highlight_possible_moves(3,6,pl,mask); 
  print_board(pl,mask);*/
  
  /*test pour le fou */
 /* highlight_possible_moves(5,0,pl,mask); 
  print_board(pl,mask);*/
  
   /*test pour le Cavalier*/
  /*highlight_possible_moves(3,3,pl,mask); 
  print_board(pl,mask);*/
  
  /*test pour la Dame*/
  /*highlight_possible_moves(5,5,pl,mask); 
  print_board(pl,mask);*/


  
 mask_choices(pl, mask); 
  
  
}