#include "Date.h"

using namespace std;


Date::Date(int day, int month, int year, int hour, int minute, int second)
{
	this->month = month;
	this->year = year;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

Date::Date()
{
	timeStruct = time(0);
	tm* UTCtime = gmtime(&timeStruct);
	this->month = UTCtime->tm_mon + 1;
	this->day = UTCtime->tm_mday;
	this->year = UTCtime->tm_year + 1900;
	this->hour = UTCtime->tm_hour;
	this->minute = UTCtime->tm_min;
	this->second = UTCtime->tm_sec;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

std::string Date::getUTCTime()
{
	string curr_time = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	return curr_time;
}

void Date::updateTime()
{
	time_t timeStruct = time(0);
	tm* UTCtime = gmtime(&timeStruct);
	this->month = UTCtime->tm_mon + 1;
	this->day = UTCtime->tm_mday;
	this->year = UTCtime->tm_year + 1900;
	this->hour = UTCtime->tm_hour;
	this->minute = UTCtime->tm_min;
	this->second = UTCtime->tm_sec;
}

std::string Date::getUTCDateForMysql()
{
	
	tm* UTCtime = gmtime(&timeStruct);

	char buffer[32];
	strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", UTCtime);
	string mysqlFormat(buffer);
	return mysqlFormat;
}
