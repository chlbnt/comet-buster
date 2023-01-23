#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)  //création de la fonction d'initialisation, pas de parametre
{
  list_ptr list; //creation de list de type list_node
  list = NULL;   // initalisation de la liste à NULL
  return list;   // La fonction retourne list avec la valeure initialisée
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */

list_ptr list_add(sprite_t sprite, list_ptr list)  
// Fonction qui permet de creer 
// des cellules et les ajouter à la list
{
  list_ptr nouvellecellule; //creation de la variable nouvellecellule de type list_node
  nouvellecellule=malloc(sizeof(s_list_node_t)); //allocation de la memoire (allocation de la taille du struct)
  nouvellecellule->data=sprite; //sprite dans data
  nouvellecellule->next=list;   // on pointe vers la list existante
  
  return nouvellecellule;   // on retourne donc data et next (ou sprite et et list)
  
}


/* Return the length of a list
 * */
int list_length(list_ptr l) // fonction qui retourne la longueur de la liste
{
  int i = 0;
  while(l->next!=NULL){ //tant que next est différent de null faire l = next et compter i +1
    l=l->next;
    i=i+1;
  }
  return i;
}

/* Reverse the order of a list
 * 
void list_reverse(list_ptr * l)
{

}
*/

/* Copy a list to another one. 
 *  Return the new list
 *
list_ptr list_clone(list_ptr list)
{
  return NULL;
}
 */

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  if (l==NULL){
    return true;
  }
  else {
    return false;
 }
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{

  if (l!=NULL){  //protection dans le cas ou la premiere cel est vide
    return l->data;  // retourne data
  }
  else { 
    return NULL;  // sinon on retourne null
  }
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  if(l==NULL){ // protection (du segfault) si la liste est vide
	return NULL;
  }
  else {
    return l->next; // on retourne la prochaine cellule
  }
}


/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
	sprite_t data=NULL;
	list_ptr tmp=*l;
	list_ptr last=NULL;
	if(tmp!=NULL){
	  while(tmp->next->next!=NULL){ // on fait 2 fois next pour eviter d'etre à la derniere cellule
                                  // étant donné qu'on ne pourra pas faire précédent pour supprimer le dernier next
        tmp=tmp->next; // passage au suivant
      }
      last=tmp->next;
      data=last->data;
      tmp->next=NULL;
      return data;
  }	
  return NULL;
}


/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
	list_ptr tmp;
    list_ptr tmp2;
    tmp=*l; //tmp = cellule actuelle
    tmp2=tmp->next; // tmp2 = cellule d'après
    if(tmp==elt){ // si parametre d'entré = cellule actuelle
        *l=tmp->next; // on écrase la cellule actuelle par la cellule d'apres
    }
    else{
        while(tmp->next!=elt){   // tant que cellule suivante différent du parametre d'entré
            tmp=tmp->next;  // avancer cellule acutelle de 1
            tmp2=tmp2->next; // avance cellule suivante de 1
        }
        tmp->next=tmp2->next; //écraser la cellule actuelle par la suivante.
    }
}
/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)

{
  list_ptr suppr=l; //liste dans suppr
  list_ptr suivant; 
  while(suppr!=NULL){
	  suivant = suppr->next; // on passe à la cellule suivante
      sprite_free(suppr->data); // on libere la mémoire de data (sprite) dans la liste
      free(suppr); // on libere la memoire de la liste
}
}