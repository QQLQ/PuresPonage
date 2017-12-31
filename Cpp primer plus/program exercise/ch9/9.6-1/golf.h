const int LEN=40;
struct golf
{
 char fullname[LEN];
 int handicap;
};

int setgolf(golf & g);
void handicap(golf & g,int hc);
void showgolf(const golf & g);
