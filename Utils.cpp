#include "Utils.h"


std::vector<std::string> tokenize(std::string toTokenize, char separator)
{
	std::stringstream ss(toTokenize);
	std::vector<std::string> tokens;
	std::string token;
	while (getline(ss, token, separator))
	{
		tokens.push_back(token);
	}
	return tokens;
}
