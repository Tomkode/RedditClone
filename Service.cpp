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
    verifyAccountUniqueness(userName);
	v.isValidEmail(email);
    verifyAccountUniqueness("", email);
	v.isValidPassword(password);
	v.arePasswordsEqual(password, confirmPassword);
	
	string hashedPassword = this->hashToSHA256(password);
	addToDatabase(userName, hashedPassword, email);
}

void Service::addToDatabase(std::string userName, std::string hashedPass, std::string email)
{
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "admin");
    con->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    try {
        
        prep_stmt = con->prepareStatement("INSERT INTO Users (username, password, email) VALUES (?, ?, ?)");
        prep_stmt->setString(1, userName);
        prep_stmt->setString(2, hashedPass);
        prep_stmt->setString(3, email);
        prep_stmt->execute();
        

    }
    catch (...) {
        ;
    }
    delete prep_stmt;
    delete con;
}

void Service::verifyAccountCredentials(std::string userName, std::string hashedPass)
{
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::ResultSet* res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "admin");
    con->setSchema("Reddit");

    sql::PreparedStatement* prep_stmt;
    prep_stmt = con->prepareStatement("SELECT COUNT(*) FROM Users WHERE username = ? AND password = ?");
    prep_stmt->setString(1, userName);
    prep_stmt->setString(2, hashedPass);
    res = prep_stmt->executeQuery();

    if (res->next()) {
        int matchingCount = res->getInt(1);
        if (matchingCount == 0)
            throw AccountInexistentException();
    }

    delete prep_stmt;
    delete con;
    delete res;
}

void Service::verifyAccountUniqueness(std::string userName, std::string email)
{
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::ResultSet* res;
    //smart pointers might be needed

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "admin");
    con->setSchema("Reddit");

    sql::PreparedStatement* prep_stmt;
    if (userName != "")
    {
        prep_stmt = con->prepareStatement("SELECT COUNT(*) FROM Users WHERE username = ?");
        prep_stmt->setString(1, userName);
        res = prep_stmt->executeQuery();

        if (res->next()) {
            int matchingCount = res->getInt(1);
            if (matchingCount == 1)
                throw ExistentUsernameException();
        }
        delete prep_stmt;
        delete con;
        delete res;
        return;
    }
    if(email!="")
    {
        prep_stmt = con->prepareStatement("SELECT COUNT(*) FROM Users WHERE email = ?");
        prep_stmt->setString(1, email);
        res = prep_stmt->executeQuery();
        if (res->next()) {
            int matchingCount = res->getInt(1);
            if (matchingCount == 1)
                throw ExistentEmailException();
        }
        delete prep_stmt;
        delete con;
        delete res;
        return;
    }
    
}


//*************
//tests for hash function
