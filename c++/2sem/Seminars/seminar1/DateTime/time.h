#ifndef TIME_H
#define TIME_H


class Time {
<<<<<<< HEAD
	int hours_ = 0;
	int minutes_ = 0;
	int seconds_ = 0;
=======
	int hours_ = -1;
	int minutes_ = -1;
	int seconds_ = -1;
>>>>>>> cbc11e56520a96d754b4efc2e4e7a5925a9d8a3c

public:
	void SetHours(int hours);
	void SetMinutes(int minutes);
	void SetSeconds(int seconds);

	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;
};

void PrintTime(const Time& time);
Time ReadTime(Time& time);
#endif // TIME_H