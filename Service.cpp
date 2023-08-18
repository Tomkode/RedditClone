#include "Service.h"
using namespace std;


std::string Service::hashToSHA256(std::string inputString)
{
	size_t inputLen = inputString.length();
	unsigned char hash[SHA256_DIGEST_LENGTH];
	char hash_str[2 * SHA_DIGEST_LENGTH + 1];
	SHA256((const unsigned char*)inputString.c_str(), inputLen, hash);
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		sprintf(&hash_str[i * 2], "%02x", hash[i]);
	}
	return string(hash_str);
}

void Service::createUserAccount(std::string userName, std::string password, std::string confirmPassword, std::string email)
{
	Validator v;
	//validations for username, password and email
	v.isValidUsername(userName);
	v.isValidEmail(email);
	v.isValidPassword(password);
	v.arePasswordsEqual(password, confirmPassword);
	//string hashedPassword = this->hashToSHA256(password);
}


//*************
//tests for hash function
