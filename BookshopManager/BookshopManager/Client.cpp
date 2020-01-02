#include "Client.h"


Client::Client(string user_name, string user_password) : User(user_name, user_password)
{
	string firstNameQuery = "SELECT first_name FROM users WHERE user_name = '" + this->user_name + "';";
	this->first_name = sendQueryRetStr(firstNameQuery.c_str());
	string lastNameQuery = "SELECT last_name FROM users WHERE user_name = '" + this->user_name + "';";
	this->last_name = sendQueryRetStr(lastNameQuery.c_str());
	string emailQuery = "SELECT email FROM users WHERE user_name = '" + this->user_name + "';";
	this->email = sendQueryRetStr(emailQuery.c_str());
	string phoneNumberQuery = "SELECT phone_number FROM users WHERE user_name = '" + this->user_name + "';";
	this->phone_number = sendQueryRetStr(phoneNumberQuery.c_str());
}

int Client::showMenu()
{
	cout << "OPTIONS" << endl << endl;
	cout << "1. Show books. " << endl;
	cout << "2. Show user details." << endl;
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


void Client::showBooks()
{
	int tab_cols = 5;

	string rowsQ = "SELECT COUNT(*) FROM books;";
	int tab_rows = sendQueryRetInt(rowsQ.c_str()) + 1;

	string** tab = new string * [tab_rows];
	for (int i = 0; i < tab_rows; i++)
	{
		tab[i] = new string[tab_cols];
	}
	tab[0][0] = "id";
	tab[0][1] = "name";
	tab[0][2] = "author";
	tab[0][3] = "type";
	tab[0][4] = "release date";


	int x;
	for (int i = 1; i < tab_rows ; i++)
	{
		x = i - 1;
		string var = to_string(x);

		for (int j = 0; j < tab_cols; j++)
		{
			switch (j)
			{
			case 0:
			{
				string element = "SELECT id FROM books limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 1:
			{
				string element = "SELECT name FROM books limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 2:
			{
				string element = "SELECT author FROM books limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 3:
			{
				string element = "SELECT type FROM books limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 4:
			{
				string element = "SELECT release_date FROM books limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			}
		}
	}
	for (int i = 0; i < tab_rows; i++)
	{
		for (int j = 0; j < tab_cols; j++)
		{
			cout.width(10);
			cout << left << tab[i][j] << " ";
		}
		cout << endl;
	}

}

Client::~Client()
{

}