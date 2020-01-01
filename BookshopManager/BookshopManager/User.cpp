#include "User.h"

User::User(string user_name, string user_password)
{
	this->user_name = user_name;
	this->user_password = user_password;
}

string User::getPassword()
{
	return user_password;
}

string User::getUsername()
{
	return user_name;
}

string User::getFirstName()
{
	return first_name;
}

string User::getLastName()
{
	return last_name;
}

string User::getEmail()
{
	return email;
}

string User::getPhoneNumber()
{
	return phone_number;
}