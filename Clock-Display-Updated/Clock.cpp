#include <iostream>
#include<Windows.h>
#include <sstream>
#include <iomanip>
#include<conio.h>
#include "Clock.h"

using namespace std;

Clock::Clock(int h, int z_h, int m, int s)
	: hour(h), z_hour(z_h), minutes(m), seconds(s) 
{}

void Clock::increment_hour() {
	if (hour == 12) {
		hour = 1;
	}
	else { hour++; }

	if (z_hour == 23) {
		z_hour = 0;
	}
	else { z_hour++; }
}

void Clock::increment_minutes() {
	if (minutes == 59) {
		minutes = 0;
		increment_hour();
	}
	else { minutes++; }
}

void Clock::increment_seconds() {
	if (seconds == 59) {
		seconds = 0;
		increment_minutes();
	}
	else { seconds++; }
}

void Clock::clockMenu() {
	cout << std::setfill('*') << setw(22) << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(20) << " 1 - Add One Hour" << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(20) << " 2 - Add One Minute" << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(20) << " 3 - Add One Second" << '*' << endl;
	cout << '*' << std::left << setfill(' ') << setw(20) << " 4 - Exit Program" << '*' << endl;
	cout << std::setfill('*') << setw(22) << '*' << endl;
}

void Clock::displayClock() {
	int ch;
	stringstream str_second;
	stringstream str_minute;
	stringstream str_hour;
	stringstream str_z_hour;

	while (true) {
		system("CLS");

		str_second << setfill('0') << setw(2) << get_seconds();
		str_minute << setfill('0') << setw(2) << get_minutes();
		str_hour << setfill('0') << setw(2) << get_hour();
		str_z_hour << setfill('0') << setw(2) << get_z_hour();

		cout << "12 HOUR \t 24 HOUR" << endl;
		cout << std::setfill('*') << setw(8) << '*' << "\t" << std::setfill('*') << setw(8) << '*' << endl;

		cout << str_hour.str() << ":" << str_minute.str() << ":" << str_second.str() << "\t";
		cout << str_z_hour.str() << ":" << str_minute.str() << ":" << str_second.str();

		//	Wait 1 second then clear screen and increment seconds
		Sleep(1000);
		increment_seconds();

		str_second.str(std::string());
		str_minute.str(std::string());
		str_hour.str(std::string());
		str_z_hour.str(std::string());

		/*	If the keyboard is hit a menu changeTime() will be called to display a menu that allows
			a user to change the value of the hour, minute, or second and to exit the program. The 
			getInput() function is used to get user input.
		*/
		if (_kbhit()) {

			// ignore the key that is pressed to pull up the menu
			ch = _getch();
			system("CLS");

			clockMenu();
			getInput();
		}
	}
}

/*	Press 1 to increment hour.
*	Press 2 to increment minutes.
*	Press 3 to increment seconds.
*	Press 4 to exit.
* 
*	Default switch case returns screen to clock.
*/
void Clock::getInput() {
	char userInput;
	cin >> userInput;

	switch (userInput) {
	case '1':
		increment_hour();
		break;

	case '2':
		increment_minutes();
		break;

	case '3':
		increment_seconds();
		break;

	case '4':
		system("CLS");
		cout << "Goodbye.";
		exit(EXIT_SUCCESS);
		break;

	default:
		break;
	}
}