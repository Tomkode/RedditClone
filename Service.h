#pragma once
#include <string>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include "Validator.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <QTextStream>
class Service
{
public:
	std::string hashToSHA256(std::string input_string);
	void createUserAccount(std::string userName, std::string password, std::string confirmPassword, std::string email);
	void addToDatabase(std::string userName, std::string hashedPass, std::string email);
	void verifyAccountCredentials(std::string userName, std::string hashedPass);
	void verifyAccountUniqueness(std::string userName, std::string email="");
};

