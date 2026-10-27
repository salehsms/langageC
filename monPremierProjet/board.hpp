#ifndef board_hpp__
#define board_hpp__

#include"types.hpp"

/***********************Entete des fonctions*********************/

/******* fonction permettant de vider**************************/
void empty(Plata plateau[taille_plateau][taille_plateau]);


/************ recuperation du contenu d'une case ***************/
Plata get_square(int lig, int col,Plata plateau[taille_plateau][taille_plateau]);


/********** fonction qui permet de modifier le contenu d'une case *******/
void set_square(int lig, int col, Plata p);


/************la fonction qui permet d'initialiser le plateau***********/
void start(Plata plateau[taille_plateau][taille_plateau]);


/****************fonction qui verifie si le deplacement est posssible*********************/
void movie_piece(int depX, int depY, int arivX, int arivY,Plata plateau[taille_plateau][taille_plateau]);


/*** Une foction qui definie un l'etat du jeu*/
void write_FEN(Plata p[taille_plateau][taille_plateau], char *file_name);




void highlight_possible_moves(int lig, int col, Plata pl[taille_plateau][taille_plateau],int mask [taille_plateau][taille_plateau]);

void highlight_possible_moves_king(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) ;

void highlight_possible_moves_rook(int x, int y, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) ;


void highlight_possible_moves_bishop(int lig, int col, Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]);


void highlight_possible_moves_queen(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]);


void highlight_possible_moves_knight(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]);


void highlight_possible_moves_pawn(int lig, int col, Plata pl[taille_plateau][taille_plateau], int mask [taille_plateau][taille_plateau]) ;


//void highlight_movable_pieces(Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]);

void highlight_attacked_pieces(Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]) ;





#endif