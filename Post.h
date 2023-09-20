#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "Comment.h"
#include "Date.h"
class Post
{
private:
	int author_id;
	std::string title;
	std::string text;
	std::string postDate;
	Date time;
	int likes;
	std::vector<std::string> tags;
	std::vector<Comment> comments;
	std::string username;
public:
	Post();
	~Post();
	Post(int author_id, std::string title, std::string text,std::string username);
	Post(int author_id, std::string title, std::string text, Date time, int likes,std::string username);
	int getAuthorId();
	std::string getAuthorUsername();
	std::string getTitle();
	std::string getText();
	Date getTime();
	int getLikes();
	std::vector<std::string> getTags();
	std::vector<Comment> getComments();
	/*void setAuthor(std::string author);*/
	void setTitle(std::string title);
	void setText(std::string text);
	/*void setTime(std::time_t time);*/
	void setLikes(int likes);
	void addTag(std::string tag);
};

