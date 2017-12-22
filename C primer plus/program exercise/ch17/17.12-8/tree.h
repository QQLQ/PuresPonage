#ifndef _TREE_H
#define _TREE_H

#define CSIZE 31
#define MAXSIZE 235

#include<stdbool.h>


typedef struct{
   char petname[CSIZE];
   char petkind[11][CSIZE];
   int showed;
      }ITEM;

typedef struct trnode {
   ITEM item;
   struct trnode*left;
   struct trnode*right;
      } TRNODE;

typedef struct {
    TRNODE* root;
    int size;
      }TREE;

void Initialize(TREE*ptree);
bool TreeIsFull(TREE*ptree);
bool TreeIsEmpty(TREE*ptree);
bool AddItem(TREE*ptree,ITEM*pi);
bool DeleteItem(TREE*ptree,ITEM*pi);
int CountTheTree(TREE*ptree);
void Traverse(TREE*ptree,void (*pfun)(ITEM item));
void EmptyAll(TREE*ptree);
bool InTree(TREE*ptree,ITEM*pi);

#endif
