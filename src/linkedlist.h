#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <SDL.h>

#include "sprite.h"

typedef struct list_node {    // Déclaration d'une stucture de type liste_node. 
  sprite_t data;     // Sprite_t est le pointeur de la structure s_sprite_t 
                     // Cela permettra d'inserer des "data" dans la structure des sprites
  struct list_node * next;  // Pointeur vers la prochaine cellule du liste_node
} s_list_node_t, *list_ptr;  // Le nom de la structure est s_list_node_t et son pointeur *list_ptr

// Prototypes des fonctions de type list_node
list_ptr list_new(void);
list_ptr list_add(sprite_t v, list_ptr l);
//list_ptr list_clone(list_ptr l); non codé
//void list_reverse(list_ptr * l); non codé
list_ptr list_next(list_ptr l);
// Prototypes des fonctions de type sprite
sprite_t list_head_sprite(list_ptr l);
sprite_t list_pop_sprite(list_ptr *l);

// Permet de déclarer les prototypes des fonctions de linkedlist.c
// A noter quelles ont toutes en parametre le pointeur list_ptr
bool list_is_empty(list_ptr l);
int  list_length(list_ptr l);
void list_free(list_ptr l);
void list_remove(list_ptr elt, list_ptr *l);


#endif /* LINKEDLIST_H */
