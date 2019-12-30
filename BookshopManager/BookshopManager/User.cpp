#include "User.h"

User::User(string username, string password)
{
	this->username = username;
	this->password = password;
}

string User::getPassword()
{
	return password;
}

string User::getUsername()
{
	return username;
}

string User::getType()
{
	return this->userType;
}

void User::setFirstName()
{
	string name;
	cout << endl << "First name: ";
	getline(cin, name);
	this->first_name = name;
}

void User::setLastName()
{
	string x;
	cout << "Last name: ";
	getline(cin, x);
	this->last_name = x;
}

void User::setEmail()
{
	string x;
	cout << "Email: ";
	getline(cin, x);
	this->email = x;
}

void User::setNumber()
{
	string x;
	cout << "Phone number: ";
	getline(cin, x);
	this->phone_number = x;
}

void User::showUserDetails()
{
	
	cout << endl << "USER DETAILS" << endl;
	cout << endl << "First name: " << this->first_name << endl;
	cout << "Last name: " << this->last_name << endl;
	cout << "Email: " << this->email << endl;
	cout << "Phone number: " << this->phone_number << endl;

	cout << endl << "1. Exit." << endl;
	cout << "2. Change details." << endl;

	while (true)
	{
		string choice;
		cout << endl << "Choice: ";
		getline(cin, choice);
		if (choice == "1")
		{
			break;
		}
		else if (choice == "2")
		{
			this->setFirstName();
			this->setLastName();
			this->setEmail();
			this->setNumber();
			cout << endl << "User details updated." << endl;
			break;
		}
		else
		{
			cout << endl << "Invalid input.Try again." << endl;
		}
	}
}

void User::showOptions()
{
	cout << endl << "OPTIONS" << endl << endl;
	cout << "1. Show user details." << endl;
	cout << "2. Show books. " << endl;
	cout << "9. Log out." << endl<<endl;
}

int User::whatOption()
{
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
			cout << endl << "Logged out." << endl;
			return 9;
			break;
		}
		else
		{
			cout <<endl<< "Invalid input. Try again."<<endl<<endl;
		}
	}
}

void User::showBooks(Book x[])
{	
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << ". Title: " << x[i].getTitle() << " Author: "<< x[i].getAuthor() << " Type: " << x[i].getBookType()<< " Release date: "<< x[i].getReleaseDate() << endl;
	}
	if (this->userType == "0")
	{
		cout << endl;
		cout << "1. Add new book." << endl;
		cout << "2. Delete book." << endl;
		cout << "3. Change book details." << endl;
		cout << "4. Exit." << endl;

		while (true)
		{
			string choice;
			cout << endl << "Choice: ";
			getline(cin, choice);
			if (choice == "4")
			{
				break;
			}
			else
			{
				cout << endl << "Invalid input.Try again."<<endl;
			}
		}
	}
	else
	{
		cout << endl << "1. Check out a book." << endl;
		cout << "2. Exit." << endl;

		while (true)
		{
			string choice;
			cout << endl << "Choice: ";
			getline(cin, choice);
			if (choice == "2")
			{
				break;
			}
			else
			{
				cout << endl << "Invalid input.Try again." << endl;
			}
		}
	}
}