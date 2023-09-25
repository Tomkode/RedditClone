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
    prep_stmt = connection->prepareStatement("INSERT INTO Users (username, password, email, resetcode) VALUES (?, ?, ?, ?)");
    prep_stmt->setString(1, newUser.getUsername());
    prep_stmt->setString(2, newUser.getPassword());
    prep_stmt->setString(3, newUser.getEmail());
    prep_stmt->setString(4, newUser.getResetCode());
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
        std::string resetCode = res->getString("resetcode").asStdString();
        int userId = res->getInt("user_id");
        User foundUser(userId, userName, password, email, resetCode);
        delete prep_stmt;
        closeConnection();
        return foundUser;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        throw InexistentAcccountException();
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
        std::string resetCode = res->getString("resetcode").asStdString();
        User foundUser(userName, password, email, resetCode);
        delete prep_stmt;
        closeConnection();
        return foundUser;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        throw InexistentAcccountException();
    }
}

int userRepository::getUserIdByUsername(std::string username)
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
        int userId = res->getInt("user_id");
        delete prep_stmt;
        closeConnection();
        return userId;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        throw InexistentAcccountException();
    }
}

std::string userRepository::getUsernameById(int id)
{
    makeConnection();
    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    prep_stmt = connection->prepareStatement("SELECT * FROM users WHERE user_id = ?");
    prep_stmt->setInt(1, id);
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        std::string username = res->getString("username");
        delete prep_stmt;
        closeConnection();
        return username;
    }
    else
    {
        delete prep_stmt;
        closeConnection();
        throw InexistentAcccountException();
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

void userRepository::changePassword(std::string userName, std::string newPassword)
{
    makeConnection();
    connection->setSchema("Reddit");
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("UPDATE Users SET password = ? WHERE username = ?");

    prep_stmt->setString(1, newPassword);
    prep_stmt->setString(2, userName);
    prep_stmt->executeQuery();
    delete prep_stmt;
    closeConnection();
}
