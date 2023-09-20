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
    
    prep_stmt = connection->prepareStatement("UPDATE posts SET likes = ? WHERE post_id = ?");
    prep_stmt->setInt(1, newLikes);
    prep_stmt->setInt(2, getPostId(postToUpdate));
    prep_stmt->execute();

    delete prep_stmt;
    closeConnection();
}

int postRepository::getPostId(Post post)
{
    makeConnection();
    
    sql::ResultSet* res;
    sql::PreparedStatement* prep_stmt;
    prep_stmt = connection->prepareStatement("SELECT * FROM Posts WHERE title = ?, author_id = ?, content = ?, likes = ?, time = ?");
    prep_stmt->setString(1, post.getTitle());
    prep_stmt->setString(3, post.getText());
    prep_stmt->setInt(2, post.getAuthorId());
    prep_stmt->setInt(4, post.getLikes());
    prep_stmt->setString(4, post.getTime().getUTCDateForMysql());
    res = prep_stmt->executeQuery();
    if (res->next())
    {
        return res->getInt("post_id");
    }
    else {
        throw exception();
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
    return res;
}


