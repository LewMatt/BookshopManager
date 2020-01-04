#ifndef _User_h
#define _User_h
#include "Book.h"
#include<string>
#include<iostream>
#include<mysql.h>
#include<stdio.h> 
#include<conio.h>
using namespace std;

class User
{
protected:
	string user_id;
	string user_name;
	string user_password;
	string first_name, last_name, email, phone_number;
public:
	User(string, string);
	string getUserId();
	string getUsername();
	string getPassword();
	void setPassword(string);
	string getFirstName();
	string getLastName();
	string getEmail();
	string getPhoneNumber();
	string sendQueryRetStr(string);
	int sendQueryRetInt(string);
	void sendQuery(string);
};

#endif
