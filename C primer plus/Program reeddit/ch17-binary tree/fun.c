#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"

typedef struct {
    TRNODE* parent;
    TRNODE* child;
       } PAIR;

void Initialize(TREE* ptree);
bool TreeIsFull(TREE* ptree);
bool TreeIsEmpty(TREE* ptree);
int CountTheTree(TREE* ptree);
bool AddItem(TREE* ptree,ITEM* pi);
bool InTree(TREE* ptree,ITEM* pi);
void Traverse(TREE* ptree,void (*pfun)(ITEM item));
bool DeleteItem(TREE* ptree,ITEM*pi);
void DeleteAll(TREE* ptree);

static bool ToLeft(ITEM *pi1,ITEM *pi2);
static bool ToRight(ITEM *pi1,ITEM *pi2);
static void InOrder(TRNODE*root,void(*pfun)(ITEM item));
static void DeleteNode(TRNODE**ppt);
static void DeleteAllNode(TRNODE*root);
static PAIR SeekAll(TREE*ptree,ITEM*pi);
static TRNODE* MakeNode(ITEM *pi);
static TRNODE* AddNode(TRNODE* new_node,TRNODE*root);

static bool ToLeft(ITEM *pi1,ITEM *pi2)
{
  int comp1;
 
  if ((comp1=strcmp(pi1->petname,pi2->petname))<0)
    return true;
  else if (comp1==0&&strcmp(pi1->petkind,pi2->petkind)<0)
    return true;
  else
    return false;
}
static bool ToRight(ITEM *pi1,ITEM *pi2)
{
  int comp1;

  if ((comp1=strcmp(pi1->petname,pi2->petname))>0)
    return true;
  else if (comp1==0&&strcmp(pi1->petkind,pi2->petkind)>0)
    return true;
  else
    return false;
}

static TRNODE* AddNode(TRNODE* new_node,TRNODE*root)
{
 bool a;
 if (a=ToLeft(&new_node->item,&(root->item)) )
   {
    if (root->left==NULL)
      root->left=new_node;
    else 
      AddNode(new_node,root->left);
    }
 else if (a=ToRight(&new_node->item,&(root->item)) )
   {
    if (root->right==NULL)
      root->right=new_node;
    else 
      AddNode(new_node,root->right);
    }
   else 
    {
     fprintf(stderr,"Error.\n");
     exit(1);
     }
}

static PAIR SeekAll(TREE*ptree,ITEM*pi)
{
  PAIR look;
  look.parent=NULL;
  look.child=ptree->root;

  while (look.child==NULL)
   return look;

  while (look.child!=NULL)
   {
    if (ToLeft(pi,&(look.child->item)))
       {
       look.parent=look.child;
       look.child=look.child->left;
       }
    else if (ToRight(pi,&(look.child->item)))
       {
       look.parent=look.child;
       look.child=look.child->right;
       }
    else 
       break;
   }
return look;
}

static void InOrder(TRNODE*root,void(*pfun)(ITEM item))
{
  if (root!=NULL)
   {
   InOrder(root->left,pfun);
   pfun(root->item);
   InOrder(root->right,pfun);  
  }
return;
}
   

static void DeleteNode(TRNODE**ppt)
{
 TRNODE* temp;
 if ( (*ppt)->left==NULL)
   {
     temp=(*ppt);
     (*ppt)=(*ppt)->right;
     free(temp);
   }
 else if ( (*ppt)->right==NULL)
   {
    temp=(*ppt)->left;
    (*ppt)=(*ppt)->left;
    free(temp);
   }
 else
   {
   for (temp=(*ppt)->left;temp->right!=NULL;temp=temp->right);
   temp=(*ppt)->right;
   temp=(*ppt);
   *ppt=(*ppt)->left;
   free(temp); 
   }
return;
}   

static void DeleteAllNode(TRNODE*root)
{
  TRNODE* pright;
  if (root!=NULL)
 {
    pright=root->right;
    DeleteAllNode(root->left);
    free(root);
    DeleteAllNode(pright);
 }
return;
}

static TRNODE* MakeNode(ITEM *pi)
{
 TRNODE* new_node;
 
 new_node=(TRNODE*)malloc(sizeof(TRNODE));
  if (new_node==NULL)  
   {
   fprintf(stderr,"Unable to allocate memory.\n");
   exit(EXIT_FAILURE);
   }
 else
  {
   new_node->item=(*pi);
   new_node->left=NULL;
   new_node->right=NULL;
  }
return new_node;
}

void Initialize(TREE* ptree)
{
   ptree->root=NULL;
   ptree->size=0;
return;
}
bool TreeIsFull(TREE* ptree)
{  
 return  ptree->size==MAXSIZE;
}
 
bool TreeIsEmpty(TREE* ptree)
{
   return ptree->root==NULL;
}
int CountTheTree(TREE* ptree)
{
  return ptree->size;
}

bool AddItem(TREE* ptree,ITEM* pi)
{
 TRNODE *new_node;
 if (true==TreeIsFull(ptree))
   {
    fprintf(stderr,"The tree is already full\n");
    return false;
   }
 if (SeekAll(ptree,pi).child!=NULL)
   {
    fprintf(stderr,"Error.Existed item is not allowed to add.\n");
    return false;
   }
  new_node=MakeNode(pi);
  if (new_node==NULL)
   {
   fprintf(stderr,"Counld not creat the node\n");
   return false;
   }

 if (ptree->root==NULL)
   ptree->root=new_node;
 else
    AddNode(new_node,ptree->root);
ptree->size++;
return true;
}

bool InTree(TREE*ptree,ITEM*pi)
{
  return SeekAll(ptree,pi).child==NULL?false:true;
}

void Traverse(TREE*ptree,void (*pfun)(ITEM item))
{
  InOrder(ptree->root,pfun);
return;
} 
    
bool DeleteItem(TREE* ptree,ITEM*pi)
{
  PAIR temp;
  if (true==TreeIsEmpty(ptree))
    { 
     printf("No date entered.\n");
     return false;
    }
  if ((temp=SeekAll(ptree,pi)).child==NULL)
   {
    printf("No such item.\n");
    return false;
   }
  if (temp.parent==NULL)
     DeleteNode(&(ptree->root));
  else if (temp.child==temp.parent->left)
     DeleteNode(&(temp.parent->left)); 
  else if (temp.child==temp.parent->right)
     DeleteNode(&(temp.parent->right));
  else 
    {
    fprintf(stderr,"Falied deletintg.\n");
    return false;
    }
  ptree->size--;
return true;
} 

void DeleteAll(TREE* ptree)
{
 DeleteAllNode(ptree->root);
 ptree->root=NULL;
 ptree->size=0;
return;
}
 
