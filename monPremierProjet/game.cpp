#include "game.hpp"
#include "board.hpp"
#include "view.hpp"
#include "types.hpp"
#include <iostream>
#include <string>
using namespace std;



/*******fonction permettant de transformation les string en col*****/
int transform_col(std :: string ecri){
    char col = ecri.at(0);
    switch(col) {
        case 'a' :
        return 0;
        case 'b' :
        return 1;
        case 'c' :
        return 2;
        case 'd' :
        return 3;
        case 'e' :
        return 4;
        case 'f' :
        return 5;
        case 'g' :
        return 6;
        case 'h' :
        return 7;
    }
    return 0;
}

/*/********fonction permettant de transformation des string en lignes **********/
int transform_lig(std :: string ecris){
    char retour_ligne ;
    char lig = ecris.at(1);
    switch(lig) {
        case '8' :
        retour_ligne =  7;
        case '7' :
        retour_ligne =  6;
        case '6' :
        retour_ligne =  5;
        case '5' :
        retour_ligne =  4;
        case '4' :
        retour_ligne =  3;
        case '3' :
        retour_ligne =  2;
        case '2' :
        retour_ligne =  1;
        case '1' :
        retour_ligne =  0;
    }
    return retour_ligne;
}

bool test_premier_position(char col){
    switch(col) {
        case 'a' :
        return true;
        case 'b' :
        return true;
        case 'c' :
        return true;
        case 'd' :
        return true;
        case 'e' :
        return true;
        case 'f' :
        return true;
        case 'g' :
        return true;
        case 'h' :
        return true;
    }
    return false;
}

bool test_seconde_position(char lig){
    switch(lig) {
        case '8' :
        return true;
        case '7' :
        return true;
        case '6' :
        return true;
        case '5' :
        return true;
        case '4' :
        return true;
        case '3' :
        return true;
        case '2' :
        return true;
        case '1' :
        return true;
    }
    return false;
}

/*********fonction permettant de savoir les mouvement********/
bool choose_mouvement_humam(Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]){

    /// mouvement concernant le depart 
    string dep;

    cout << "Ecrivez  le nom de la piece a utilisé ";
    cin >> dep;
    while (dep.length() > 2 ){
        cout <<  "Erreur ,ressayez ! ";
        cin >>  dep;
    }
    // test les caracteres
    while (!test_premier_position(dep.at(0))){
        cout << "la saisie n'est pa correct ,Essayé a nouveau ";
        cin >> dep;
    }
    
    while (!test_premier_position(dep.at(1))){
        cout << "la saisie n'est pa correct ,Essayé a nouveau ";
        cin >> dep;
    }

    // apres avoir fait la bonne saisie

    int col__dep = transform_col(dep);
    int row__dep = transform_lig(dep);
    
    cout << col__dep << " "<< row__dep << endl;

    while(pl[row__dep][col__dep].type = '-'){
        cout << "Reprenez la saisie ";
        cin >> dep;
        col__dep =  transform_col(dep);
        row__dep = transform_lig(dep);
    }

    /// mouvement concernant l'arrivée

    string ariv;

    cout << "Ecrivez  le nom de la piece a utilisé ";
    cin >> ariv;
    while (ariv.length() > 2 ){
        cout <<  "Erreur ,ressayez ! ";
        cin >>  ariv;
    }
    // test les caracteres
    while (!test_premier_position(ariv.at(0))){
        cout << "la saisie n'est pa correct ,Essayé a nouveau ";
        cin >> dep;
    }
    
    while (!test_premier_position(ariv.at(1))){
        cout << "la saisie n'est pa correct ,Essayé a nouveau ";
        cin >> dep;
    }

    int col__ariv = transform_col(ariv);
    int row__ariv = transform_lig(ariv);

    // voir les masques en fonctions des coordonnées

    highlight_possible_moves(row__dep,col__dep,pl,mask);
    print_board(pl,mask);
    if (mask[row__ariv][col__ariv] == 1){
        movie_piece(row__dep,col__dep,row__ariv,col__ariv,pl);
        print_square_color(pl,mask);
        return true;
    }
    return false;


}

/****fonction permettant de faire jouer l'humain********/
void one_run_human( Plata pl[taille_plateau][taille_plateau], int mask[taille_plateau][taille_plateau]){

    choose_mouvement_humam(pl,mask);
    



    
}