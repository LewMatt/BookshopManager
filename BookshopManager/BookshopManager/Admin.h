#ifndef _Admin_h
#define _Admin_h
#include "User.h"

class Admin : public User
{
public:
	Admin(string, string);
	virtual int showMenu();
	void showBooks();
	void showBorrowedBooks();
	void showClients();
	~Admin();
};

#endif
