#include "User.h"

User::User()
{
	username = "";
	password = "";
	email = "";
	resetCode = "";
}

User::User(std::string username, std::string password, std::string email, std::string resetCode) : username{ username }, password{ password }, email{ email }, resetCode{resetCode}
{

}

User::User(int userId, std::string username, std::string password, std::string email, std::string resetCode) : userId{ userId }, username { username }, password{ password }, email{ email }, resetCode{ resetCode }
{
}

std::string User::getUsername()
{
	return username;
}

std::string User::getPassword()
{
	return password;
}

std::string User::getEmail()
{
	return email;
}

std::string User::getResetCode()
{
	return resetCode;
}

int User::getUserId()
{
	return userId;
}
