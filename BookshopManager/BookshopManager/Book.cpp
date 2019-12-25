#include "Book.h"

Book::Book(string book_title, string book_author, string book_type, string book_release_date)
{
	this->book_title = book_title;
	this->book_author = book_author;
	this->book_type = book_type;
	this->book_release_date = book_release_date;
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