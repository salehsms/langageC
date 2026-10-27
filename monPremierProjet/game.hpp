#ifndef game_hpp__
#define game_hpp__

#include"types.hpp"
#include<iostream>
#include <string>



int transform_col(std :: string ecri);

int transform_lig(std :: string ecris);

bool test_premier_position(char col);

bool test_seconde_position(char lig);

bool choose_mouvement_humam(Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]);

void one_run_human( Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]);


#endif