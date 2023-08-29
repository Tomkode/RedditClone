#include "Post.h"

Post::Post()
{
    author = "";
    title = "";
    text = "";
    time = 0;
    likes = 0;

}

Post::~Post()
{
}

Post::Post(std::string author, std::string title, std::string text)
{
    this->author = author;
    this->title = title;
    this->text = text;
    this->likes = 0;
    this->time = std::time(NULL);
}

std::string Post::getAuthor()
{
    return author;
}

std::string Post::getTitle()
{
    return title;
}

std::string Post::getText()
{
    return text;
}

std::time_t Post::getTime()
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

void Post::setAuthor(std::string author)
{
    this->author = author;
}

void Post::setTitle(std::string title)
{
    this->title = title;
}

void Post::setText(std::string text)
{
    this->text = text;
}

void Post::setTime(std::time_t time)
{
    this->time = time;
}

void Post::setLikes(int likes)
{
    this->likes = likes;
}

void Post::addTag(std::string tag)
{
    this->tags.push_back(tag);
}

void Post::addComment(Comment comment)
{
    this->comments.push_back(comment);
}
