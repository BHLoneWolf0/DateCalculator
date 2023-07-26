#include <iostream>
#include <chrono>
int sYear, sMonth, sDay;
int choose, beforeOrAfter;

void setDate() {

	std::cout << "Enter date\n";

	std::cout << "Enter year: ";
	std::cin >> sYear;

	std::cout << "\nEnter month: ";
	std::cin >> sMonth;

	std::cout << "\nEnter day: ";
	std::cin >> sDay;

	std::cout << "========================================================================\n";
}
//I can't think of a good name
void getStuff() {

	std::cout << "(1)After the Date \n(2)Before the Date\n";
	std::cin >> beforeOrAfter;
	
	std::cout << "========================================================================\n";

	std::cout << "\nWhich date you wanna after/before the date?\n(1)Years\n(2)Months\n(3)Days\n";
	std::cin >> choose;

	std::cout << "========================================================================\n";

}

int main() {
	setDate();
	std::chrono::year year(sYear);
	std::chrono::month month(sMonth);
	std::chrono::day day(sDay);

	getStuff();

	switch (choose)
	{
		int changeDate;
	case 1:
		std::cout << "Year\n";
		std::cout << "Enter how many years:";
		std::cin >> changeDate;
		if (beforeOrAfter == 1) {
			year += std::chrono::years(changeDate);
			std::cout << day << "/" << month << "/" << year;
		}
		else if (beforeOrAfter == 2) {
			year -= std::chrono::years(changeDate );
			std::cout << day << "/" << month << "/" << year;
		}
		break;
	case 2:
		std::cout << "Month\n";
		std::cout << "Enter how many months:";
		std::cin >> changeDate;

		if (beforeOrAfter == 1) {
			month += std::chrono::months(changeDate);
			if (month >= std::chrono::month(1)) {
				year += std::chrono::years(1);
			}
			std::cout << day << "/" << month << "/" << year;
		}
		else if (beforeOrAfter == 2) {
			month -= std::chrono::months(changeDate);
			std::cout << day << "/" << month << "/" << year;
		}

		break;
	case 3:
		std::cout << "THE DAY SECTION DOES NOT CALCULATE PROPERLY!!\n";
		std::cout << "Day\n";
		std::cout << "Enter how many days:";
		std::cin >> changeDate;

		if (beforeOrAfter == 1) {
			
			if (year.is_leap()) if (day == std::chrono::day(29)) std::cout << "Leap year!\n";

			day += std::chrono::days(changeDate);

			if (day >= std::chrono::day(31)) {
				day = std::chrono::day(1) + std::chrono::days((day - (std::chrono::day)1) % 30);

				month += std::chrono::months(changeDate / 30);
			}
			std::cout << day << "/" << month << "/" << year;
		}

		else if (beforeOrAfter == 2) {
			if (year.is_leap()) if (day == std::chrono::day(29)) std::cout << "Leap year! ";
			
				day -= std::chrono::days(changeDate);
		
			if (day >= std::chrono::day(200)) {
				day += std::chrono::days(30);
				month--;
			}
			else if (month <= std::chrono::month(0)){
				month = std::chrono::month(12);
			}
			
			std::cout << day << "/" << month << "/" << year;
			break;
	default:
		std::cout << "Please select 1 to 3\n";
		break;
		}
	}
}
