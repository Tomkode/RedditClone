#pragma once
#include "userRepository.h"
#include <QTextStream>
#include  "Validator.h"
class Service
{
private:
	userRepository userRepository;
	
public:
	std::string hashToSHA256(std::string input_string);
	void createUserAccount(std::string userName, std::string password, std::string confirmPassword, std::string email, std::string passwordResetCode);
	void verifyAccountCredentials(std::string userName, std::string hashedPass);
	void verifyAccountUniqueness(std::string userName, std::string email="");
	void verifyUsername(std::string userName);
	void verifyEmail(std::string email);
	void verifyPassword(std::string password);
	void verifyConfirmPassword(std::string password, std::string confirmPassword);
	void verifyResetCode(std::string resetCode);
};

