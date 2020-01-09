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
	int user_id, phone_number;
	string user_name;
	string user_password;
	string first_name, last_name, email;
public:
	User(string, string);
	virtual int showMenu();
	int getUserId();
	string getUsername();
	string getPassword();
	void setPassword(string);
	string getFirstName();
	string getLastName();
	string getEmail();
	int getPhoneNumber();
	string sendQueryRetStr(string);
	int sendQueryRetInt(string);
	void sendQuery(string);
};

#endif
