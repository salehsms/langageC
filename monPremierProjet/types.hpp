#ifndef types_hpp__
#define types_hpp__

const int taille_plateau = 8;

  

// structure pieces
struct Plata {
  char type; /*****/
  bool couleur;
};

//Plata plateau[taille_plateau][taille_plateau]; // tableau statique du plateau

const char case_vide = 'V'; // representation de la case vide;


struct Piece_prise{
  char type;
  bool couleur;
  Piece_prise * next;
}; 

struct Game{
  Plata plateau[taille_plateau][taille_plateau];
  int mask[taille_plateau][taille_plateau];
  bool joueur;
  Piece_prise *piece_prise_blanc;
  Piece_prise *piece_prise_noir;


};



#endif 