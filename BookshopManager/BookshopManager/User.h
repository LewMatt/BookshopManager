#ifndef _User_h
#define _User_h
#include<string>
using namespace std;

class User
{
protected:
	string username;
	string password;
public:
	User(string, string);
};

#endif
