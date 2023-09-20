#pragma once
#include <string>
class User
{
private:
	int userId;
	std::string username;
	std::string password;
	std::string email;
	std::string resetCode;
public:
	User();
	User(std::string username, std::string password, std::string email, std::string resetCode);
	std::string getUsername();
	std::string getPassword();
	std::string getEmail();
	std::string getResetCode();
	int getUserId();
};

