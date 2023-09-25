#pragma once
#include "User.h"
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "ValidatorException.h"

class userRepository
{
private:

	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	void makeConnection(){
		connection = driver->connect("tcp://mariola.mysql.database.azure.com", "mariola", "Admin69!");
	}
    void closeConnection()
    {
        delete connection;
    }
public:
	userRepository();
	void addUser(User newUser);
	User getUserByUsername(std::string username);
	User getUsersByEmail(std::string email);
	int getUserIdByUsername(std::string username);
	std::string getUsernameById(int id);
	bool isUserByUsername(std::string username);
	bool isUserByEmail(std::string email);
	void changePassword(std::string userName,std::string newPassword);
};

