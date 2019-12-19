#include "Book.h"

Book::Book(string book_name, string book_author, string book_type, string book_release_date)
{
	this->book_name = book_name;
	this->book_author = book_author;
	this->book_type = book_type;
	this->book_release_date = book_release_date;
}