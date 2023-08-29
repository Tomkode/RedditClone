#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "Comment.h"
class Post
{
private:
	std::string author;
	std::string title;
	std::string text;
	std::time_t time;
	int likes;
	std::vector<std::string> tags;
	std::vector<Comment> comments;
public:
	Post();
	~Post();
	Post(std::string author, std::string title, std::string text);
	std::string getAuthor();
	std::string getTitle();
	std::string getText();
	std::time_t getTime();
	int getLikes();
	std::vector<std::string> getTags();
	std::vector<Comment> getComments();
	void setAuthor(std::string author);
	void setTitle(std::string title);
	void setText(std::string text);
	void setTime(std::time_t time);
	void setLikes(int likes);
	void addTag(std::string tag);
	void addComment(Comment comment);
};

