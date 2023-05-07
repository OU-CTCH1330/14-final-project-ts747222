#include "book_roster.h"

using namespace ctch1330;

void inty(){
    class Books {
  public:
    string name;   
    string author;
    int year;
     };


  Books book1;
  book1.name = "How to drain your ice cream";
  book1.author = "Tommy W.";
  book1.year = 1999;

 Books book2;
  book2.name = "What is sleep?";
  book2.author = "Inso M. Nia";
  book2.year = 2023;
  Books book3, book4, book5;
    book3.name = "What is sleep?";
  book4.name = "What is sleep?";
  book5.name = "What is sleep?";

vector<string> roster = 
{ 
    book1.name, 
    book2.name, 
    book3.name, 
    book4.name, 
    book5.name	
};
}