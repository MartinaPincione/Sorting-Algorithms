#ifndef __DLIST_H
#define __DLIST_H
#include <stdlib.h>

typedef struct ILNode{
  struct ILNode* next;
  struct ILNode* prev;
  int number;
} ILNode;

typedef struct DList{
  ILNode* head;
  ILNode* tail;
  size_t len;
} DList;

void initList(DList* list);
void freeList(DList* list);

void pushBackList(DList* list, int number);
int popBackList(DList* list);
void pushFrontList(DList* list, int number);
int popFrontList(DList* list);

void sortList(DList* list);
int lengthList(DList* list);
void printList(DList* list);

#endif
