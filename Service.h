#pragma once
#include <string>
#include <openssl/sha.h>
#include <openssl/evp.h>
class Service
{
public:
	std::string hashToSHA256(std::string input_string);
	void createUserAccount(std::string userName, std::string password, std::string email);
};

