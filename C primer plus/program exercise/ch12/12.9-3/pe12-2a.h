#define M0 fuel*100/distance
#define M1 distance/fuel
#define MA0 "liters per 100km"
#define MA1 "miles per gallon"

int set_mode(int m,int *pprev);
void get_info(int mode,double *pdist,double *pfue);
void show_info(int mode,const double distance,const double fuel);
