#include"tree.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    TRNODE* parent;
    TRNODE* child;
       } PAIR;


static bool ToLeft(ITEM*pi1,ITEM*pi2);
static bool ToRight(ITEM*pi1,ITEM*pi2);
static PAIR SeekAll(TREE*ptree,ITEM*pi);
static TRNODE* MakeNode(ITEM*pi);
static void InOrder(TRNODE* root,void (*pfun)(ITEM item));
static bool DeleteNode(TRNODE**ppt);
static void DeleteAllNodes(TRNODE*root);
static void AddNode(TRNODE*root,ITEM*pi);

void Initialize(TREE*ptree)
{
 ptree->root=NULL;
 ptree->size=0;
}
bool TreeIsFull(TREE*ptree)
{
  return ptree->size==MAXSIZE;
}

bool TreeIsEmpty(TREE*ptree)
{
  return ptree->root==NULL;
}
bool AddItem(TREE*ptree,ITEM*pi)
{
  PAIR temp;
  if (TreeIsFull(ptree))
   {
    fprintf(stderr,"The tree is already full.\n");
    return false;
   }
  if (TreeIsEmpty(ptree))
     ptree->root=MakeNode(pi);
  else if ((temp=SeekAll(ptree,pi)).child!=NULL) 
       {
        strcpy(&(temp.child->item.petkind[temp.child->item.showed][0]),
         &(pi->petkind[0][0]));
        temp.child->item.showed++;
        }
  else if (temp.child==NULL)
    {
     AddNode(ptree->root,pi);
     ptree->size++;
     }
   else
     printf("HMM\n");
return true;
}      
  
bool DeleteItem(TREE*ptree,ITEM*pi) 
{
  int i;
  PAIR temp;
  if (TreeIsEmpty(ptree))
   {
    printf("No data.\n");
     return false;
   }
  else if (!InTree(ptree,pi))
   {
    printf("Target is not in tree.\n");
    return false;
    }
  else 
    {
      temp=SeekAll(ptree,pi);
    if (temp.child->item.showed==1)
     {     
      if (temp.parent==NULL)
        DeleteNode(&(ptree->root));
      else if (temp.parent->left==temp.child)
        DeleteNode(&(temp.parent->left));
      else if (temp.parent->right==temp.child)
        DeleteNode(&(temp.parent->right));
      else
        {
         printf("Error Deleting node.\n");
         return false;
        }
     ptree->size--;
      }
    else if (temp.child->item.showed>1)
     {
      for (i=0;i<(temp.child->item.showed);i++)
        if (strcmp(&(temp.child->item.petkind[i][0]),&(pi->petkind[0][0]))==0)
        break;
       while (i+1<(temp.child->item.showed))
         {
          strcpy(&(temp.child->item.petkind[i][0]),&(temp.child->item.petkind[i+1][0]));
          i++;  
         }
      temp.child->item.showed--;
      }
     else 
      printf("Grr\n");
    }
return true;
}

int CountTheTree(TREE*ptree)
{
  return ptree->size;
}

void Traverse(TREE*ptree,void (*pfun)(ITEM item))
{
  InOrder(ptree->root,pfun);
return;
}

void EmptyAll(TREE*ptree)
{
 DeleteAllNodes(ptree->root);
 ptree->root=NULL;
 ptree->size=0;
return;
}

static bool ToLeft(ITEM*pi1,ITEM*pi2)
{
 if (strcmp(pi1->petname,pi2->petname)<0)
    return true;
 else
   return false;
}

static bool ToRight(ITEM*pi1,ITEM*pi2)
{
 if (strcmp(pi1->petname,pi2->petname)>0)
    return true;
 else
   return false;
}

static PAIR SeekAll(TREE*ptree,ITEM*pi)
{
  PAIR look;
  look.parent=NULL;
  look.child=ptree->root;
   
while (look.child!=NULL)
 {
  if (ToLeft(pi,&(look.child->item)))
   {
    look.parent=look.child;
    look.child=look.child->left;
   }
  else if(ToRight(pi,&(look.child->item)))
   {
    look.parent=look.child;
    look.child=look.child->right;
   }
  else
   break;
  }
return look;
}

static TRNODE* MakeNode(ITEM*pi)
{
 TRNODE *new_node;
 new_node=(TRNODE*)malloc(sizeof(TRNODE));
 if (new_node==NULL)
 {
  fprintf(stderr,"Error allocating momorary.\n"); 
  exit(EXIT_FAILURE);
  }
 strcpy(new_node->item.petname,pi->petname);
 strcpy(new_node->item.petkind[0],pi->petkind[0]);
 new_node->item.showed=1;
 new_node->left=NULL;
 new_node->right=NULL;
return new_node;
}
static void InOrder(TRNODE* root,void (*pfun)(ITEM item))
{
  if (root!=NULL)
  {
   InOrder(root->left,pfun);
   pfun(root->item);
   InOrder(root->right,pfun);
  }
return;
}
   
static bool DeleteNode(TRNODE**ppt)
{
  if ((*ppt)==NULL)
    return false;

  TRNODE*temp;
  if ((*ppt)->left==NULL)
   {
    temp=*ppt;
    *ppt=(*ppt)->right;
    free(temp);
    }
  else if((*ppt)->right==NULL)
    {
     temp=*ppt;
     *ppt=(*ppt)->left;
     free(temp);
    }
  else
   {
    for(temp=(*ppt)->left;temp->right!=NULL;temp=temp->right);
    temp->right=(*ppt)->right;
    temp=(*ppt);
    *ppt=(*ppt)->left;
    free(temp);
    }
return true;
}
   
static void DeleteAllNodes(TRNODE*root)
{
   TRNODE* pright;
   if (root!=NULL)
    {
     pright=root->right;
     DeleteAllNodes(root->left);
     free(root);
     DeleteAllNodes(pright);
     }
return;
}

bool InTree(TREE*ptree,ITEM*pi)
{
  int i;
  PAIR temp;
  temp=SeekAll(ptree,pi);
  if (temp.child!=NULL)
    {
      for (i=0;i<temp.child->item.showed;i++)
       {
        if (strcmp(&(pi->petkind[0][0]),&(temp.child->item.petkind[i][0]))==0)
           return true;
       }
     return false;
    }  
  else 
   return false;
}

static void AddNode(TRNODE*root,ITEM*pi)
{ 
    if (ToLeft(pi,&(root->item)))
     {
      if (root->left==NULL)
        root->left=MakeNode(pi);
      else
        AddNode(root->left,pi);
      }
   else if (ToRight(pi,&(root->item)))
     {
      if (root->right==NULL)
        root->right=MakeNode(pi);
      else
        AddNode(root->right,pi);
      }
return;
}
