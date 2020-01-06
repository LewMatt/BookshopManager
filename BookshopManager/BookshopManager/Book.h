#ifndef _Book_h
#define _Book_h
#include "User.h"
#include<iostream>
#include<string>
using namespace std;

class Book
{
protected:
	int book_id,book_release_date;
	string book_title;
	string book_author;
	string book_type;
public:
	Book(int);
	Book(int, string, string, string, int);
	~Book();
	int getBookId();
	string getTitle();
	string getAuthor();
	string getBookType();
	int getReleaseDate();
	string sendQueryRetStr(string);
	int sendQueryRetInt(string);
};

#endif 
