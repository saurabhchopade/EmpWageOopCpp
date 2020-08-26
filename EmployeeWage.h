#include <iostream>
#include <time.h>
using namespace std;

class EmployeeWage{
public:
    int ratePerHour, maxWorkingDays, maxWorkingHours, totalWage;

	string company;

    EmployeeWage(string companyName,int ratePerHour,int  maxWorkingDays,int maxWorkHour){
        this->company = companyName;
        this->ratePerHour = ratePerHour;
        this->maxWorkingDays = maxWorkingDays;
        this->maxWorkingHours =maxWorkHour;
    }
 
    void setTotalWage(int totalWage) {
        this->totalWage = totalWage;
    }
 
    int getHour(int);
    int calculateMonthlyWage();
    bool checkMaxHoursReached(int,int);     
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

bool EmployeeWage :: checkMaxHoursReached(int totalHours,int maxHours) {    
    if(totalHours >= maxHours) {
         return true;
    }    
    return false;
} 

int EmployeeWage :: calculateMonthlyWage() {
    int hour, status;
    const int WAGE_PER_HOUR = ratePerHour;
	const int WORKING_DAYS = maxWorkingDays;
	
    int totalWage = 0,totalWorkHours = 0;

    srand(time(NULL));
    for(int day = 1; day <= WORKING_DAYS; day++) {
	    status = ((1 + rand() % 3));
        hour = getHour(status); 

		totalWage += hour * WAGE_PER_HOUR;
	    totalWorkHours += hour;

        if(checkMaxHoursReached(totalWorkHours,maxWorkingHours)) {
            cout << "\nCompanyName = " << company;
            cout << "\nWage for month = " << totalWage << endl;
            setTotalWage(totalWage);
            return 0;
        } 
    }
        return 0;
}