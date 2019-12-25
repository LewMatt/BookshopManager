#ifndef _User_h
#define _User_h
#include "Book.h"
#include<string>
#include<iostream>
using namespace std;

class User
{
protected:
	string username;
	string password;
	string userType;
	string first_name = "", last_name = "", email = "", phone_number = "";
public:
	User(string, string);
	string getUsername();
	string getPassword();
	void setFirstName();
	void setLastName();
	void setEmail();
	void setNumber();
	int whatOption();
	void showOptions();
	void showUserDetails();
	void showBooks(Book x[]);
};

#endif
