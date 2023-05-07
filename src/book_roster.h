#pragma once

#include <vector>
#include <string>
using namespace std;
namespace ctch1330
{
	constexpr int max_book_size = 6;

	void RenderMainMenu(vector<string> menu);
	void DisplayRoster(vector<string> roster);
	vector<string> AddBook(vector<string> roster, int max_book_size);
	vector<string> DeleteBook(vector<string> roster);
	void WaitForUser();
	int GetUserSelection(int max);
	void PrintInvalidFunctionSelectionWarning();
	void DispatchSelectedOperation(int user_selection);
	int GetUserInputWithinIntegerRange(int min, int max);
	tuple<bool, string> ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input);
	void PrintInvalidFunctionSelectionWarning(int max_function_count);

	extern vector<string> roster;
	extern vector<string> menu_real;
	vector<string> GetMenuFromDatabase();

		

}

