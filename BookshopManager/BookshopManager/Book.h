#ifndef _Book_h
#define _Book_h
#include<string>
using namespace std;

class Book
{
private:
	string book_name;
	string book_author;
	string book_type;
	string book_release_date;
public:
	Book(string, string, string, string);
};

#endif 
