#ifndef CLOCK_H
#define CLOCK_H

class Clock {

private:
	int hour;
	int z_hour;
	int minutes;
	int seconds;

public:
	// Clock constructor w/ default values
	Clock(int hour = 12, int z_hour = 12, int minutes = 59, int seconds = 50);

	int get_hour() { return hour; }
	int get_z_hour() { return z_hour; }
	int get_minutes() { return minutes; }
	int get_seconds() { return seconds; }

	void increment_hour();
	void increment_minutes();
	void increment_seconds();

	void clockMenu();
	void displayClock();
	void getInput();

};
#endif // !CLOCK_H
