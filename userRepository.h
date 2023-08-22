#pragma once
#include "User.h"
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class userRepository
{
private:

	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	void makeConnection(){
        connection = driver->connect("tcp://127.0.0.1:3306", "root", "admin");
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

	

};

