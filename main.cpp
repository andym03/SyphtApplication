#include <iostream>
#include <string>
#include <fstream>

#define JANURARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#define OFFSET 13
/***
 * Calculates if it is a leap year and returns the appropriate days of February
 * @param year
 * @return the days of February this year
 */
int daysOfFebruary(int year) {
    if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)) {
        return 29;
    } else {
        return 28;
    }
}
/***
 * Calculates how many days the given month has.
 * @param month
 * @return
 */
int daysOfMonth(int month, int year) {
    if (month == JANURARY
     || month == MARCH
     || month == MAY
     || month == JULY
     || month == AUGUST
     || month == OCTOBER
     || month == DECEMBER) {
        return 31;
    }
    else if (month == APRIL
    || month == JUNE
    || month == SEPTEMBER
    || month == NOVEMBER) {
        return 30;
    } else {
        return daysOfFebruary(year);
    }
}


/***
 * relies on input string being the same
 * @return
 */
int parseDay(std::string date, bool firstInput) {
    //02/06/1983 - 22/06/1983
    int indexOffset = 0;
    int outputDay = 0;
    if (!firstInput) {
        indexOffset = OFFSET;
    }

    if (date[indexOffset] == '1') {
        outputDay += 10;
    } else if (date[indexOffset] == '2') {
        outputDay += 20;
    } else if (date[indexOffset] == '3') {
        outputDay += 30;
    }

    outputDay += (int)date[indexOffset+1]-48;
    return outputDay;
}

int parseMonth(std::string date, bool firstInput) {
    int indexOffset = 0;
    int month = 0;

    if (!firstInput) {
        indexOffset = OFFSET;
    }

    if (date[indexOffset+3] == '1') {
        month += 10;
    }

    month += (int)date[indexOffset+4]-48;
    return month;
}

int parseYear(std::string date, bool firstInput) {
    int indexOffset = 0;
    int year = 1000;

    if (!firstInput) {
        indexOffset = OFFSET;
    }

    year = year*((int)date[indexOffset+6]-48);
    year += 100*((int)date[indexOffset+7]-48);
    year += 10*((int)date[indexOffset+8]-48);
    year += (int)date[indexOffset+9]-48;

    return year;
}

bool flipGoalDate(int d1, int d2, int m1, int m2, int y1, int y2) {
    if (y1 == y2) {
        if (m1 == m2) {
            if (d1 > d2) {
                return true;
            }
        }
        if (m1 > m2) {
            return true;
        }
    }
    if (y1 > y2) {
        return true;
    }

    return false;
}

int dateDifference(std::string dates) {
    int initialDay = parseDay(dates, true);
    int initialMonth = parseMonth(dates, true);
    int initialYear = parseYear(dates, true);
    int goalDay = parseDay(dates, false);
    int goalMonth = parseMonth(dates, false);
    int goalYear = parseYear(dates, false);

    if (initialDay == goalDay
        && initialMonth == goalMonth
        && initialYear == goalYear) {
        std::cout << 0 << "\n";
    } else {
        if (flipGoalDate(initialDay, goalDay, initialMonth, goalMonth, initialYear, goalYear)) {
            int temp = initialDay;
            initialDay = goalDay;
            goalDay = temp;

            temp = initialMonth;
            initialMonth = goalMonth;
            goalMonth = temp;

            temp = initialYear;
            initialYear = goalYear;
            goalYear = temp;
        }

        int DAYS = 0;
        int daysThisMonth = 0;
        initialDay +=1; // Ignore the first day

        while (initialYear <= goalYear) {
            if (initialYear == goalYear) {
                for (int month = initialMonth; month <= goalMonth; month++) {
                    if ( month == goalMonth) {
                        for (int i = initialDay; i < goalDay; i++) {
                            DAYS++;
                        }
                    } else {
                        daysThisMonth = daysOfMonth(month, initialYear);
                        for (int i = initialDay; i <= daysThisMonth; i++) {
                            DAYS++;
                        }
                    }
                    initialDay = 1;
                }
            } else {
                for (int month = initialMonth; month <= DECEMBER; month++) {
                    daysThisMonth = daysOfMonth(month, initialYear);
                    for (int i = initialDay; i <= daysThisMonth; i++) {
                        DAYS++;
                    }
                    initialDay = 1;
                }
            }
            initialDay = 1;
            initialMonth = 1;
            initialYear++;
        }
        std::cout << DAYS << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        for (std::string line; std::getline(std::cin, line);) {
            dateDifference(line);
        }
    } else {
        std::string filePath = argv[1];
        std::ifstream input(filePath);
        for( std::string line; std::getline( input, line ); )
        {
            dateDifference(line);
        }
    }
}