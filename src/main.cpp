#include <iostream>
#include "book_roster.h"
// using namespace ctch1330;
using namespace ctch1330;

int main()
{

	class Books {
  public:
    string name;   
    string author;
    int year;
};



	std::cout << endl << "Welomce to the public Ohio University Library" << endl << std::endl;
	
	while (true)
	{
	/*	class Books {
  public:
    std::string name;   
    std::string author;
    int year;
  private
    int barcode;
     };


  Books book1;
  book1.name = "How to drain your ice cream";
  book1.author = "Tommy W.";
  book1.year = 1999;

 Books book2;
string book2.name = "What is sleep?";
string book2.author = "Inso M. Nia";
  int book2.year = 2023;
  Books book3; 
  Books book4; 
  Books book5;
   string book3.name = "What is sleep?";
 string book4.name = "What is sleep?";
  string book5.name = "What is sleep?";

vector<string> menu = 
{ 
    book1.name, 
    book2.name, 
    book3.name, 
    book4.name, 
    book5.name	
};*/
class Full_name {
  public:
    string First = "Charleston";
    void line() {
      cout << "Welcome" ;
    }
};
// Derived class
class Name: public Full_name {
  public:
    string last_name = "Thomas";
};

  Name name;
  name.line();
 string last_name = name.last_name;
 
 string First = name.First;
 
  First = last_name;
  last_name = "Charleston";




  std::cout << endl <<  First + " " + last_name << endl << std::endl;






		int user_selection = 0;
		 
			//std::cout << endl << menu << endl << std::endl;

		vector<string> menu;

		try
		{
			menu = ctch1330::menu;
			RenderMainMenu(menu);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
			continue;
		}		
		
		try
		{
			user_selection = GetUserSelection(menu.size());
		}
		catch(const runtime_error& e)
		{
			cerr << e.what() << endl;
			continue;
		}
		
		DispatchSelectedOperation(user_selection);
	}
		
	
	return 0;
}

