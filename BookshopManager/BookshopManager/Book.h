#ifndef _Book_h
#define _Book_h
#include "User.h"
#include<iostream>
#include<string>
using namespace std;

class Book
{
protected:
	string book_id;
	string book_title;
	string book_author;
	string book_type;
	string book_release_date;
public:
	Book(string);
	Book(string, string, string, string, string);
	~Book();
	string getBookId();
	string getTitle();
	string getAuthor();
	string getBookType();
	string getReleaseDate();
	string sendQueryRetStr(string);
};

#endif 
