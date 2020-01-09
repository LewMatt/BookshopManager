#include<iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include <mysql.h>
#include "Admin.h"
#include "Client.h"
#include "Book.h"
#include "User.h"
using namespace std;

bool loggedIn = false;
string loggedUsername;
string loggedPassword;

string sendQueryRetStr(string x)
{
	const char* sql_host_name = "localhost";
	const char* sql_user_name = "root";
	const char* sql_password = "password";
	const char* sql_db_name = "bookshop_db";
	const unsigned int sql_port = 3306;
	const char* sql_socket = NULL;
	const int sql_flags = 0;

	MYSQL* handler;
	MYSQL_RES* qRes;
	MYSQL_ROW row;
	string retVal;

	handler = mysql_init(NULL);
	mysql_real_connect(handler, sql_host_name, sql_user_name, sql_password, sql_db_name, sql_port, sql_socket, sql_flags);

	mysql_query(handler, x.c_str());

	qRes = mysql_store_result(handler);

	int num_fields = mysql_num_fields(qRes);

	while ((row = mysql_fetch_row(qRes)))
	{
		retVal = row[0];
	}

	if (qRes != NULL)
	{
		mysql_free_result(qRes);
	}
	mysql_close(handler);

	return retVal;
}

int sendQueryRetInt(string x)
{
	const char* sql_host_name = "localhost";
	const char* sql_user_name = "root";
	const char* sql_password = "password";
	const char* sql_db_name = "bookshop_db";
	const unsigned int sql_port = 3306;
	const char* sql_socket = NULL;
	const int sql_flags = 0;

	MYSQL* handler;
	MYSQL_RES* qRes;
	MYSQL_ROW row;

	handler = mysql_init(NULL);
	mysql_real_connect(handler, sql_host_name, sql_user_name, sql_password, sql_db_name, sql_port, sql_socket, sql_flags);

	mysql_query(handler, x.c_str());
	qRes = mysql_store_result(handler);

	int num_fields = mysql_num_fields(qRes);

	string qOutput;

	while ((row = mysql_fetch_row(qRes)))
	{
		qOutput = row[0];
	}

	const char* str = qOutput.c_str();
	int retVal;
	sscanf_s(str, "%d", &retVal);

	if (qRes != NULL)
	{
		mysql_free_result(qRes);
	}
	mysql_close(handler);

	return retVal;
}

void sendQuery(string x)
{
	const char* sql_host_name = "localhost";
	const char* sql_user_name = "root";
	const char* sql_password = "password";
	const char* sql_db_name = "bookshop_db";
	const unsigned int sql_port = 3306;
	const char* sql_socket = NULL;
	const int sql_flags = 0;

	MYSQL* handler;

	handler = mysql_init(NULL);
	mysql_real_connect(handler, sql_host_name, sql_user_name, sql_password, sql_db_name, sql_port, sql_socket, sql_flags);

	mysql_query(handler, x.c_str());

	mysql_close(handler);
}

void createAccount()
{
	system("CLS");
	cout << "NEW USER CREATION" << endl;
	char ch;
	string newUsername, newPassword = "", newPasswordAgain = "", newFirstName, newLastName, newEmail;
	int newPhoneNumber;
	string qText = "SELECT COUNT(*) FROM users;";
	int newId = sendQueryRetInt(qText.c_str());

	while (true)
	{
		cout << endl << "Username: ";
		cin >> newUsername;
		string usernameQuery = "SELECT COUNT(*) FROM users WHERE user_name = '" + newUsername + "';";
		int result = sendQueryRetInt(usernameQuery.c_str());
		if (result == 0)
		{
			break;
		}
		else
		{
			cout << endl << "Username is taken. Try different one." << endl;
		}
	}

	while (true)
	{
		cout << "Password: ";
		ch = _getch();
		while (ch != 13)
		{
			newPassword.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << endl;
		cout << "Password again: ";
		ch = _getch();
		while (ch != 13)
		{
			newPasswordAgain.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << endl;
		if (newPassword == newPasswordAgain)
		{
			break;
		}
		else
		{
			cout << endl << "Passwords do not match. Try again." << endl << endl;
			newPassword = "";
			newPasswordAgain = "";
		}
	}

	cout << endl << "First name: ";
	cin >> newFirstName;
	cout << "Last name: ";
	cin >> newLastName;
	cout << "Email: ";
	cin >> newEmail;
	cout << "Phone number: ";
	cin >> newPhoneNumber;
	while (cin.fail())
	{
		cout << endl << "Invalid input. Try again." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl << "Phone number: ";
		cin >> newPhoneNumber;
	}

	string newIdStr = to_string(newId);
	string newAccQuery = "INSERT INTO users (user_id,user_name,user_password,first_name,last_name,email,phone_number) VALUES (" + newIdStr + ",'" + newUsername + "','" + newPassword + "','" + newFirstName + "','" + newLastName + "','" + newEmail + "'," + to_string(newPhoneNumber) + ");";
	sendQuery(newAccQuery.c_str());
	string newTabQuery = "CREATE TABLE books_" + newUsername + " (book_id int, title varchar(200), author varchar(200), type varchar(200), release_date int);";
	sendQuery(newTabQuery.c_str());
}

void loginOptions()
{
	cout << endl;
	cout << "1.Log in." << endl;
	cout << "2.Create a new account." << endl;
	cout << "9.Exit." << endl;

	while (true)
	{
		string choice;
		cout << endl << "What to do: ";
		cin >> choice;

		if (choice == "1")
		{
			break;
		}
		else if (choice == "2")
		{
			createAccount();
			break;
		}
		else if (choice == "9")
		{
			exit(0);
		}
		else
		{
			cout << endl << "Invalid input. Try again." << endl;
		}
	}
	system("CLS");
}

void loginFunc()
{
	cout << "LOG IN" << endl;

	while (true)
	{
		string username, password ="", userQ, passQ, logQ;
		char ch;
		cout << endl << "Username: ";
		cin >> username;
		cout << "Password: ";
		ch = _getch();
		while (ch != 13) 
		{
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		userQ = "'" + username + "'";
		passQ = "'" + password + "'";
		logQ = "SELECT COUNT(*) FROM users WHERE user_name = " + userQ + " AND user_password = " + passQ + ";";

		if (sendQueryRetStr(logQ.c_str()) == "1")
		{
			loggedUsername = username;
			loggedPassword = password;
			break;
		}
		else
		{
			cout << endl << endl << "Invalid input. Try again." << endl;
		}
	}
	loggedIn = true;
}

int main()
{
	while (true)
	{
		system("CLS");
		cout << "||| MATT'S BOOKSHOP MANAGER |||" << endl;

		while (loggedIn == false)
		{
			loginOptions();
			loginFunc();
		}

		while (loggedIn == true)
		{
			Admin* admin_obj = new Admin(loggedUsername, loggedPassword);
			Client* client_obj = new Client(loggedUsername, loggedPassword);
			bool adminLoggedIn = false;

			if (loggedUsername == "admin")
			{
				adminLoggedIn = true;
			}

			if (adminLoggedIn)
			{

				switch (admin_obj->showMenu())
				{
				case 1:
				{
					admin_obj->showBooks();
					break;
				}
				case 2:
				{
					admin_obj->showClients();
					break;
				}
				case 3:
				{
					admin_obj->showBorrowedBooks();
					break;
				}
				case 9:
				{
					delete admin_obj;
					delete client_obj;
					loggedIn = false;
					break;
				}
				}
			}
			else
			{
				switch (client_obj->showMenu())
				{
				case 1:
				{
					client_obj->showBooks(client_obj);
					break;
				}
				case 2:
				{
					client_obj->showMyBooks(client_obj);
					break;
				}
				case 3:
				{
					client_obj->showMyDetails(client_obj);
					break;
				}
				case 9:
				{
					cout << endl << "Logged out" << endl;
					delete admin_obj;
					delete client_obj;
					loggedIn = false;
					break;
				}
				}
			}
		}
	}
}