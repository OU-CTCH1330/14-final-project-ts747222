#include <iostream>
#include <limits>
#include <tuple>
#include "book_roster.h"
namespace ctch1330
{
	void RenderMainMenu(vector<string> menu) 
	{	
		
		
		cout << endl << "Main menu:" << endl << endl;

		for (string menu_item : menu)
		{
			cout << menu_item << endl;
		}


		return;
	}




	void DisplayRoster(vector<string> roster)
	{
		int roster_size = roster.size();

		cout << endl << "Book roster:" << endl << endl;

		for (int i = 0; i < roster_size; i++)
		{
			cout << i+1 << ". " << roster[i] << endl;
		}
		WaitForUser();	
		return;
	}

	vector<string> AddBook(vector<string> roster, int max_book_size)
	{
		if ( max_book_size < 0)
		{
			throw runtime_error( "Can't have negative bookshelf" );
		}
		
		string new_entry = "";

		if (roster.size() == max_book_size)
		{
			cout << endl << "Bookshelf is full, apologies, no more book can be added" << endl;
			WaitForUser();
		}
		else
		{
			cout << endl << "Please enter book number" << endl;

			cin >> new_entry;
			
			roster.push_back(new_entry); 
			cout << "Book information has been saved." << endl;
			WaitForUser();
		}
		return roster;
	}

	vector<string> DeleteBook(vector<string> roster) 
	{
			cout << endl << "Please enter index of book to be deleted" << endl;
			int index_of_book_selected_for_deletion = GetUserInputWithinIntegerRange(1, roster.size()+1);
			
			roster.erase( roster.begin() + index_of_book_selected_for_deletion - 1 );
			cout << endl << "Book information deleted, please press any character to continue" << endl;	
			WaitForUser();
			return roster;
	}

	void WaitForUser()
	{
		cout << endl << "Please press enter to continue..." << endl;
		cin.get();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n' );	
	}

	void PrintInvalidFunctionSelectionWarning(int max_function_count)
	{
		cerr << endl << "Please select integer from the list of offered functions, 1 to " << max_function_count << endl;

		cin.clear();
		cin.ignore();
		return;
	}

	int GetUserSelection(int max)
	{
		int user_selection = 0;
		cout << endl << "Please select the operation" << endl;	
		cin >> user_selection;

		if 
		( 
			!cin 
			|| user_selection < 1 
			|| user_selection > max 
		) 
		{
			PrintInvalidFunctionSelectionWarning( max );
			throw runtime_error("Invalid functionality selection");
		}
		
		return user_selection;
	}

	void DispatchSelectedOperation(int user_selection)
	{
			switch (user_selection)
			{
				case 1:
					DisplayRoster(roster);
					break;

				case 2:
					roster = AddBook(roster, max_book_size);	
					break;

				case 3:
					roster = DeleteBook(roster);
					break;

				case 4:
					cout << "Exiting..." << endl; 
					exit(0);

				default:
					cout << "Invalid user selection" << endl;
					WaitForUser();
					break;
			}
	}

	int GetUserInputWithinIntegerRange(int min, int max)
	{
		int index_of_book_selected_for_deletion = 0;
		
		bool keep_polling_user = true;
		while ( keep_polling_user )
		{
			cin.clear();
			cin.ignore();
			cin >> index_of_book_selected_for_deletion;

			const auto [is_valid, validation_message] = ValidateUserInputWithinIntegerRange(min, max, index_of_book_selected_for_deletion);

			if (!is_valid) 
			{
				cout << endl << validation_message << endl;
			}
			
			keep_polling_user = !is_valid;
		}
		return index_of_book_selected_for_deletion;
	}
}

/// @brief function is validating user input, making sure a valid integer input was submitted by the user
/// @param min minimum acceptable valued
/// @param max maximum acceptable value
/// @param user_input actual value submitted by the user
/// @return boolean part is true if input was valid, and false if input was invalid. there is also an error message part, that's empty for valid scenario and contains error message for invalid scenario
tuple<bool, string> ctch1330::ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input)
{
	if 
	( 
		!cin
		|| user_input < min
		|| user_input > max 
	)
	{
		return {false, "Please enter integer within the range of current roster"};
	}
	else 
	{
		return {true, ""};
	}
}