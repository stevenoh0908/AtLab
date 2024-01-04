/*************************************************
*   				timecntl.h				     *
**************************************************
* Header file for managing time information.     *
*************************************************/

// Constants
const time_t TIME_INVALID = -1;
const time_t TIME_ADDEND_YEAR = 1900;
const time_t TIME_ADDEND_MONTH = 1;

// Limiting Constants
const time_t MIN_SECOND = 0;
const time_t MAX_SECOND = 59;
const time_t MIN_MINUTE = 0;
const time_t MAX_MINUTE = 59;
const time_t MIN_HOUR = 0;
const time_t MAX_HOUR = 23;
const time_t MIN_DATE = 1;
const time_t MIN_MONTH = 1;
const time_t MAX_MONTH = 12;
const time_t MIN_YEAR = 0;
const time_t MAX_YEAR = 9999;
const time_t MIN_WEEKDAY = 0; // Sun.
const time_t MAX_WEEKDAY = 6; // Sat.

// Structures
typedef enum MonthInfo {
	JAN = 1,
	FEB = 2,
	MAR = 3,
	APR = 4,
	MAY = 5,
	JUN = 6,
	JUL = 7,
	AUG = 8,
	SEP = 9,
	OCT = 10,
	NOV = 11,
	DEC = 12
} Month;

typedef enum DaysInMonthInfo {
	DAYS_IN_JAN = 31,
	DAYS_IN_FEB = 28,
	DAYS_IN_FEB_LEAP = 29,
	DAYS_IN_MAR = 31,
	DAYS_IN_APR = 30,
	DAYS_IN_MAY = 31,
	DAYS_IN_JUN = 30,
	DAYS_IN_JUL = 31,
	DAYS_IN_AUG = 31,
	DAYS_IN_SEP = 30,
	DAYS_IN_OCT = 31,
	DAYS_IN_NOV = 30,
	DAYS_IN_DEC = 31
} DaysInMonth;

typedef enum WeekdayInfo {
	WEEKDAY_INVALID = -1,
	WEEKDAY_SUN = MIN_WEEKDAY,
	WEEKDAY_MON,
	WEEKDAY_TUE,
	WEEKDAY_WED,
	WEEKDAY_THU,
	WEEKDAY_FRI,
	WEEKDAY_SAT
} Weekday;

struct TimeInfo {
	time_t second; // second, 0 to 59
	time_t minute; // minute, 0 to 59
	time_t hour; // hour, 0 to 23
	time_t date; // date, 0 to 31, depending on the current year and month
	time_t month; // month, 1 to 12
	time_t year; // year
	Weekday weekday; // weekday: 0 - Sun to 6 - Sat
};

// Get Current Time Information
struct TimeInfo getCurrentTimeInfo(void);

// Get Each Element of Current Time Information
time_t getCurrentSecond(void);
time_t getCurrentMinute(void);
time_t getCurrentHour(void);
time_t getCurrentDate(void);
time_t getCurrentMonth(void);
time_t getCurrentYear(void);
Weekday getCurrentWeekday(void);

// Check Validity of Time Information
// - Each method will return 1 if the given information is valid, otherwise 0.
int isValidTimeInfo(struct TimeInfo timeInfo);
int isValidSecond(time_t second);
int isValidMinute(time_t minute);
int isValidHour(time_t hour);
int isValidDate(time_t date, time_t month, time_t year);
int isValidMonth(time_t month);
int isValidYear(time_t year);
int isValidWeekday(time_t weekday);

// Check if the given year is leap-year
int isLeapYear(time_t year);
