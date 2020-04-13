#include <iostream>
#include <cstring>
#include <iomanip>

#include "time.h"
#include "lib.h"
#include "exception.h"


void Time::SetHours(int hours) {
	if (hours >= 0 && hours < 24) {
		hours_ = hours;
	} else {
<<<<<<< HEAD
		throw DomainError("Domain Error: error in the setting of the hours.");
=======
		throw domain_error();
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
	}
}
void Time::SetMinutes(int minutes) {
	if (minutes >= 0 && minutes < 60) {
		minutes_ = minutes;
	} else {
<<<<<<< HEAD
		throw DomainError("Domain Error: error in the setting of the minutes.");
=======
		throw domain_error();
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
	}
}
void Time::SetSeconds(int seconds) {
	if (seconds >= 0 && seconds < 60) {
		seconds_ = seconds;
	} else {
<<<<<<< HEAD
		throw DomainError("Domain Error: error in the setting of the seconds.");
=======
		throw domain_error();
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c
	}
}



int Time::GetHours() const {
	if (hours_ == -1) {
		std::cout << "время еще не определено\n";
		throw logic_error();
	}
	return hours_;
}
int Time::GetMinutes() const {
	if (minutes_ == -1) {
		std::cout << "время еще не определено\n";
		throw logic_error();
	}
	return minutes_;
}
int Time::GetSeconds() const {
	if (seconds_ == -1) {
		std::cout << "время еще не определено\n";
		throw logic_error();
	}
	return seconds_;
}

void PrintTime(const Time& time) {
	std::cout << std::setfill ('0') << std::setw (2) << time.GetHours() 
							<< ':'  << std::setw (2) << time.GetMinutes() 
							<< ':' << std::setw (2) << time.GetSeconds();
	if (time.GetHours() == 0 && time.GetMinutes() == 0 && time.GetSeconds() == 0) {
		throw Exception("Exception: perhaps the time is not set.");
	}
}

Time ReadTime(Time& time) {
	try {
		char time_str[15];
		std::cin >> time_str;
		int time_array[3];

<<<<<<< HEAD
=======
		bool flag = ParseString(time_array, time_str, '/');  
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c

	
		if (flag) { 
			time.SetHours(time_array[0]);
			time.SetMinutes(time_array[1]);
			time.SetSeconds(time_array[2]);
		}
	} catch (exception& ex) {
		std::cout << "wrong input of time\n";
		throw;
	}
	return time;
}