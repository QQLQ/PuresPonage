// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<memory>
#include<string>

using std::shared_ptr;

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worsethan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool cheaperthan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(Review & rr);
void ShowReview(const shared_ptr<Review>& rr);
int main()
{
    using namespace std;

    vector<shared_ptr<Review> > books;
    Review temp;
    while (FillReview(temp))
        books.push_back(shared_ptr<Review>(new Review(temp)));
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
              << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

       vector<shared_ptr<Review> > temp=books;

       char choice;
      
       cout<<"Now please select displayed mode:"<<endl<< 
       ">>a.)sorted by input order\n"
       ">>b.)sorted by title\n"
       ">>c.)sorted by rating(from low to high)\n"
       ">>d.)sorted by rating(from high to low)\n"
       ">>e.)sorted by price(from low to high)\n"
       ">>f.)sorted by price(from high to low)\n"
       ">>q.)quit\n";
       cout<<"Please enter your choice now:";
       string choice_list("abcdefq");
       while (cin>>choice)
       {
        while (getchar()!='\n');
        if (string::npos==choice_list.find(choice))
         {
          cout<<choice<<" is not an option,please reenter:";
          continue;
         }
         
        switch(choice)
        {
        case 'a':
        cout<<"sorted by input order:\nRating\tPrice\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);break;
        case 'b':
        sort(temp.begin(),temp.end());
        cout<<"sorted by title:\nRating\tPrice\tBook\n";
        for_each(temp.begin(), temp.end(), ShowReview);break;
        case 'c':
        sort(temp.begin(),temp.end(),worsethan);
        cout<<"sorted by rating(from low to high):\nRating\tPrice\tBook\n";
        for_each(temp.begin(), temp.end(), ShowReview);break;
        case 'd':
        sort(temp.rbegin(),temp.rend(),worsethan);
        cout<<"sorted by rating(from high to low):\nRating\tPrice\tBook\n";
        for_each(temp.begin(), temp.end(), ShowReview);break;
        case 'e':
        sort(temp.begin(),temp.end(),cheaperthan);
        cout<<"sorted by price(from low to high):\nRating\tPrice\tBook\n";
        for_each(temp.begin(), temp.end(), ShowReview);break;
        case 'f':
        sort(temp.rbegin(),temp.rend(),cheaperthan);
        cout<<"sorted by price(from high to low):\nRating\tPrice\tBook\n";
        for_each(temp.begin(), temp.end(), ShowReview);break;
        case 'q':break;
        }
        if (choice=='q')
         break;
        cout<<"Please enter your next choice:";
         continue;
        }
      }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->price < r2->price)
        return true;
    else if (r1->price == r2->price && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worsethan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool cheaperthan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    std::cout<<"Enter book price: ";
    std::cin>>rr.price;
    if(!std::cin)
        return false;
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review>& rr)
{
    std::cout << rr->rating << "\t" << rr->price << "\t" << rr->title << std::endl; 
}
