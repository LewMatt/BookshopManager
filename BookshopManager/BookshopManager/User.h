#ifndef _User_h
#define _User_h
#include "Book.h"
#include<string>
#include<iostream>
#include<mysql.h>
#include<stdio.h> 
using namespace std;

class User
{
protected:
	string user_name;
	string user_password;
	string first_name = "", last_name = "", email = "", phone_number = "";
public:
	User(string, string);
	string getUsername();
	string getPassword();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getPhoneNumber();
};

#endif
