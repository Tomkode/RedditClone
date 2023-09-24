#pragma once

#include "Post.h"
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "ValidatorException.h"

class postRepository
{
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* connection;
    void makeConnection() {
        connection = driver->connect("tcp://127.0.0.1:3306", "root", "admin");
        connection->setSchema("Reddit");
    }
    void closeConnection()
    {
        delete connection;
    }
public:
    postRepository();
    void addPost(Post post);
    void updateLikes(Post postToUpdate, int newLikes);
    void addUserPostInteraction(int userId, Post post, int value);
    int getPostId(Post post);
    sql::ResultSet* getPostsByPagination(int offset, int requestSize);
};

