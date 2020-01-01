#ifndef _Admin_h
#define _Admin_h
#include "User.h"

class Admin : public User
{
public:
	Admin(string, string);
	void sendQueryPrint(string);
	string sendQueryRetStr(string);
	int showMenu();
	void showBooks();
	~Admin();
};

#endif
