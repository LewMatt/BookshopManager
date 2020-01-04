#include "Book.h"

Book::Book(string b)
{
	string var;
	this->book_id = b;
	var = "SELECT name FROM books_all WHERE book_id = '" + b + "';";
	this->book_title = sendQueryRetStr(var.c_str());
	var = "SELECT author FROM books_all WHERE book_id = '" + b + "';";
	this->book_author = sendQueryRetStr(var.c_str());
	var = "SELECT type FROM books_all WHERE book_id = '" + b + "';";
	this->book_type = sendQueryRetStr(var.c_str());
	var = "SELECT release_date FROM books_all WHERE book_id = '" + b + "';";
	this->book_release_date = sendQueryRetStr(var.c_str());
}

Book::Book(string b_id, string b_title, string b_author, string b_type, string b_release_date)
{
	this->book_id = b_id;
	this->book_title = b_title;
	this->book_author = b_author;
	this->book_type = b_type;
	this->book_release_date = b_release_date;
}

string Book::getBookId()
{
	return this->book_id;
}

string Book::getTitle()
{
	return this->book_title;
}

string Book::getAuthor()
{
	return this->book_author;
}

string Book::getBookType()
{
	return this->book_type;
}

string Book::getReleaseDate()
{
	return this->book_release_date;
}

string Book::sendQueryRetStr(string x)
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

Book::~Book()
{

}