#include <iostream>
#include <cstring>
#include <iomanip>

#include "date.h"
#include "lib.h"
#include "exception.h"

bool Date::IsLeapYear() const {
	if ((year_%4 == 0 && year_%100 != 0) || (year_%400 == 0)){
        return true;;
    }
    else {
        return false;
    }
}

void Date::SetDay(int day) {
	int capacity[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	capacity[1] = ((IsLeapYear()) ? 29 : 28);
	if (day > 0 && day <= 31 && day <= capacity[month_-1]) {
		day_ = day;
	} else {
		throw domain_error();
	}
}

void Date::SetMonth(int month) {
	int capacity[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	capacity[1] = (IsLeapYear()?29:28);
	if (month > 0 && month <= 12 && day_ < capacity[month-1]) {
		month_ = month;
	} else {
		throw domain_error();
	}
}


void Date::SetYear(int year) {
	if (!(IsLeapYear()) && day_ == 29 && month_ == 2) { 
//		day_ = 1;
//		month_ = 1;
		throw domain_error();
	}
	year_ = year;
}

int Date::GetDay() const {
	if (day_ == 0) {
		std::cout << "дата еще не определена\n";
		throw logic_error();
	}
	return day_;
}
int Date::GetMonth() const {
	if (month_ == 0) {
		std::cout << "дата еще не определена\n";
		throw logic_error();
	}
	return month_;
}
int Date::GetYear() const {
	if (year_ == 0) {
		std::cout << "дата еще не определена\n";
		throw logic_error();
	}
	return year_;
}


void PrintDate(const Date& date) {
	std::cout << std::setfill('0') << std::setw(2) << date.GetDay() << '.' << std::setw(2) << date.GetMonth() << '.' << date.GetYear();
}

Date ReadDate(Date& date) {
	char date_str[15]; 
	std::cin >> date_str;
	int date_array[3]; 

	bool flag = ParseString(date_array, date_str, '/');  
	try {
		if (flag) { 
			date.SetDay(date_array[0]);
			date.SetMonth(date_array[1]);
			date.SetYear(date_array[2]);
		} 	
	} catch (exception& ex) {
		std::cout << "wrong input of date\n";
		throw;
	}

	return date;
}