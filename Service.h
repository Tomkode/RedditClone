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
	void createUserAccount(std::string userName, std::string password, std::string confirmPassword, std::string email);
	void verifyAccountCredentials(std::string userName, std::string hashedPass);
	void verifyAccountUniqueness(std::string userName, std::string email="");
};

