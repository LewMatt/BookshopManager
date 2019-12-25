#include "Client.h"


Client::Client(string username, string password) : User(username, password)
{
	this->userType = "1";
}

