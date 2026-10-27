#ifndef mask_hpp__
#define mask_hpp__
/**Masque sans informaions */
void empty_mask(int mask [taille_plateau][taille_plateau]);

/**********reéinitialiser un masque aux valeurs 0****/
void clear_mask(int mask [taille_plateau][taille_plateau]);

/********lire le contenue d'une case de masque******/

int get_mask(int lig , int col,int mask [taille_plateau][taille_plateau]);

/*******modifier le contenu d'une case du masque***********/
void set_mask(int val, int lig, int col, int mask [taille_plateau][taille_plateau]);

void  mask_choices_menu();

void mask_choices(Plata pl[taille_plateau][taille_plateau],int mask[taille_plateau][taille_plateau]);
#endif
