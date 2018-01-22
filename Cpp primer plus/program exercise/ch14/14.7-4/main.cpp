#include<iostream>
#include<string>
#include<cstring>
#include"person.h"

const int SIZE=4;

int main(void)
{
   using std::cout;
   using std::cin;
   using std::endl;
   using std::string;
   
  Gunslinger g1(0.3,22,"Fnn","Lnn");
  PokerPlayer p1("pf","pl");
  BadDude b1(0.52,98,"bFnn","bLnn");  
  
  g1.Show();
  g1.Draw();
  p1.Show();
  (p1.Draw()).Show();

  b1.Show();
  cout<<b1.Gdraw()<<endl;
  (b1.Cdraw()).Show();

  string fname,lname;
  int marks;
  double draw;
  char choice;
  Person* ar[SIZE];
  int i;
  for (i=0;i<SIZE;i++)
  {
   cout<<"Please enter the type (1:Person,2:Gunslinger,3:PokerPlayer,4:BadDude  q:quit):";
   cin>>choice;
   while (cin.get()!='\n');
   while (!std::strchr("1234q",choice))
   {
    cout<<"Invalid choice,enter again:";
    cin>>choice;
    while (cin.get()!='\n');
   }

   if (choice=='q')
      break;

   cout<<":Please enter the fname:";
   getline(cin,fname);
   cout<<"Please enter the lname:";
   getline(cin,lname);

   switch(choice)
   {
    case '1':ar[i]=new Person(fname,lname);break;
    case '2':cout<<"Please enter the draw:";
             cin>>draw;
             cout<<"Please enter the marks:";
             cin>>marks;
             ar[i]=new Gunslinger(draw,marks,fname,lname);
             break;
    case '3':ar[i]=new PokerPlayer(fname,lname);break;
    case '4':cout<<"Please enter the draw:";
             cin>>draw;
             cout<<"Please enter the marks:";
             cin>>marks;
             ar[i]=new BadDude(draw,marks,fname,lname);
             break;
    }
   }
   
  for (int x=0;x<i;x++)
     ar[x]->Show();
  
return 0;
}  
