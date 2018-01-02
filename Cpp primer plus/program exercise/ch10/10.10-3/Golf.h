#ifndef _Golf_h
#define _Golf_h

class Golf{
private:
 const static int LEN=40;
 char fullname[LEN];
 int handicap;
public:
 Golf(const char*fn,int hc);
 Golf();
 void Setgolf(void);
 void Handicap(int hc);
 void Showgolf(void) const;
};

#endif
