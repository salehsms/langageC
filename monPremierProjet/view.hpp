#ifndef view_hpp__
#define view_hpp__


void print_board(Plata pl[taille_plateau][taille_plateau]) ;

void print_square_color(Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]);

void set_background( int color) ;
void set_foreground(bool color) ;

void print_square(int x,int y, Plata pl[taille_plateau][taille_plateau]);

void print_board(Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]) ;

void print_symbol(char t);


#endif