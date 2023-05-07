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
Books book1;
  book1.name = "How to drain your ice cream";
  book1.author = "Tommy W.";
  book1.year = 1999;
 Books book2;
  book2.name = "What is sleep?";
  book2.author = "Inso M. Nia";
  book2.year = 2023;


	std::cout << endl << "Welomce to the public Ohio University Library" << endl << std::endl;
	
	while (true)
	{
		int user_selection = 0;
		vector<string> menu;

		try
		{
			menu = GetMenuFromDatabase();
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

