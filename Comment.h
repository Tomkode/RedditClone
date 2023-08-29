#pragma once
#include <string>
#include <vector>
#include <ctime>
class Comment
{
private:
	std::string author;
	std::string text;
	std::vector<Comment> replies;
	std::time_t time;
public:
	Comment();
	~Comment();
	Comment(std::string author, std::string text);
	std::string getAuthor();
	std::string getText();
	std::vector<Comment> getReplies();
	std::time_t getTime();
	void addReply(Comment reply);
	void setAuthor(std::string author);
	void setText(std::string text);
	void setTime(std::time_t time);

};

