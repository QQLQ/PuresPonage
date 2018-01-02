#ifndef _STACK_H
#define _STACK_H

const int FSIZE=35;

typedef struct customer{
 char fullname[FSIZE];
 double payment;
  } Item;


class Stack{
private:
  enum{ISIZE=5};
  Item m_items[ISIZE];
  int m_tops;
public:
  Stack();
  Stack(const Item*ar,int n);
  bool IsEmpty();
  bool IsFull();
  bool Push(const Item&);
  bool Pop(Item&item);
 };
 
#endif
