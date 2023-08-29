#include "Comment.h"
using namespace std;
Comment::Comment()
{
    author = "";
    text = "";
    time = 0;

}

Comment::~Comment()
{
}

Comment::Comment(std::string author, std::string text)
{
    this->author = author;
	this->text = text;
	this->time = std::time(NULL); // current time
}

std::string Comment::getAuthor()
{
    return author;
}

std::string Comment::getText()
{
    return text;
}

std::vector<Comment> Comment::getReplies()
{
    return replies;
}

std::time_t Comment::getTime()
{
    return this->time;
}

void Comment::addReply(Comment reply)
{
    replies.push_back(reply);
}

void Comment::setAuthor(std::string author)
{
    this->author = author;
}

void Comment::setText(std::string text)
{
    this->text = text;
}

void Comment::setTime(std::time_t time)
{
    this->time = time;
}
