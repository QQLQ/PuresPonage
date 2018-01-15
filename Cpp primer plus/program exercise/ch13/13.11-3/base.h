#ifndef DMA_H_
#define DMA_H_

#include<iostream>

class base  //abstract base class;
{
private:
 char *label;
 int rating;
public:
 base(const char* l="null",int r=0);
 base(const base& rs);
 virtual ~base();
 base& operator=(const base& rs);
 friend std::ostream& operator<<(std::ostream& os, const base& rs);
 virtual void view()=0;  //pure virtual function; 
};

class baseDMA:public base
{
public:
baseDMA(const char* l="null",int r=0);
baseDMA(const baseDMA& rs);
virtual void view();
};

class lacksDMA:public base
{
private:
  enum{COL_LEN=40};
  char color[COL_LEN];

public:
  lacksDMA(const char* c="black",const char* l="null",
    int r=0);
  lacksDMA(const char* c,const lacksDMA &rs);
  friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
virtual void view();
};

class hasDMA:public base
{
private:
  char *style;
public:
  hasDMA(const char* s="none",const char* l= "null",int r=0);
  hasDMA(const char*s,const hasDMA & rs);
  hasDMA(const hasDMA& hs);
  ~hasDMA();
  hasDMA& operator=(const hasDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
  void view();
};

#endif
