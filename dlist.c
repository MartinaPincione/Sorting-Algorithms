#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void initList(DList* list)
{
   list->head = list->tail = NULL;
   list->len = 0;
}
void freeList(DList* list)
{
  ILNode* node = list->head;
  if (node == NULL){
      return;
  }
  else{
      list->head = node->next;
      freeList(list);
      free(node);
  }
}

void pushBackList(DList* list, int number)
{
    ILNode* new_node = (ILNode*)malloc(sizeof(ILNode));
    new_node->number= number;
    new_node->next = NULL;

    if (list->head == NULL){
        list->head = new_node;
    }
    else{
        list->tail->next = new_node;
    }
    new_node->prev = list->tail;
    list->tail = new_node;

    list->len++;
}

int popBackList(DList* list)
{
  assert(list->head && list->tail && list->len > 0);
  ILNode* to_pop = list->tail;
  int pop_val = to_pop->number;

  if (list->len == 1){
      list->head = NULL;
  }
  else{
      list->tail->prev->next = NULL;
  }
  list->tail = list->tail->prev;

  free(to_pop);
  list->len--;
  return pop_val;
}

void pushFrontList(DList* list, int number)
{
  ILNode* new_node = (ILNode*)malloc(sizeof(ILNode));
  new_node->number = number;
  new_node->prev = NULL;

  if (list->head == NULL){
      list->tail = new_node;
  }
  else{
      list->head->prev = new_node;
  }
  new_node->next = list->head;
  list->head = new_node;

  list->len++;
}
int popFrontList(DList* list)
{
  assert(list->head && list->tail && list->len > 0);
  ILNode* to_pop = list->head;
  int pop_val = to_pop->number;

  if (list->len ==1){
      list->tail = NULL;
  }
  else{
      list->head->next->prev = NULL;
  }
  list->head = list->head->next;

  list->len--;
  free(to_pop);
  return pop_val;
}

void sortedInsert(DList* sortedList, ILNode* nodeToInsert){
    sortedList->len++;
    nodeToInsert->prev = nodeToInsert->next = NULL;
    if (sortedList->head == NULL){
        sortedList->head = sortedList->tail = nodeToInsert;
    }
    else if (nodeToInsert->number <= sortedList->head->number){
        nodeToInsert->next = sortedList->head;
        sortedList->head->prev = nodeToInsert;
        sortedList->head = nodeToInsert;
    }
    else if (nodeToInsert->number >= sortedList->tail->number){
        nodeToInsert->prev = sortedList->tail;
        sortedList->tail->next = nodeToInsert;
        sortedList->tail = nodeToInsert;
    }
    else{ 
        ILNode* cur_node = sortedList->head;
        ILNode* prev_node = NULL;
        while (cur_node->number < nodeToInsert->number){ 
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        nodeToInsert->prev = prev_node;
        prev_node->next = nodeToInsert;
        cur_node->prev = nodeToInsert;
        nodeToInsert->next = cur_node;
    }
}

void sortList(DList* list)
{
  DList newList = {NULL, NULL};
  
  ILNode* next_node = NULL;
  ILNode* cur_node = list->head;
  while(cur_node){
    next_node = cur_node->next;
    sortedInsert(&newList, cur_node); //passing the address of the newList
    cur_node = next_node;
  }
  *list = newList; //the value of DList* list is updated to newList by dereferencing *list
}



int lengthList(DList* list)
{
  return list->len;
}
void printList(DList* list)
{
   printf("(");
   ILNode* node = list->head;
   while (node) {
      printf("%d ", node->number);
      node = node->next;
   }
   printf(")\n");
}
