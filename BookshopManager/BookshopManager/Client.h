#ifndef _Client_h
#define _Client_h
#include "User.h"

class Client : public User
{
public:
	Client(string, string);
	~Client();
	virtual int showMenu();
	void showBooks(Client*);
	void showMyBooks(Client*);
	void showMyDetails(Client*);
};

#endif
