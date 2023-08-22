#pragma once
#include <string>
class User
{
private:
	std::string username;
	std::string password;
	std::string email;
public:
	User();
	User(std::string username, std::string password, std::string email);
	std::string getUsername();
	std::string getPassword();
	std::string getEmail();
};

