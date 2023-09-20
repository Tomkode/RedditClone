#pragma once
#include <ctime>
#include <string>

class Date {
private:
	int month;
	int day;
	int year;
	int hour;
	int second;
	int minute;
	time_t timeStruct;
public:
	Date(int day, int month, int year, int hour, int minute, int second);
	Date();
	int getDay();
	int getMonth();
	int getYear();
	std::string getUTCTime();
	void updateTime();
	std::string getUTCDateForMysql();
};
