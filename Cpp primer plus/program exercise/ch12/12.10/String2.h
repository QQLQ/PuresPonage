#ifndef STRING_H_2_
#define STRING_H_2_
#include<iostream>

class String{
  char *str;
  int len;
  static const int MSIZE=80;
public:
  String();
  String(const char*line);
  String(const String&t);
  ~String();
  String& operator=(const String&t);
  bool operator==(const String&t) const;
  String operator+(const String&t) const;
  String operator+(const char*line) const;
  void stringup(void);
  void stringlow(void);
  int has(char ch) const;
  friend std::ostream& operator<<(std::ostream& os,const String& t);
  friend std::istream& operator>>(std::istream& is,String& t);
  friend String operator+(const char*line,const String&t);
};
#endif
