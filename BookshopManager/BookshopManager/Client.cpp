#include "Client.h"

Client::Client(string user_name, string user_password) : User(user_name, user_password)
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
	this->phone_number = sendQueryRetInt(phoneNumberQuery.c_str());
}

int Client::showMenu()
{
	string choice;
	system("CLS");
	cout << "OPTIONS" << endl << endl;
	cout << "1.Show availabe books. " << endl;
	cout << "2.Show my books." << endl;
	cout << "3.Show my details." << endl;
	cout << "9.Log out." << endl << endl;
	while (true)
	{
		cout << "What to do: ";
		cin >> choice;
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

void Client::showBooks(Client* cl_obj)
{
	system("CLS");
	int tab_cols = 5;
	string rowsQ = "SELECT COUNT(*) FROM books;";
	int tab_rows = sendQueryRetInt(rowsQ.c_str());
	if (tab_rows == 0)
	{
		cout << "No books available at this moment." << endl << endl;
		cout << "Enter 1 to return." << endl;

		while (true)
		{
			string choice;
			cout << endl << ": ";
			cin >> choice;
			if (choice == "1")
			{
				break;
			}
			else
			{
				cout << endl << "Invalid input. Try again." << endl;
			}
		}

	}
	else
	{
		string** tab = new string * [tab_rows];
		for (int i = 0; i < tab_rows; i++)
		{
			tab[i] = new string[tab_cols];
		}

		string tab_h[5] = { "id","Title","Author","Type","Release date" };

		string q = "SELECT * FROM books ORDER BY book_id;";

		sendQueryRetArr(q.c_str(), tab);

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
		cout << endl;
		cout << endl << "OPTIONS" << endl << endl;
		cout << "1.Borrow a book" << endl;
		cout << "2.Return to menu" << endl;

		while (true)
		{
			string choice;
			cout << endl << "What to do: ";
			cin >> choice;

			if (choice == "1")
			{
				while (true)
				{
					int choice;
					cout << endl << "Enter book id: ";
					cin >> choice;
					while (cin.fail())
					{
						cout << endl << "Invalid input. Try again." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cout << endl << "Enter book id: ";
						cin >> choice;
					}
					string querytext = "SELECT COUNT(*) FROM books WHERE book_id = " + to_string(choice) + ";";
					int res = sendQueryRetInt(querytext.c_str());
					if (res == 0)
					{
						cout << endl << "Invalid input. Try again." << endl;
					}
					else
					{
						Book* book_obj = new Book(choice);
						string var = "INSERT INTO books_" + cl_obj->getUsername() + " (book_id,title,author,type,release_date) VALUES (" + to_string(book_obj->getBookId()) + ",'" + book_obj->getTitle() + "','" + book_obj->getAuthor() + "','" + book_obj->getBookType() + "'," + to_string(book_obj->getReleaseDate()) + ");";
						sendQuery(var.c_str());
						string var2 = "INSERT INTO books_borrowed (book_id,title,client_id,client_username) VALUES (" + to_string(book_obj->getBookId()) + ",'" + book_obj->getTitle() + "'," + to_string(cl_obj->getUserId()) + ",'" + cl_obj->getUsername() + "');";
						sendQuery(var2.c_str());
						string var3 = "DELETE FROM books WHERE book_id=" + to_string(choice) + ";";
						sendQuery(var3.c_str());

						delete book_obj;
						break;
					}
				}
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
}

void Client::showMyBooks(Client* obj)
{
	string tab_h[5] = { "id","Title","Author","Type","Release date" };

	string rowsQ = "SELECT COUNT(*) FROM books_" + obj->getUsername() + ";";
	int tab_rows = sendQueryRetInt(rowsQ.c_str());

	if (tab_rows == 0)
	{
		system("CLS");
		cout << "You don't have any book yet." << endl << endl;
		cout << "Enter 1 to return." << endl;
		while (true)
		{
			string choice;
			cout << endl << ": ";
			cin >> choice;
			if (choice == "1")
			{
				break;
			}
			else
			{
				cout << endl << "Invalid input.Try again." << endl;
			}
		}
	}
	else
	{
		string** books_tab = new string * [tab_rows];
		for (int i = 0; i < tab_rows; i++)
		{
			books_tab[i] = new string[5];
		}

		string q = "SELECT * FROM books_" + obj->getUsername() + " ORDER BY book_id;";

		sendQueryRetArr(q.c_str(), books_tab);

		system("CLS");
		for (int i = 0; i < 5; i++)
		{
			cout.width(24);
			cout << left << tab_h[i];
		}
		cout << endl << endl;

		for (int i = 0; i < tab_rows; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout.width(24);
				cout << left << books_tab[i][j];
			}
			cout << endl;
		}

		cout << endl;
		cout << endl << "OPTIONS" << endl << endl;
		cout << "1.Return a book." << endl;
		cout << "2.Return to menu" << endl;

		while (true)
		{
			string choice;
			cout << endl << "What to do: ";
			cin >> choice;

			if (choice == "1")
			{
				while (true)
				{
					int input;
					cout << endl << "Enter book id: ";
					cin >> input;
					while (cin.fail())
					{
						cout << endl << "Invalid number. Try again." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cout << endl << "Enter book id: ";
						cin >> input;
					}
					string q = "SELECT COUNT(*) FROM books_" + obj->getUsername() + " WHERE book_id = " + to_string(input) + ";";
					int ret = sendQueryRetInt(q.c_str());
					if (ret == 0)
					{
						cout << endl << "Invalid input. Try again." << endl;
					}
					else
					{
						Book* book_obj = new Book(input);
						string var = "INSERT INTO books (book_id,title,author,type,release_date) VALUES (" + to_string(book_obj->getBookId()) + ",'" + book_obj->getTitle() + "','" + book_obj->getAuthor() + "','" + book_obj->getBookType() + "'," + to_string(book_obj->getReleaseDate()) + ");";
						sendQuery(var.c_str());
						string var2 = "DELETE FROM books_" + obj->getUsername() + " WHERE book_id= " + to_string(input) + ";";
						sendQuery(var2.c_str());
						string var3 = "DELETE FROM books_borrowed WHERE book_id= " + to_string(input) + ";";
						sendQuery(var3.c_str());
						delete book_obj;
						break;
					}
				}
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
			delete[] books_tab[i];
		}
		delete[] books_tab;
	}

}

void Client::showMyDetails(Client* obj)
{
	system("CLS");
	string user_det_h[5] = { "Username","First name","Last name","Email","Phone number" };
	string user_det[5] = { this->user_name,this->first_name,this->last_name,this->email,to_string(this->phone_number) };

	for (int i = 0; i < 5; i++)
	{
		cout.width(24);
		cout << left << user_det_h[i];
	}
	cout << endl << endl;
	for (int i = 0; i < 5; i++)
	{
		cout.width(24);
		cout << left << user_det[i];
	}
	cout << endl << endl;

	cout << endl << "OPTIONS" << endl << endl;
	cout << "1.Change details." << endl;
	cout << "2.Change password." << endl;
	cout << "3.Return to menu." << endl;

	while (true)
	{
		string choice;
		cout << endl << "What to do: ";
		cin >> choice;
		if (choice == "1")
		{
			cout << endl << "1.Change first name." << endl;
			cout << "2.Change last name." << endl;
			cout << "3.Change email." << endl;
			cout << "4.Change phone number." << endl;

			while (true)
			{
				string ch;
				cout << endl << "Choice: ";
				cin >> ch;
				if (ch == "1")
				{
					cout << endl << "New first name: ";
					string inp;
					cin >> inp;
					string que = "UPDATE users SET first_name = '" + inp + "' where user_name = '" + obj->getUsername() + "';";
					sendQuery(que.c_str());
					obj->setFirstName(inp);
					break;
				}
				else if (ch == "2")
				{
					cout << endl << "New last name: ";
					string inp;
					cin >> inp;
					string que = "UPDATE users SET last_name = '" + inp + "' where user_name = '" + obj->getUsername() + "';";
					sendQuery(que.c_str());
					obj->setLastName(inp);
					break;
				}
				else if (ch == "3")
				{
					cout << endl << "New email: ";
					string inp;
					cin >> inp;
					string que = "UPDATE users SET email = '" + inp + "' where user_name = '" + obj->getUsername() + "';";
					sendQuery(que.c_str());
					obj->setEmail(inp);
					break;
				}
				else if (ch == "4")
				{
					cout << endl <<"New phone number: ";
					int inp;
					cin >> inp;
					while (cin.fail()) 
					{
						cout << endl << "Invalid number. Try again." << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cout << endl << "New phone number: ";
						cin >> inp;
					}
					
					string que = "UPDATE users SET phone_number = " + to_string(inp) + " where user_name = '" + obj->getUsername() + "';";
					sendQuery(que.c_str());
					obj->setPhoneNumber(inp);
					break;
				}
				else
				{
					cout << endl << "Invalid input. Try again." << endl;
				}
			}
			break;
		}
		else if (choice == "2")
		{
			while (true)
			{
				string curr_pw = "";
				char ch;
				cout << endl << "Current password: ";
				ch = _getch();
				while (ch != 13)
				{
					curr_pw.push_back(ch);
					cout << '*';
					ch = _getch();
				}
				cout << endl;

				string pw_check = "SELECT user_password FROM users WHERE user_name ='" + obj->getUsername() + "';";
				string act_pw = sendQueryRetStr(pw_check.c_str());
				if (curr_pw == act_pw)
				{
					while (true)
					{
						string pw1="", pw2="";
						cout << endl << "New password: ";
						ch = _getch();
						while (ch != 13)
						{
							pw1.push_back(ch);
							cout << '*';
							ch = _getch();
						}
						cout << endl;

						cout << "New password again: ";
						ch = _getch();
						while (ch != 13)
						{
							pw2.push_back(ch);
							cout << '*';
							ch = _getch();
						}
						cout << endl;

						if (pw1 == pw2 && pw1 != "")
						{
							string que = "UPDATE users SET user_password = '" + pw1 + "' WHERE user_name = '" + obj->getUsername() + "';";
							sendQuery(que.c_str());
							obj->setPassword(pw1);
							break;
						}
						else
						{
							cout << endl << "Passwords don't match. Try again." << endl;
						}
					}
					break;
				}
				else
				{
					cout << endl << "Invalid current password. Try again." << endl;
				}

			}
			break;
		}
		else if (choice == "3")
		{
			break;
		}
		else
		{
			cout << endl << "Invalid input. Try again" << endl;
		}
	}

}

Client::~Client()
{

}