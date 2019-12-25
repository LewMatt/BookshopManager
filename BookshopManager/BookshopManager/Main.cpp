#include<iostream>
#include<string>
#include "Admin.h"
#include "Client.h"
#include "Book.h"
#include "User.h"
using namespace std;

int main()
{
	Admin user0("admin", "admin");
	Client user1("mati", "123");
	Book book1("Harry Potter", "JK Rowling", "fantasy", "2010");
	Book book2("Zew Cthulhu", "Lovecraft", "fantasy", "2005");
	Book book3("DaVinci", "Leonardo", "criminal", "2000");
	Book my_books[3] = {book1,book2,book3};
	void LoginFunc();
	bool loggedIn=false;
	User* user_logged =NULL;

	while (true)
	{
		while (loggedIn == false)
		{
			string l_username, l_password;
			cout << endl << "Login: ";
			getline(cin, l_username);
			cout << "Password: ";
			getline(cin, l_password);

			if (l_username == user0.getUsername() && l_password == user0.getPassword())
			{
				cout << endl << "Hello " << user0.getUsername() << endl;
				user_logged = &user0;
				loggedIn = true;
			}
			else if (l_username == user1.getUsername() && l_password == user1.getPassword())
			{
				cout << endl << "Hello " << user1.getUsername() << endl;
				user_logged = &user1;
				loggedIn = true;
			}
			else
			{
				cout << endl << "Invalid input.Try again." << endl;
			}
		}

		while (loggedIn == true)
		{
			int choice = 0;
			user_logged->showOptions();
			choice = user_logged->whatOption();
			if (choice == 0)
			{
				continue;
			}
			else if (choice == 1)
			{
				user_logged->showUserDetails();
			}
			else if (choice == 2)
			{
				user_logged->showBooks(my_books);
			}
			else if (choice == 9)
			{
				loggedIn = false;
			}
		}
	}

	return 0;
}