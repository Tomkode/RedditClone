#pragma once
#include <exception>
#include <string>
class UsernameException : public std::exception
{
public:
	const char* what() {
		return "Username lenght must be between 3-20 and it can only contain letters,digits and underscore!";
	}
};
class EmailException : public std::exception
{
public:
	const char* what() {
		return "Email is not valid!";
	}
};
class PasswordException : public std::exception
{
public:
	const char* what() {
		return "Password must contain one uppercase letter,one lowercase letter,one digit, one special character!";
	}
};
class DifferentPasswordsException : public std::exception
{
public:
	const char* what() {
		return "Passwords must be the same!";
	}
};
