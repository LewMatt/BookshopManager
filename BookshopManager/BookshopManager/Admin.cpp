#include "Admin.h"

Admin::Admin(string user_name, string user_password) : User(user_name, user_password)
{

}


int Admin::showMenu()
{
	cout << endl << "OPTIONS" << endl << endl;
	cout << "1. Show books. " << endl;
	cout << "2. Show users." << endl;
	cout << "9. Log out." << endl << endl;
	while (true)
	{
		string choice;
		cout << "What to do: ";
		getline(cin, choice);
		if (choice == "1")
		{
			return 1;
			break;
		}
		else if (choice == "2")
		{
			return 2;
			break;
		}
		else if (choice == "9")
		{
			return 9;
			break;
		}
		else
		{
			cout << endl << "Invalid input. Try again." << endl << endl;
		}
	}
}

void Admin::showBooks()
{
	
}

Admin::~Admin()
{

}