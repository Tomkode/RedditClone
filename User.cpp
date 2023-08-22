#include "User.h"

User::User()
{
	username = "";
	password = "";
	email = "";
}

User::User(std::string username, std::string password, std::string email): username{username}, password{password}, email{email}
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
