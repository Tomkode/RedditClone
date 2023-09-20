#pragma once
#include <exception>
#include <string>

class IncorrectCredentialsException :public std::exception {
public:
	virtual const char* what() const override{
		return "Incorrect credentials!";
	}
};
class InvalidUsernameException : public IncorrectCredentialsException
{
public:
	const char* what() const  override{
		return "Username length must be between 3-20 and it can only contain letters,digits and underscore!";
	}
};
class InvalidEmailException : public IncorrectCredentialsException
{
public:
	const char* what() const override{
		return "Email is not valid!";
	}
};
class InvalidPasswordException : public IncorrectCredentialsException
{
public:
	const char* what() const override{
		return "Password must contain one uppercase letter,one lowercase letter,one digit, one special character!";
	}
};
class InvalidResetCodeException : public IncorrectCredentialsException
{
public:
	const char* what() const override {
		return "Reset code must be a 7 digit number!";
	}
};
class DifferentPasswordsException : public IncorrectCredentialsException
{
public:
	const char* what() const override{
		return "Passwords must be the same!";
	}
};


class InexistentAcccountException : public IncorrectCredentialsException
{
public:
	const char* what() {
		return "The entered account doesn't exist!";
	}
};


class SignUpException: public IncorrectCredentialsException
{
	const char* what() const override {
		return "Couldn't sign up";
	}
};
class ExistentUsernameException : public IncorrectCredentialsException
{
public:
	const char* what() const override
	{
		return "Username already exists!";
	}
};

class ExistentEmailException : public IncorrectCredentialsException
{
public:
	const char* what() const override
	{
		return "Email already in use";
	}
};
