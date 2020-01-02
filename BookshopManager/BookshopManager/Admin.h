#ifndef _Admin_h
#define _Admin_h
#include "User.h"

class Admin : public User
{
public:
	Admin(string, string);
	int showMenu();
	void showBooks();
	~Admin();
};

#endif
