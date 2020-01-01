#include "Admin.h"

Admin::Admin(string user_name, string user_password) : User(user_name, user_password)
{

}

void Admin::sendQueryPrint(string x)
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

	while ((row = mysql_fetch_row(qRes)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			if (row[i] != NULL)
			{
				cout << row[i] << " ";
			}
			else
			{
				cout << "NULL" << endl;
			}
		}
		cout << endl;
	}

	if (qRes != NULL)
	{
		mysql_free_result(qRes);
	}
	mysql_close(handler);
}

string Admin::sendQueryRetStr(string x)
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

	string retVal;

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