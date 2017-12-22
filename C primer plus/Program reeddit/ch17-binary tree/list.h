#ifndef _LIST_H
#define _LIST_H

#include<stdbool.h>

#define MAXSIZE 20
#define NSIZE 21

typedef struct {
    char petname[NSIZE];
    char petkind[NSIZE];
       } ITEM;

typedef struct trnode{
     ITEM item;
     struct trnode* left;
     struct trnode* right;
     } TRNODE;

typedef struct {
    TRNODE* root;
    int size;
     } TREE;

void Initialize(TREE* ptree);
bool TreeIsFull(TREE* ptree);
bool TreeIsEmpty(TREE* ptree);
int CountTheTree(TREE* ptree);
bool AddItem(TREE* ptree,ITEM* pi);
bool InTree(TREE* ptree,ITEM* pi);
void Traverse(TREE* ptree,void (*pfun)(ITEM item));
bool DeleteItem(TREE* ptree,ITEM*pi);
void DeleteAll(TREE* ptree);


#endif
