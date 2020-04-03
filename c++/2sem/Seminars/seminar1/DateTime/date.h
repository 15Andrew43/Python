#ifndef DATE_H
#define DATE_H


class Date {
	int day_ = 1;
	int month_ = 1;
	int year_ = 1;

	bool IsLeapYear() const;

public:
	void SetDay(int day);
	void SetMonth(int month);
	void SetYear(int year);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

};


void PrintDate(const Date& date);
Date ReadDate(Date& date);

#endif // DATE_H