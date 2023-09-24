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
	friend int operator-(Date bigDate, Date smallDate);
	int getDay();
	int getMonth();
	int getYear();
	std::string getUTCTime();
	void updateTime();
	std::string getUTCDateForMysql();
	time_t getTime_T();
};
