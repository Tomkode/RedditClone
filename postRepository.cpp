#include "postRepository.h"
#include "Utils.h"

using namespace std;
postRepository::postRepository()
{
    driver = sql::mysql::get_mysql_driver_instance();
}
void postRepository::addPost(Post post)
{
	makeConnection();

    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("INSERT INTO Posts(title, content, author_id, time) VALUES (?, ?, ?, ?)");
    prep_stmt->setString(1, post.getTitle());
    prep_stmt->setString(2, post.getText());
    prep_stmt->setInt(3, post.getAuthorId());

    string mysqlUtcTime = post.getTime().getUTCDateForMysql();
    prep_stmt->setString(4, mysqlUtcTime);


    prep_stmt->execute();
    delete prep_stmt;
    
    closeConnection();
}

void postRepository::updateLikes(Post postToUpdate, int newLikes)
{
    makeConnection();
    sql::PreparedStatement* prep_stmt;
    
    prep_stmt = connection->prepareStatement("UPDATE posts SET likes = likes + ? WHERE post_id = ?");
    prep_stmt->setInt(1, newLikes);
    prep_stmt->setInt(2, getPostId(postToUpdate));
    prep_stmt->execute();

    delete prep_stmt;
    closeConnection();
}

void postRepository::addUPI(int userId, Post post, int value)
{
    makeConnection();
    sql::ResultSet* res;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* result;
    prep_stmt = connection->prepareStatement("INSERT INTO user_likes(user_id, post_id, like_val) VALUES(?, ?, ?)");
   

    prep_stmt->setInt(1, userId);
    prep_stmt->setInt(2, this->getPostId(post));
    prep_stmt->setInt(3, value);
    prep_stmt->execute();
 
    delete prep_stmt;
    closeConnection();
}

void postRepository::updateUPI(int userId, Post post, int newValue)
{
    makeConnection();
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("UPDATE user_likes SET like_val = ? WHERE user_id = ? AND post_id = ?");
    prep_stmt->setInt(1, newValue);
    prep_stmt->setInt(2, userId);
    prep_stmt->setInt(3, getPostId(post));
    int successValue = prep_stmt->executeUpdate();
    closeConnection();
    delete prep_stmt;
}

int postRepository::getUPIvalue(int userId, Post post)
{
    makeConnection();
    sql::ResultSet* res;
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("SELECT * FROM user_likes where user_id = ? AND post_id = ?");
    prep_stmt->setInt(1, userId);
    prep_stmt->setInt(2, getPostId(post));
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        return res->getInt("like_val");

    }
    
    delete prep_stmt;
    closeConnection();
    return 0;
}

int postRepository::getPostId(Post post)
{
    makeConnection();
    
    sql::ResultSet* res;
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("SELECT * FROM Posts WHERE title = ? AND author_id = ? AND content = ? AND likes = ? AND time = ?");
    prep_stmt->setString(1, post.getTitle());
    prep_stmt->setInt(2, post.getAuthorId());
    prep_stmt->setString(3, post.getText());
    prep_stmt->setInt(4, post.getLikes());
    prep_stmt->setString(5, post.getTime().getUTCDateForMysql());
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        return res->getInt("post_id");
    }
    else {
        return 0;
    }

    delete prep_stmt;
    closeConnection();


}

sql::ResultSet* postRepository::getPostsByPagination(int offset, int requestSize)
{
    makeConnection();
    sql::ResultSet* res;
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("SELECT * FROM Posts LIMIT ? OFFSET ?");
    prep_stmt->setInt(1, requestSize);
    prep_stmt->setInt(2, offset);
    res = prep_stmt->executeQuery();
    closeConnection();
    return res;
}


