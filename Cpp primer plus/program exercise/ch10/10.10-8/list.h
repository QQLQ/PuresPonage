#ifndef _LIST_H
#define _LIST_H

const int NSIZE=20;
typedef struct{
     char name[NSIZE];
     int rank;
    }ITEM;
    
typedef struct Node{
   ITEM item;
   Node* next;
     }NODE;

class list{
   enum{MAXSIZE=5};
   NODE* start;
   int nums;
   void dnode(NODE*pn);
public:
   list(const ITEM& item);
   list();
   ~list();
   bool add(ITEM&item);
   bool isempty(void);
   bool isfull(void);
   void visit(void (*pf)(ITEM&));
};

#endif
