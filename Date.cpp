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

	struct tm utc;
	utc.tm_year = year - 1900;
	
	utc.tm_mon = month - 1;
	utc.tm_mday = day;
	utc.tm_hour = hour;
	utc.tm_min = minute;
	utc.tm_sec = second;
	utc.tm_isdst = 0;
	timeStruct = _mkgmtime(&utc);
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



time_t Date::getTime_T()
{
	return timeStruct;
}

int operator-(Date bigDate, Date smallDate)
{
	return difftime(bigDate.getTime_T(), smallDate.getTime_T());
}
