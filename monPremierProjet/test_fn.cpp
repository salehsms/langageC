#include<iostream>
#include"types.hpp"
#include "board.hpp"
#include"view.cpp"
using namespace std;
int main(int argc, char *argv[]){
    Plata pl[taille_plateau][taille_plateau];
  start(pl);
  print_board(pl);
  cout << endl;

  /** mouvement des 4 pieces*****/
  movie_piece(0, 1, 2, 2, pl);
  movie_piece(1, 6, 3, 6, pl);
  movie_piece(7, 2, 5, 0, pl);
  movie_piece(6, 1, 4, 1, pl);

  print_board(pl);
  

    char filename[256] = "FEN_007.txt";

    write_FEN(pl, filename);

}