#include<iostream>
#include"tv.h"

int main()
{
  using std::cout;
  Tv s42;
  cout<<"Initial settins for 42\" TV:\n";
  s42.settings();
  s42.onoff();
  s42.chanup();
  cout<<"\nAdjusted settings for 42\" TV:\n";
  s42.settings();
  
  Remote grey;
  
  grey.set_chan(s42,10);
  grey.volup(s42);
  grey.volup(s42);
  cout<<"\n42\" settings after using remote:\n";
  s42.settings();
  grey.showstatus();
  s42.switch_status(grey);
  grey.showstatus();
  
  Tv s58(Tv::On);
  s58.set_mode();
  grey.set_chan(s58,28);
  cout<<"\n58\" settins:\n";
  s58.settings();
  return 0;
}
