#include "User.h"

User::User(string user_name, string user_password)
{
	this->user_name = user_name;
	this->user_password = user_password;
}

int User::getUserId()
{
	return user_id;
}

string User::getPassword()
{
	return user_password;
}

void User::setPassword(string new_pw)
{
	this->user_password = new_pw;
}

string User::getUsername()
{
	return user_name;
}

string User::getFirstName()
{
	return first_name;
}

string User::getLastName()
{
	return last_name;
}

string User::getEmail()
{
	return email;
}

int User::getPhoneNumber()
{
	return phone_number;
}

int User::showMenu()
{
}

string User::sendQueryRetStr(string x)
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
		retVal = row[0];
	}

	if (qRes != NULL)
	{
		mysql_free_result(qRes);
	}
	mysql_close(handler);

	return retVal;
}

int User::sendQueryRetInt(string x)
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

void User::sendQuery(string x)
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

void User::sendQueryRetArr(string x, string *tab[])
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

	int i = 0;
	while ((row = mysql_fetch_row(qRes)))
	{
		for (int j = 0; j < num_fields; j++)
		{
			if (row[j] != NULL)
			{
				tab[i][j] = row[j];
			}
			else
			{
				tab[i][j] = " ";
			}
		}
		i++;
	}

	if (qRes != NULL)
	{
		mysql_free_result(qRes);
	}
	mysql_close(handler);

}

void User::setFirstName(string x)
{
	this->first_name = x;
}

void User::setLastName(string x)
{
	this->last_name = x;
}

void User::setEmail(string x)
{
	this->email = x;
}

void User::setPhoneNumber(int x)
{
	this->phone_number = x;
}