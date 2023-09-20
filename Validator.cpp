#include "Validator.h"
using namespace std;
void Validator::isValidUsername(string username)
{
	regex pattern("^[a-zA-Z0-9_]{3,20}$");
	if (!regex_match(username, pattern))
		throw InvalidUsernameException();
}

void Validator::isValidPassword(string password)
{
	regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{6,}$");
	if (!regex_match(password, pattern))
		throw InvalidPasswordException();
}

void Validator::isValidEmail(string email)
{
	regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
	if (!regex_match(email, pattern))
		throw InvalidEmailException();
}

void Validator::arePasswordsEqual(std::string password, std::string confirmPassword)
{
	if (password != confirmPassword)
		throw DifferentPasswordsException();
}

void Validator::isValidResetCode(std::string passwordResetCode)
{
	regex pattern("^[1-9]{1}[0-9]{6}$");
	if (!regex_match(passwordResetCode, pattern))
		throw InvalidResetCodeException();
}

void Validator::isValidTitle(std::string title)
{
}

void Validator::isValidText(std::string text)
{
}
