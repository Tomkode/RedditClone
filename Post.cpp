#include "Post.h"

Post::Post()
{
    author_id = 0;
    title = "";
    text = "";
    time = Date();
    likes = 0;

}

Post::~Post()
{
}

Post::Post(int author_id, std::string title, std::string text, std::string username)
{
    this->author_id = author_id;
    this->username;
    this->title = title;
    this->text = text;
    this->likes = 0;
    this->time = Date();
    this->username = username;
}

Post::Post(int author_id, std::string title, std::string text, Date time, int likes,std::string username)
{
    this->author_id = author_id;
    this->title = title;
    this->text = text;
    this->likes = likes;
    this->time = time;
    this->username = username;
}

int Post::getAuthorId()
{
    return author_id;
}

std::string Post::getAuthorUsername()
{
    return username;
}

std::string Post::getTitle()
{
    return title;
}

std::string Post::getText()
{
    return text;
}

Date Post::getTime()
{
    return this->time;
}

int Post::getLikes()
{
    return likes;
}

std::vector<std::string> Post::getTags()
{
    return tags;
}

std::vector<Comment> Post::getComments()
{
    return comments;
}

//void Post::setAuthor(std::string author)
//{
//    this->author = author;
//}

void Post::setTitle(std::string title)
{
    this->title = title;
}

void Post::setText(std::string text)
{
    this->text = text;
}

//void Post::setTime(std::time_t time)
//{
//    this->time = time;
//}

void Post::setLikes(int likes)
{
    this->likes = likes;
}

void Post::addTag(std::string tag)
{
    this->tags.push_back(tag);
}
