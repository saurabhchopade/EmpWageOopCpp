#include <iostream>
#include <time.h>
using namespace std;

class EmployeeWage{
public:
    int getHour(int);
    int calculateMonthlyWage();
    bool checkMaxHoursReached(int); 
};

int EmployeeWage :: getHour(int status) {
    const  int IS_FULL_TIME = 1;
	const  int  IS_PART_TIME = 2;

    int hour = 0;

    switch(status) {
	    case IS_FULL_TIME:
			hour = 8;
				break;
			case IS_PART_TIME:
			    hour = 4;
				break;
			default :
				hour = 0;
			    break;
    }      
    return hour;
}

bool EmployeeWage :: checkMaxHoursReached(int totalHours) {
    const int maxHours = 100; 
    
    if(totalHours >= maxHours) {
         return true;
    }    
    return false;
} 

int EmployeeWage :: calculateMonthlyWage() {
    int hour, status;
    const int WAGE_PER_HOUR = 20;
	const int WORKING_DAYS = 100;
	
    int totalWage = 0,totalWorkHours = 0;

    srand(time(NULL));
    for(int day = 1; day <= WORKING_DAYS; day++) {
	    status = ((1 + rand() % 3));
        hour = getHour(status); 

		totalWage += hour * WAGE_PER_HOUR;
	    totalWorkHours += hour;

        if(checkMaxHoursReached(totalWorkHours)) {
            cout << "\nWage for month = " << totalWage;
            return 0;
        } 
    }
        return 0;
}