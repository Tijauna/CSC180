#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 *  * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 *   * to that function.
 *    * 
 *     * Recap: if we want to use a function to modify a VARIABLE in the caller
 *      *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *       *
 *        * Similarly: if we want to use a function to modify a POINTER in the caller
 *         *            then the CALLER needs to send in the ADDRESS of the POINTER
 *          *
 *           * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 *            * nodes to be added to the linked list. Any dynamic creation of a node must be via
 *             * malloc.
 *              */

int ll_add_to_head( llnode **head, int val) {
llnode *old_head;

   if (head == NULL) {
      return -1;
   }
	old_head = *head;

if(*head == NULL){
*head = (llnode*)malloc(sizeof(llnode));
(*head) -> val = val;
(*head) ->next = NULL;
(*head)->prev = NULL;
return 0;

}

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
(*head)->prev = NULL;
(*head)->next->prev = *head;

return 0;
}

int ll_add_to_tail( llnode **head, int val) {   
llnode* current = NULL;

if (head == NULL) {
      return -1;
   
}

current = *head;

if(*head == NULL){

 *head = ( llnode *) malloc(sizeof( llnode));
(*head) -> val = val;
(*head) ->next = NULL;
(*head)->prev = NULL;
return 0;
}
else
{
while (current->next != NULL){
  current = current->next;  
 }
   
current->next = ( llnode *) malloc(sizeof( llnode));
      current->next->val = val;
     current->next->prev = current;
current->next->next = NULL;
      return 0;
 }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
  }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
       llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}


int ll_find_by_value(llnode *pList,int val){
  if (pList == NULL){
    return -1;
  }
  
  else{
    if (pList->val == val){
      return 0;
    }    
    return ll_find_by_value(pList->next, val);   
  }
}

int ll_del_from_tail(llnode **ppList){
llnode *current = NULL;
 
if (ppList == NULL){
return -1;
}


current = (*ppList);

while (current->next->next != NULL){
current = current->next;
}

current->next = NULL;
free (current->next);


return 0;
}

int ll_del_from_head(llnode **ppList){
llnode *current = NULL;

if(ppList ==NULL){
return -1;
}

current = (*ppList)->next;
current->prev = NULL;

free(*ppList);
*ppList = current;

return 0;
}

int ll_del_by_value(llnode **ppList,int val){

llnode *current = NULL;
llnode *todelete = NULL;
llnode *temp = NULL;

if(ppList == NULL){
return -1;
}

current = *ppList;

if ((*ppList)->val == val){
current = (*ppList)->next;
printf ("first value deleting");
free (*ppList);
*ppList = current;
(*ppList)->prev = NULL;
return 0;

}



while (current != NULL){


if (current->val == val){

printf("%d\n",current->val);

printf("Found a match!\n");

if (current->next == NULL){

todelete = current;
current = current ->prev;
current->next = NULL;

free(todelete);
return 0;

}

todelete = current;

current = current->prev;

current->next = current->next->next;

current->next->prev = current;


free(todelete);
return 0;
}

current = current->next;

}


return -1;
}


int ll_concat(llnode **pSrcA,llnode **pSrcB){

llnode *first = NULL;

first = *pSrcA;


if (pSrcA == NULL){
return -1;
}

if (pSrcB == NULL){
return -1;
}

if ((first->next) == NULL){
first->next = *pSrcB;
(*pSrcB)->prev = first;
}


else{
return ll_concat(&((*pSrcA)->next),pSrcB );
}

return 0;
}





int ll_sort(llnode **ppList){
 int swapped, i;
llnode *pointer1 = NULL;
llnode *other = NULL;

if (ppList == NULL){
return -1;
}

do{

swapped = 0;
pointer1 = *ppList;

while (pointer1->next != other)
{
if (pointer1->val > pointer1->next->val){

i = pointer1->val;
pointer1->val = pointer1->next->val;
pointer1->next->val = i;
swapped = 1;

}
pointer1 = pointer1->next;


}
other = pointer1;





}
while (swapped);

return 0;
}

int ll_insert_in_order(llnode **ppList,int val) {
   /* we are going to iterate through the linked list to find the
 *       insertion point; we will need to track the prior node so we
 *             can stitch in the new node properly
 *                   -> thus we will create two pointers to track the nodes
 *                            "curr" and "prev"
 *                               */
   llnode *curr = NULL;
llnode *temp = NULL;
int trigger = 0;

   if (ppList == NULL) { return -1; }
   if (*ppList == NULL) {
      /* if we're dealing with an empty linked list, just call
 *          add to head */
      return ll_add_to_head(ppList,val);
   }
   /* otherwise: we iterate through the list until will find the
 *       insert location */
   /* first we handle the degenerate case of the first node */
   if ((*ppList) -> val > val) {
      return ll_add_to_head(ppList,val);
   } 

else {
     
      curr = (*ppList);

      while(curr != NULL) {
         if (curr->val > val) {
trigger = 1;            
break;
         } else {

            curr = curr->next;
         }
      }

if (trigger == 0){

return ll_add_to_tail(ppList,val);
}

temp = curr;
curr = curr->prev;
 
curr->next = (llnode *) malloc(sizeof(llnode));
curr->next->val  = val;
curr->next->prev = curr;
curr->next->next = temp;

curr->next->next->prev = curr->next;     
      

return 0;
   }
}
