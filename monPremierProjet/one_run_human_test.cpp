#include "board.hpp"
#include "types.hpp"
#include "view.hpp"
#include "mask.hpp"
#include "game.hpp"
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

  one_run_human(pl,mask);

  

}