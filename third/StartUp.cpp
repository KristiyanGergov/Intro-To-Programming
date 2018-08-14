#include <iostream>
#include <string>
#include "cstring"

using namespace std;

const int startYear = 2000;

const int yearDays = 365;

const int weekDays = 7;

const int defaultUndefinedValue = -858993460;

int getDayCountByMonth(int month) {
	//the months till the current are full, so our count is the month -1
	int count = (month - 1) * 31;

	//if containing February
	if (month >= 2)
		count -= 2;

	//remove one from all of the months that have 30 days
	count -= month / 2;

	//increment count by 1 since the logic changes for months that are greater than 8
	if (month >= 8 && month % 2 == 0)
		count++;
	return count;
}

int getDayCountByYear(int year) {
	int diff = year - startYear;

	//add one because 2000 is a leap year
	int leapYears = diff / 4 + 1;

	//add yearDays since 2000 does not enter in the diff
	return diff * 365 + leapYears + yearDays;
}

int main()
{
	char firstDelimeter;
	char secondDelimeter;
	int day;
	int month;
	int year;

	bool validate = false;

	cout << "Enter date in format dd.MM.yyyy: ";

	//validation
	while (!validate)
	{
		cin >> day >> firstDelimeter >> month >> secondDelimeter >> year;
		if (day == defaultUndefinedValue || month == defaultUndefinedValue || year == defaultUndefinedValue)
		{
			cout << "Invalid format" << endl;
			break;
		}

		if (day < 1 || day > 31)
		{
			cout << "Invalid day. Day must be a valid number and in the following range: 1 <= day <= 31" << endl;
			cout << "Please try again: ";
			continue;
		}
		if (month < 1 || month > 12)
		{
			cout << "Invalid month. Month must be a valid number and in the following range: 1 <= month <= 12" << endl;
			cout << "Please try again: ";
			continue;
		}
		if (year < 2000)
		{
			cout << "Invalid year. Year must be a valid number and greater than 2000" << endl;
			cout << "Please try again: ";
			continue;
		}
		if (firstDelimeter != 46 && secondDelimeter != 46)
		{
			cout << "Invalid format" << endl;
			cout << "Please try again: ";
			continue;
		}
		validate = true;
	}

	if (validate)
	{
		int totalDays = getDayCountByYear(year);
		int totalDaysForTheYear = getDayCountByMonth(month) + day;
		totalDays -= (yearDays - totalDaysForTheYear);

		cout << totalDays / weekDays << endl;
	}

	return 0;
}