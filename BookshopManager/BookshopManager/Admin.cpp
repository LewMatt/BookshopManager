#include "Admin.h"

Admin::Admin(string username, string password) : User(username, password)
{
	this->userType = "0";
}