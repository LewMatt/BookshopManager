#ifndef _Client_h
#define _Client_h
#include "User.h"

class Client : public User
{
public:
	Client(string, string);
	~Client();
	int showMenu();
	void showBooks();
};

#endif
