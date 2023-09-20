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

void Service::createUserAccount(std::string userName, std::string password, std::string confirmPassword, std::string email, std::string passwordResetCode)
{
	Validator v;
	//validations for username, password and email
	verifyUsername(userName);
	verifyEmail(email);
	verifyPassword(password);
	verifyConfirmPassword(password, confirmPassword);
	verifyResetCode(passwordResetCode);
	
	string hashedPassword = this->hashToSHA256(password);

    User newUser(userName, hashedPassword, email, passwordResetCode);
	this->userRepository.addUser(newUser);
}

void Service::resetUserPassword(std::string userName, std::string email, std::string resetCode, std::string newPassword)
{
	User userToChange = this->userRepository.getUserByUsername(userName);
	if (userToChange.getEmail() == email && userToChange.getResetCode() == resetCode)
	{
		verifyPassword(newPassword);
		newPassword = hashToSHA256(newPassword);
		userRepository.changePassword(userName, newPassword);
	}
	else
		throw InexistentAcccountException();
}



void Service::verifyAccountCredentials(std::string userName, std::string hashedPass)
{
    //could use other handling method
    User user = userRepository.getUserByUsername(userName);
    if (user.getUsername() == "")
        throw InexistentAcccountException();
    if (user.getPassword() != hashedPass)
        throw InexistentAcccountException();
}

void Service::verifyAccountUniqueness(std::string userName, std::string email)
{
	if (userName != "") {
		try
		{
			userRepository.getUserByUsername(userName);
		}
		catch (InexistentAcccountException &err)
		{
			throw ExistentUsernameException();
		}
	}
	else
	{
		try
		{
			userRepository.getUsersByEmail(email);
		}
		catch (InexistentAcccountException &err)
		{
			throw ExistentEmailException();
		}
	}
}

void Service::verifyUsername(std::string userName)
{
	Validator v;
	v.isValidUsername(userName);
	if(this->userRepository.isUserByUsername(userName))
		throw ExistentUsernameException();
}

void Service::verifyEmail(std::string email)
{
	Validator v;
	v.isValidEmail(email);
	if (userRepository.isUserByEmail(email))
		throw ExistentEmailException();
}

void Service::verifyPassword(std::string password)
{
	Validator v;
	v.isValidPassword(password);
}

void Service::verifyConfirmPassword(std::string password, std::string confirmPassword)
{
	Validator v;
	v.arePasswordsEqual(password, confirmPassword);
}

void Service::verifyResetCode(std::string resetCode)
{
	Validator v;
	v.isValidResetCode(resetCode);
}

User Service::getUserByUsername(std::string username)
{
	return this->userRepository.getUserByUsername(username);
}

void Service::addPostByUser(std::string title, std::string content, User user)
{
	int userId = userRepository.getUserIdByUsername(user.getUsername());
	Post newPost(userId, title, content, user.getUsername());
	postRepository.addPost(newPost);
}

std::vector<Post> Service::requestPosts(int number)
{
	vector<Post> requestedPosts;
	auto result = postRepository.getPostsByPagination(postOffset, number);
	
	while (result->next())
	{
		int authorId = result->getInt("author_id");
		string title = result->getString("title");
		string content = result->getString("content");
		int likes = result->getInt("likes");
		string times = result->getString("time");
		vector<string> tokens = tokenize(times, ' ');
		vector<string> date = tokenize(tokens[0], '-');
		vector <string> time = tokenize(tokens[1], ':');

		
		Date postDate(stoi(date[2]), stoi(date[1]), stoi(date[0]), stoi(time[0]), stoi(time[1]), stoi(time[2]));
		string username = this->userRepository.getUsernameById(authorId);
		Post post(authorId, title, content, postDate, likes, username);
		requestedPosts.push_back(post);
		postOffset++;
	}
	
	return requestedPosts;
}





