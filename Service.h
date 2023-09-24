#pragma once
#include "userRepository.h"
#include "postRepository.h"
#include <QTextStream>
#include  "Validator.h"
#include "Utils.h"
class Service
{
private:
	userRepository userRepository;
	postRepository postRepository;

	int postOffset = 0;
	
public:
	std::string hashToSHA256(std::string input_string);
	void createUserAccount(std::string userName, std::string password, std::string confirmPassword, std::string email, std::string passwordResetCode);
	void resetUserPassword(std::string userName, std::string email, std::string resetCode, std::string newPassword);
	void verifyAccountCredentials(std::string userName, std::string hashedPass);
	void verifyAccountUniqueness(std::string userName, std::string email="");
	void verifyUsername(std::string userName);
	void verifyEmail(std::string email);
	void verifyPassword(std::string password);
	void verifyConfirmPassword(std::string password, std::string confirmPassword);
	void verifyResetCode(std::string resetCode);
	User getUserByUsername(std::string username);
	void addPostByUser(std::string title, std::string content, User user);
	std::vector<Post> requestPosts(int number);
	std::string processPostTime(Post post);
};

