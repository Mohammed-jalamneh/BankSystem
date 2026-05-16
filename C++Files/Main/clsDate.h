#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "clsString.h"

using namespace std;

string GetSystemDate();

class clsDate
{

private:

	short _Day;
	short _Month;
	short _Year;

	string _DayFromTheBeginningOfTheYear;

	static bool IsOddNumber(int Number)
	{
		return Number % 2 != 0;
	}

public:

	//Constructors

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{

		vector <string> vDate;
		vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short DateOrderInYear, short Year)
	{
		//This will construct a date by date order in year
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
	}


	//System Date

	static clsDate GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}

	static void PrintDate(clsDate Date)
	{
		cout << Date._Day << "/" << Date._Month << "/" << Date._Year;
	}

	void PrintDate()
	{
		PrintDate(*this);
	}


	//Problem 3

	static bool IsLeapYear(int Year)
	{
		return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	//Problem 4

	static int NumberOfDaysInYear(int UserYear)
	{

		if (IsLeapYear(UserYear))
		{
			return 366;
		}
		else {
			return  365;
		}

	}
	static void DaysHoursMinutesSecondsForAyear(int UserYear)
	{

		int Hourse, Minutes;
		double Seconds;

		cout << "Number Of Days in Year [" << UserYear << "] is "
			<< NumberOfDaysInYear(UserYear) << endl;

		cout << "Number Of Hourse in Year [" << UserYear << "] is "
			<< NumberOfDaysInYear(UserYear) * 24 << endl;

		cout << "Number Of Minutes in Year [" << UserYear << "] is "
			<< NumberOfDaysInYear(UserYear) * 24 * 60 << endl;

		cout << "Number Of Seconds in Year [" << UserYear << "] is "
			<< NumberOfDaysInYear(UserYear) * 24 * 60 * 60 << endl;


	}

	int NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}
	void DaysHoursMinutesSecondsForAyear()
	{
		DaysHoursMinutesSecondsForAyear(_Year);
	}

	//Problem 5

	static int MonthDays(int UserMonth, int UserYear)
	{
		if (UserMonth < 1 || UserMonth>12)
			return 0;

		int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (UserMonth == 2) ? (IsLeapYear(UserYear) ? 29 : 28) : (Arr[UserMonth - 1]);

	}

	static int MonthDays(clsDate Date)
	{
		if (Date._Month < 1 || Date._Month>12)
			return 0;

		int Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Date._Month == 2) ? (IsLeapYear(Date._Year) ? 29 : 28) : (Arr[Date._Month - 1]);

	}

	int MonthDays()
	{
		return MonthDays(_Month, _Year);
	}

	//Problem 7

	static short DayOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	static void UserBirthdayCard(clsDate Date, short IndexOfDayOrder)
	{
		string Arr[7] = { "Sunday" ,"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

		cout << "\n----------------------------" << endl;
		cout << "Date Analysis" << endl;
		cout << "----------------------------" << endl;
		cout << "Date      :" << Date._Day << "/" << Date._Month << "/" << Date._Year << endl;
		cout << "Day Order :" << IndexOfDayOrder << endl;
		cout << "Day Name  :" << Arr[IndexOfDayOrder] << endl;
		cout << "----------------------------" << endl;


	}
	short DayOrder()
	{
		return DayOrder(_Day, _Month, _Year);
	}
	void UserBirthdayCard()
	{
		UserBirthdayCard((*this), DayOrder());
	}

	//Problem 8

	static string PrintMonth(int Month)
	{
		string MonthsArr[12] = { "Jan" ,"Feb","Mar","Epr","May","Jon","July","Aug","Sep","Oct","Nov","Dec" };

		return MonthsArr[Month - 1];

	}
	string PrintMonth()
	{
		return PrintMonth(_Month);
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};

		return (Months[MonthNumber - 1]);
	}

	string MonthShortName()
	{

		return MonthShortName(_Month);
	}

	static void MonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6
		int current = DayOrder(1, Month, Year);

		NumberOfDays = MonthDays(Month, Year);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}
	void MonthCalendar()
	{
		MonthCalendar(_Year, _Month);
	}

	//Problem 9

	static void YearCalendar(int Year)
	{

		cout << "\n       " << Year << " Year Calendar" << endl;

		int ONEYEAR = 12;

		for (int i = 1; i <= ONEYEAR; i++)
		{
			MonthCalendar(Year, i);
			cout << "\n";
		}

	}
	void YearCalendar()
	{
		YearCalendar(_Year);
	}

	//Problem 10


	static int TotalDaysFromBeginning(clsDate Date)
	{


		int TotalDays = 0;

		for (int i = 1; i <= 12; i++)
		{
			for (int j = 1; j <= MonthDays(Date._Year, i); j++)
			{
				TotalDays++;

				if (i == Date._Month && j == Date._Day)
					return TotalDays;

			}

		}


		return 0;

	}
	int TotalDaysFromBeginning()
	{
		return TotalDaysFromBeginning(*this);
	}

	//Problem 11

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{

		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDay = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDay = MonthDays(Date._Month, Year);

			if (RemainingDays > MonthDay)
			{
				RemainingDays -= MonthDay;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}

		}

		return Date;
	}

	//Problem 12

	static void DateValidationAfterAddingDays(int Year, int NewTotalDays)
	{

		short TempYear = Year;
		short TempMonth = 1;
		short TempDay = 0;

		while (true)
		{
			int daysInMonth = MonthDays(TempYear, TempMonth);

			if (NewTotalDays > daysInMonth)
			{
				NewTotalDays -= daysInMonth;
				TempMonth++;

				if (TempMonth > 12)
				{
					TempMonth = 1;
					TempYear++;
				}
			}
			else
			{
				TempDay = NewTotalDays;
				break;
			}
		}

		cout << TempDay << "/" << TempMonth << "/" << TempYear << endl;
	}
	void DateValidationAfterAddingDays()
	{
		DateValidationAfterAddingDays(_Year, TotalDaysFromBeginning(*this));
	}

	//Problem 13



	//Problem 14

	static bool CheckequalityBetweenDates(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year + Date1._Month + Date1._Day) == (Date2._Year + Date2._Month + Date2._Day);
	}
	bool CheckequalityBetweenDates(clsDate Date2)
	{
		return CheckequalityBetweenDates(*this, Date2);
	}

	//Problem 15

	static bool IsLastDay(clsDate Date)
	{
		short MonthDayss = MonthDays(Date._Year, Date._Month);

		return Date._Day == MonthDayss;
	}
	static bool IsLastMonth(int Month)
	{
		return Month == 12;
	}
	bool IsLastDay()
	{
		return IsLastDay(*this);
	}
	bool IsLastMonth()
	{
		return IsLastMonth(_Month);
	}

	//Problem 16

	static clsDate IncreasingDateByOneDay(clsDate& Date)
	{

		if (IsLastDay(Date))
		{
			Date._Day = 1;

			if (IsLastMonth(Date._Month))
			{
				++Date._Year;
				Date._Month = 1;

			}
			else {
				Date._Month++;
			}

		}
		else {
			Date._Day++;
		}

		return Date;

	}

	//Problem 17

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year ==
			Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month ==
				Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool
		IncludeEndDay = false)
	{


		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreasingDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	//Prbolem 18

	static int YourAgeinDays(clsDate BirthDate)
	{
		return GetDifferenceInDays(BirthDate, GetSystemDate());
	}
	int yourAgeinDays()
	{
		return YourAgeinDays(*this);
	}

	//Problem 20-32

	clsDate IncreaseDateByXDays(clsDate& Date, int DayToAdd)
	{

		for (int i = 1; i <= DayToAdd; i++)
		{
			IncreasingDateByOneDay(Date);
		}

		return Date;

	}
	clsDate IncreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 0; i < 7; i++)
		{
			IncreasingDateByOneDay(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXWeeks(clsDate& Date, int NumberOfWeeks)
	{

		for (int i = 0; i < NumberOfWeeks; i++)
		{
			IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (IsLastMonth(Date._Month))
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short MaxDaysInNewMonth = MonthDays(Date._Month, Date._Year);
		if (Date._Day > MaxDaysInNewMonth)
		{
			Date._Day = MaxDaysInNewMonth;
		}

		return Date;
	}
	clsDate IncreaseDateByXMonth(clsDate& Date, int NumberOfMonths)
	{

		for (int i = 0; i < NumberOfMonths; i++)
		{
			IncreaseDateByOneMonth(Date);
		}

		return Date;
	}
	clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}
	clsDate IncreaseDateByXYears(clsDate& Date, int NumberOfYears)
	{

		for (int i = 0; i < NumberOfYears; i++)
		{
			IncreaseDateByOneYear(Date);
		}


		return Date;
	}
	clsDate IncreaseDateByXYearsFaster(clsDate& Date, short NumberOfYears)
	{
		Date._Year += NumberOfYears;

		if (Date._Month == 2 && Date._Day == 29 && !IsLeapYear(Date._Year))
		{
			Date._Day = 28;
		}

		return Date;
	}
	clsDate IncreaseDateByOneDecade(clsDate& Date)
	{

		IncreaseDateByXYearsFaster(Date, 10);

		return Date;
	}
	clsDate IncreaseDateByXDecades(clsDate& Date, int NumberOfDecades)
	{

		for (int i = 0; i < NumberOfDecades; i++)
		{
			IncreaseDateByOneDecade(Date);
		}


		return Date;
	}
	clsDate IncreaseDateByXDecadesFaster(clsDate& Date, short NumberOfDecades)
	{

		Date._Year += (NumberOfDecades) * 10;
		return Date;
	}
	clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		IncreaseDateByXDecadesFaster(Date, 10);
		return Date;
	}
	clsDate IncreaseDateByXCentury(clsDate& Date, int NumberOfCentury)
	{
		IncreaseDateByXDecadesFaster(Date, (NumberOfCentury) * 10);
		return Date;
	}
	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		IncreaseDateByXCentury(Date, 10);

		return Date;
	}

	//Problemes 33-46

	string WeekDays(int DayOrder)
	{

		string arr[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arr[DayOrder];
	}

	clsDate DecreaseDateByOneDay(clsDate& Date) {

		if (Date._Month == 1) {
			if (Date._Day == 1) {
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else {
				Date._Day--;
			}
		}
		else {



			if (Date._Day == 1)
			{
				Date._Day = MonthDays(Date._Month - 1, Date._Year);
				Date._Month--;
			}
			else
			{
				Date._Day--;
			}

		}
		return Date;
	}
	clsDate DecreaseDateByXDays(clsDate& Date, int DayToDec)
	{

		for (int i = 1; i <= DayToDec; i++)
		{
			DecreaseDateByOneDay(Date);
		}

		return Date;

	}
	clsDate DecreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 0; i < 7; i++)
		{
			DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXWeeks(clsDate& Date, int NumberOfWeeks)
	{

		for (int i = 0; i < NumberOfWeeks; i++)
		{
			DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByOneMonth(clsDate& Date)
	{

		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;

			return Date;
		}

		Date._Month--;

		return Date;
	}
	clsDate DecreaseDateByXMonths(clsDate& Date, int NumberOfMonths)
	{

		for (int i = 0; i < NumberOfMonths; i++)
		{
			DecreaseDateByOneMonth(Date);
		}

		return Date;
	}
	clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date._Year--;
		return Date;
	}
	clsDate DecreaseDateByXYears(clsDate& Date, int NumberOfYears)
	{

		for (int i = 0; i < NumberOfYears; i++)
		{
			DecreaseDateByOneYear(Date);
		}


		return Date;
	}
	clsDate DecreaseDateByXYearsFaster(clsDate& Date, short NumberOfYears)
	{
		Date._Year -= NumberOfYears;

		if (Date._Month == 2 && Date._Day == 29 && !IsLeapYear(Date._Year))
		{
			Date._Day = 28;
		}

		return Date;
	}
	clsDate DecreaseDateByOneDecade(clsDate& Date)
	{

		DecreaseDateByXYearsFaster(Date, 10);

		return Date;
	}
	clsDate DecreaseDateByXDecades(clsDate& Date, int NumberOfDecades)
	{

		for (int i = 0; i < NumberOfDecades; i++)
		{
			DecreaseDateByOneDecade(Date);
		}


		return Date;
	}
	clsDate DecreaseDateByXDecadesFaster(clsDate& Date, short NumberOfDecades)
	{

		Date._Year -= (NumberOfDecades) * 10;
		return Date;
	}
	clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		DecreaseDateByXDecadesFaster(Date, 10);
		return Date;
	}
	clsDate DecreaseDateByXCentury(clsDate& Date, int NumberOfCentury)
	{
		DecreaseDateByXDecadesFaster(Date, (NumberOfCentury) * 10);
		return Date;
	}
	clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		DecreaseDateByXCentury(Date, 10);

		return Date;
	}


	//Problems 47-53

	static bool IsEndOfWeek(clsDate Date)
	{

		if (DayOrder(Date._Day, Date._Month, Date._Year) == 6)
			return true;
		else
			return false;

	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}


	static bool IsWeekEnd(clsDate Date)
	{

		if (DayOrder(Date._Day, Date._Month, Date._Year) >= 4 && DayOrder(Date._Day, Date._Month, Date._Year) <= 6)
			return true;
		else
			return false;


	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{

		if (DayOrder(Date._Day, Date._Month, Date._Year) <= 4 && DayOrder(Date._Day, Date._Month, Date._Year) >= 0)
			return true;
		else
			return false;


	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	unsigned short DaysUntilTheEndOfWeek(clsDate Date)
	{
		short DayWeekss = 6;
		short OrderOfDay = DayOrder(Date._Day, Date._Month, Date._Year);
		short Counter = 0;

		for (OrderOfDay; OrderOfDay < DayWeekss; OrderOfDay++)
		{
			Counter++;
		}

		return Counter;
	}
	unsigned short DaysUntilTheEndOfMonth(clsDate Date)
	{
		short MonthsDay = MonthDays(Date._Month, Date._Year);
		return MonthsDay - Date._Day;
	}
	unsigned short DaysUntilTheEndOfYear(clsDate Date)
	{
		int YearDays = 0;
		if (IsLeapYear(Date._Year))
		{
			YearDays = 366;
		}
		else {
			YearDays = 365;
		}
		return (YearDays - TotalDaysFromBeginning(Date)) + 1;
	}

	//Problem 54

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreasingDateByOneDay(DateFrom);
		}
		return DaysCount;
	}
	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	//Problem 55

	static clsDate DateOfTheEndOfVacation(clsDate Date, short VacationDays)
	{

		clsDate LastDayOfVacation;

		for (int i = 0; i <= VacationDays; i++)
		{
			IncreasingDateByOneDay(Date);

			if (IsWeekEnd(Date))
				VacationDays++;
		}

		LastDayOfVacation = Date;

		return LastDayOfVacation;

	}
	clsDate DateOfTheEndOfVacation(short VacationDays)
	{
		return DateOfTheEndOfVacation(*this, VacationDays);
	}

	//Problem 57

	bool isDate1BeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
		return (Date1._Year == Date2._Year &&
			Date1._Month == Date2._Month &&
			Date1._Day == Date2._Day);
	}
	bool IsDate1EqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}


	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}


	static bool IsValidDate(clsDate Date)
	{
		
		short MonthDayss =  MonthDays(Date);
		if (Date._Day > MonthDayss || Date._Day < 1)
			return false;
		else
			return true;
		
	}
};

