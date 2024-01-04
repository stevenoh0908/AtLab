/****************************************************
*					timecntl.c						*
*****************************************************
* Source file for managing time information.		*
****************************************************/

// Include Required Headers
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _TIMECNTL_H_
	#define _TIMECNTL_H_
	#include "timecntl.h"
#endif

// Methods

// Get Current Time Information
// - Returns struct TimeInfo filled with all TIME_INVALID (WEEKDAY_INVALID for weekday) constant if fails.
//   Otherwise, return struct TimeInfo filled with current system time information.
struct TimeInfo getCurrentTimeInfo(void) {
	struct TimeInfo timeInfo;
	time_t now;
	struct tm* currentTime;

	timeInfo.second = TIME_INVALID;
	timeInfo.minute = TIME_INVALID;
	timeInfo.hour = TIME_INVALID;
	timeInfo.date = TIME_INVALID;
	timeInfo.month = TIME_INVALID;
	timeInfo.year = TIME_INVALID;
	timeInfo.weekday = WEEKDAY_INVALID;

	now = time(NULL);
	if (now == TIME_INVALID) return timeInfo;
	currentTime = localtime(&now);
	if (currentTime == NULL) return timeInfo;

	timeInfo.second = currentTime->tm_sec;
	timeInfo.minute = currentTime->tm_min;
	timeInfo.hour = currentTime->tm_hour;
	timeInfo.date = currentTime->tm_mday;
	timeInfo.month = currentTime->tm_mon + TIME_ADDEND_MONTH;
	timeInfo.year = currentTime->tm_year + TIME_ADDEND_YEAR;
	timeInfo.weekday = currentTime->tm_wday;

	return timeInfo;
}

// Get Current Second
// - Returns TIME_INVALID if fetching current time is failed, otherwise return current time in time_t.
time_t getCurrentSecond(void) {
	time_t now;
	struct tm* currentTime;

	now = time(NULL);
	if (now == TIME_INVALID) return TIME_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return TIME_INVALID;
	return currentTime->tm_sec;
}

// Get Current Minute
// - Returns TIME_INVALID if fetching current time is failed, otherwise return current minute.
time_t getCurrentMinute(void) {
	time_t now;
	struct tm* currentTime;

	now = time(NULL);
	if (now == TIME_INVALID) return TIME_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return TIME_INVALID;
	return currentTime->tm_min;
}

// Get Current Hour
// - Returns TIME_INVALID if fetching current hour is failed, otherwise return current hour.
time_t getCurrentHour(void) {
	time_t now;
	struct tm* currentTime;

	now = time(NULL);
	if (now == TIME_INVALID) return TIME_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return TIME_INVALID;
	return currentTime->tm_hour;
}

// Get Current Date
// - Return TIME_INVALID if fetching current date is failed, otherwise return current date.
time_t getCurrentDate(void) {
	time_t now;
	struct tm* currentTime;

	now = timer(NULL);
	if (now == TIME_INVALID) return TIME_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return TIME_INVALID;
	return currentTime->tm_mday;
}

// Get Current Month
// - Return TIME_INVALID if fetching current month is failed, otherwise return current month.
time_t getCurrentMonth(void) {
	time_t now;
	struct tm* currentTime;

	now = time(NULL);
	if (now == TIME_INVALID) return TIME_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return TIME_INVALID;
	return currentTime->tm_mon + TIME_ADDEND_MONTH;
}

// Get Current Year
// - Return TIME_INVALID if fetching current year is failed, otherwise return current year.
time_t getCurrentYear(void) {
	time_t now;
	struct tm* currentTime;

	now = time(NULL);
	if (now == TIME_INVALID) return TIME_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return TIME_INVALID;
	return currentTime->tm_year + TIME_ADDEND_YEAR;
}

// Get Current Weekday
// - Return WEEKDAY_INVALID if fetching current weekday is failed, otherwise return current Weekday as enum WeekdayInfo (Weekday)
Weekday getCurrentWeekday(void) {
	time_t now;
	struct tm* currentTime;

	now = time(NULL);
	if (now == TIME_INVALID) return WEEKDAY_INVALID;
	currentTime = localtime(&now);
	if (currentTime == NULL) return WEEKDAY_INVALID;
	return (Weekday) currentTime->tm_wday;
}

// Check Validity of Second
// - Returns 1 if the given second is valid, otherwise 0.
int isValidSecond(time_t second) {
	return (MIN_SECOND <= second) && (second <= MAX_SECOND);
}

// Check Validity of Minute
// - Returns 1 if the given minute is valid, otherwise 0.
int isValidMinute(time_t minute) {
	return (MIN_MINUTE <= second) && (second <= MAX_MINUTE);
}

// Check Validity of Hour
// - Returns 1 if the given hour is valid in 24-hourly format, otherwise 0.
int isValidHour(time_t hour) {
	return (MIN_HOUR <= hour) && (hour <= MAX_HOUR);
}

// Check Validity of Date
// - Returns 1 if the given date is valid in respect to the given month and the year, otherwise 0.
int isValidDate(time_t date, time_t month, time_t year) {
	if (!isValidMonth(month) || !isValidYear(year)) return 0;
	switch(month) {
		case JAN:
			return (MIN_DATE <= date) && (date <= DAYS_IN_JAN);
		case FEB:
			if (isLeapYear(year)) return (MIN_DATE <= date) && (date <= DAYS_IN_FEB_LEAP);
			else return (MIN_DATE <= date) && (date <= DAYS_IN_FEB);
		case MAR:
			return (MIN_DATE <= date) && (date <= DAYS_IN_MAR);
		case APR:
			return (MIN_DATE <= date) && (date <= DAYS_IN_APR);
		case MAY:
			return (MIN_DATE <= date) && (date <= DAYS_IN_MAY);
		case JUN:
			return (MIN_DATE <= date) && (date <= DAYS_IN_JUN);
		case JUL:
			return (MIN_DATE <= date) && (date <= DAYS_IN_JUL);
		case AUG:
			return (MIN_DATE <= date) && (date <= DAYS_IN_AUG);
		case SEP:
			return (MIN_DATE <= date) && (date <= DAYS_IN_SEP);
		case OCT:
			return (MIN_DATE <= date) && (date <= DAYS_IN_OCT);
		case NOV:
			return (MIN_DATE <= date) && (date <= DAYS_IN_NOV);
		case DEC:
			return (MIN_DATE <= date) && (date <= DAYS_IN_DEC);
	}
}

// Check Validity of Month
// - Return 1 if the given month is valid, otherwise 0.
int isValidMonth(time_t month) {
	return (MIN_MONTH <= month) && (month <= MAX_MONTH);
}

// Check Validity of Year
// - Return 1 if the given year is valid (between MIN_YEAR and MAX_YEAR), otherwise 0.
int isValidYear(time_t year) {
	return (MIN_YEAR <= year) && (year <= MAX_YEAR);
}

// Check Validity of Weekday
// - Return 1 if the given weekday is valid (between MIN_WEEKDAY and MAX_WEEKDAY), otherwise 0.
int isValidWeekday(time_t weekday) {
	return (MIN_WEEKDAY <= weekday) && (weekday <= MAX_WEEKDAY);
}

// Check Validity of the given struct TimeInfo
// - Return 1 if the given TimeInfo structure is valid, otherwise 0.
int isValidTimeInfo(struct TimeInfo timeInfo) {
	return (isValidSecond(timeInfo.second)) &&
		   (isValidMinute(timeInfo.minute)) &&
		   (isValidHour(timeInfo.hour)) &&
           (isValidDate(timeInfo.date, timeInfo.month, timeInfo.year)) &&
		   (isValidMonth(timeInfo.month)) &&
		   (isValidYear(timeInfo.year)) &&
		   (isValidWeekday((time_t) timeInfo.weekday));
}

// Check if the given year is leap-year
// - Return 1 if the given year is leap-year, otherwise 0.
int isLeapYear(time_t year) {
	return !((year % 100 == 0) && (year % 400 != 0) || (year % 4 != 0))
}
