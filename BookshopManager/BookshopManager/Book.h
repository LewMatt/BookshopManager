#ifndef _Book_h
#define _Book_h
#include<iostream>
#include<string>
using namespace std;

class Book
{
protected:
	string book_title;
	string book_author;
	string book_type;
	string book_release_date;
public:
	Book(string, string, string, string);
	~Book();
	string getTitle();
	string getAuthor();
	string getBookType();
	string getReleaseDate();
};

#endif 
