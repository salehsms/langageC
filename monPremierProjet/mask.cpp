#include "types.hpp"
#include "mask.hpp"
#include "board.hpp"
#include "view.hpp"
#include <iostream>
using namespace std;

/********** creation du masque sans information*************/
/*void empty_mask(mask m[taille_plateau][taille_plateau]) {*/
void empty_mask(int mask[taille_plateau][taille_plateau]) {
  for (int i = 0; i < taille_plateau; i++) {
    for (int j = 0; j < taille_plateau; j++) {
      mask[i][j]= 0;
    }
  }
}

/**********reéinitialiser un masque aux valeurs 0****/
void clear_mask(int mask[taille_plateau][taille_plateau]){
  empty_mask(mask);
}

/********lire le contenue d'une case de masque******/
int get_mask(int lig, int col, int mask[taille_plateau][taille_plateau]) {
  return mask[lig][col];
}

/**********modifier le contenue d'une case*/
void set_mask(int val, int lig, int col, int mask [taille_plateau][taille_plateau]) {
  mask[lig][col] = val;
}
/**************menu a visualiser*********/
void  mask_choices_menu() {
  cout << "==== Masques disponibles ====" << endl;
  cout << "1. Masque des pieces pouvant se deplacer" << endl;
  cout << "2. Masque des pieces pouvant etre prises" << endl;
  cout << "3. Quitter" << endl;
  cout << "=============================" << endl;
}

void mask_choices(Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]) {
  int choice = 0;

  while (choice != 4) {
    mask_choices_menu();
    cout << "Choisissez un masque `a visualiser : ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "==== Masque des pi`eces pouvant se deplacer ====" << endl;
      //highlight_movable_pieces(pl, mask);
      print_board(pl, mask);
      cout << "==============================================" << endl;
      break;
    case 2:
      cout << "==== Masque des pi`eces pouvant ˆetre prises ====" << endl;
      highlight_attacked_pieces(pl, mask);
      print_board(pl, mask);
      cout << "================================================" << endl;
      break;

    case 3:
      cout << "Au revoir !" << endl;
      break;
    default:
      cout << "Choix invalide. Veuillez reessayer." << endl;
      break;
    }
  }
}

