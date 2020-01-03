#include<iostream>
#include<string>
#include<mysql.h>
#include "Admin.h"
#include "Client.h"
#include "Book.h"
#include "User.h"

using namespace std;

const char* sql_host_name = "localhost";
const char* sql_user_name = "root";
const char* sql_password = "password";
const char* sql_db_name = "bookshop_db";
const unsigned int sql_port = 3306;
const char* sql_socket = NULL;
const int sql_flags = 0;

bool loggedIn = false;
string loggedUsername;
string loggedPassword;

string sendQueryRetStr(string x)
{
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
		for (int i = 0; i < num_fields; i++)
		{
			if (row[i] != NULL)
			{
				retVal = row[0];
			}
		}
	}

	if (qRes != NULL)
	{
		mysql_free_result(qRes);
	}
	mysql_close(handler);

	return retVal;
}

void loginFunc()
{
	while (true)
	{
		string username, password, userQ, passQ, logQ;
		cout << endl << "Username: ";
		getline(cin, username);
		cout << "Password: ";
		getline(cin, password);

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
			cout << endl << "Invalid input. Try again." << endl;
		}
	}
}

int main()
{
	
	while (true)
	{
		system("CLS");
		cout << "||| MATT'S BOOKSHOP MANAGER |||" << endl;
		while (loggedIn == false)
		{
			
			loginFunc();
			loggedIn = true;
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
					cout << "Not ready yet." << endl;
					break;
				}
				case 3:
				{
					cout << "Not ready yet." << endl;
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


	return 0;
}