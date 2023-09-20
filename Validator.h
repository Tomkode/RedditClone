#pragma once
#include <string>
#include "ValidatorException.h"
#include <regex>
class Validator
{
public:
	void isValidUsername(std::string userName);
	void isValidPassword(std::string password);
	void isValidEmail(std::string email);
	void arePasswordsEqual(std::string password, std::string confirmPassword);
	void isValidResetCode(std::string passwordResetCode);
	void isValidTitle(std::string title);
	void isValidText(std::string text);
};

