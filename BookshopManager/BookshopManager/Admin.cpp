#include "Admin.h"

Admin::Admin(string user_name, string user_password) : User(user_name, user_password)
{
	string userIdQuery = "SELECT user_id FROM users WHERE user_name = '" + this->user_name + "';";
	this->user_id = sendQueryRetInt(userIdQuery.c_str());
	string firstNameQuery = "SELECT first_name FROM users WHERE user_name = '" + this->user_name + "';";
	this->first_name = sendQueryRetStr(firstNameQuery.c_str());
	string lastNameQuery = "SELECT last_name FROM users WHERE user_name = '" + this->user_name + "';";
	this->last_name = sendQueryRetStr(lastNameQuery.c_str());
	string emailQuery = "SELECT email FROM users WHERE user_name = '" + this->user_name + "';";
	this->email = sendQueryRetStr(emailQuery.c_str());
	string phoneNumberQuery = "SELECT phone_number FROM users WHERE user_name = '" + this->user_name + "';";
	this->phone_number = sendQueryRetStr(phoneNumberQuery.c_str());
}

int Admin::showMenu()
{
	system("CLS");
	cout << "OPTIONS" << endl << endl;
	cout << "1. Show all books. " << endl;
	cout << "2. Show clients." << endl;
	cout << "3. Show borrowed books." << endl;
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
		else if (choice == "3")
		{
			return 3;
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
	system("CLS");
	int tab_cols = 5;
	string rowsQ = "SELECT COUNT(*) FROM books_all;";
	int tab_rows = sendQueryRetInt(rowsQ.c_str());

	string** tab = new string * [tab_rows];
	for (int i = 0; i < tab_rows; i++)
	{
		tab[i] = new string[tab_cols];
	}

	string tab_h[5] = { "id","Title","Author","Type","Release date" };

	for (int i = 0; i < tab_rows; i++)
	{
		string var = to_string(i);

		for (int j = 0; j < tab_cols; j++)
		{
			switch (j)
			{
			case 0:
			{
				string element = "SELECT book_id FROM books_all limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 1:
			{
				string element = "SELECT name FROM books_all limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 2:
			{
				string element = "SELECT author FROM books_all limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 3:
			{
				string element = "SELECT type FROM books_all limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			case 4:
			{
				string element = "SELECT release_date FROM books_all limit " + var + ",1;";
				tab[i][j] = sendQueryRetStr(element.c_str());
				break;
			}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout.width(24);
		cout << left << tab_h[i];
	}
	cout << endl << endl;

	for (int i = 0; i < tab_rows; i++)
	{
		for (int j = 0; j < tab_cols; j++)
		{
			cout.width(24);
			cout << left << tab[i][j];
		}
		cout << endl;
	}

	cout << endl << "OPTIONS" << endl << endl;
	cout << "1.Add a new book." << endl;
	cout << "2.Return to menu." << endl;

	while (true)
	{
		string choice;
		cout << endl << "What to do: ";
		getline(cin, choice);

		if (choice == "1")
		{
			string b_id, b_title, b_author, b_type, b_release_date;
			
			while (true)
			{
				string x;
				cout << endl << "Book id: ";
				getline(cin, x);
				string qText = "SELECT COUNT(*) FROM books_all WHERE book_id = '" + x + "';";
				int result = sendQueryRetInt(qText.c_str());
				if (result == 1)
				{
					cout << endl << "There already is a book with that id. Try again." << endl;
				}
				else
				{
					b_id = x;
					break;
				}
			}
			
			cout << "Book title: ";
			getline(cin, b_title);
			cout << "Author: ";
			getline(cin, b_author);
			cout << "Book type: ";
			getline(cin, b_type);
			cout << "Release date: ";
			getline(cin, b_release_date);

			Book* book_obj = new Book(b_id, b_title, b_author, b_type, b_release_date);

			string queryBooks = "INSERT INTO books (book_id,name,author,type,release_date) VALUES ('" + book_obj->getBookId() + "','" + book_obj->getTitle() + "','" + book_obj->getAuthor() + "','" + book_obj->getBookType() + "','" + book_obj->getReleaseDate() + "');";
			string queryBooksAll = "INSERT INTO books_all (book_id,name,author,type,release_date) VALUES ('" + book_obj->getBookId() + "','" + book_obj->getTitle() + "','" + book_obj->getAuthor() + "','" + book_obj->getBookType() + "','" + book_obj->getReleaseDate() + "');";
			sendQuery(queryBooks.c_str());
			sendQuery(queryBooksAll.c_str());

			delete book_obj;

			break;
		}
		else if (choice == "2")
		{
			break;
		}
		else
		{
			cout << endl << "Invalid input. Try again." << endl;
		}
	}

	for (int i = 0; i < tab_rows; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}

Admin::~Admin()
{

}