#include "userRepository.h"


userRepository::userRepository()
{
    driver = sql::mysql::get_mysql_driver_instance();
}

void userRepository::addUser(User newUser)
{
    makeConnection();

    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("INSERT INTO Users (username, password, email) VALUES (?, ?, ?)");
    prep_stmt->setString(1, newUser.getUsername());
    prep_stmt->setString(2, newUser.getPassword());
    prep_stmt->setString(3, newUser.getEmail());
    prep_stmt->execute();
    delete prep_stmt;
    closeConnection();
}

User userRepository::getUserByUsername(std::string username)
{
    makeConnection();
    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    prep_stmt = connection->prepareStatement("SELECT * FROM users WHERE username = ?");
    prep_stmt->setString(1, username);
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        std::string userName = res->getString("username").asStdString();
        std::string password = res->getString("password").asStdString();
        std::string email = res->getString("email").asStdString();
        User foundUser(userName, password, email);
        delete prep_stmt;
        closeConnection();
        return foundUser;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        return User();
    }
}

User userRepository::getUsersByEmail(std::string email)
{
    makeConnection();
    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    prep_stmt = connection->prepareStatement("SELECT * FROM users WHERE email = ?");
    prep_stmt->setString(1, email);
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        std::string userName = res->getString("username").asStdString();
        std::string password = res->getString("password").asStdString();
        std::string email = res->getString("email").asStdString();
        User foundUser(userName, password, email);
        delete prep_stmt;
        closeConnection();
        return foundUser;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        return User();
    }
}

bool userRepository::isUserByUsername(std::string username)
{
    makeConnection();
    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    prep_stmt = connection->prepareStatement("SELECT * FROM users WHERE username = ?");
    prep_stmt->setString(1, username);
    res = prep_stmt->executeQuery();
    if (res->next())
    {
       
        delete prep_stmt;
        closeConnection();
        return true;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        return false;
    }
}

bool userRepository::isUserByEmail(std::string email)
{
    makeConnection();
    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    prep_stmt = connection->prepareStatement("SELECT * FROM users WHERE email = ?");
    prep_stmt->setString(1, email);
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        delete prep_stmt;
        closeConnection();
        return true;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        return false;
    }
}
