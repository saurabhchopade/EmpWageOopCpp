#include <iostream>
#include <time.h>
#include <list> 
#include "CompanyEmpWage.h"
#include "IEmployeeWage.h"
using namespace std;

class EmployeeWage : IEmployeeWage{
public:
    int ratePerHour, maxWorkingDays, maxWorkingHours, totalWage;

	string company;
   
    list <CompanyEmpWage> companyList; 

    EmployeeWage(){}

    int getHour(int);
    int calculateMonthlyWage(CompanyEmpWage);
    bool checkMaxHoursReached(int,int);     
    int addCompanyEmpWage(string,int,int,int);
    void displayDetails(int,string);
    void computeEmpWage();
    list<CompanyEmpWage>::iterator it = companyList.begin(); 
};


int EmployeeWage :: addCompanyEmpWage( string companyName, int ratePerHour, int  maxWorkingDays, int maxWorkHour){
    CompanyEmpWage  companyEmpWage(companyName, ratePerHour,maxWorkingDays, maxWorkingHours);
     companyList.insert(it,companyEmpWage);
    return 0;
}

void EmployeeWage :: computeEmpWage(){
  
    for (list<CompanyEmpWage>::iterator index = companyList.begin(); index != companyList.end();index++) {
       index -> setTotalWage(calculateMonthlyWage(*index));
    } 
}
      
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

void EmployeeWage :: displayDetails(int totalWage, string company) {
    cout << "\nCompanyName = " << company;
    cout << "\nWage for month = " << totalWage << endl;
}

int EmployeeWage :: calculateMonthlyWage(CompanyEmpWage companyEmpWage) {
    int hour, status;
    const int WAGE_PER_HOUR = companyEmpWage.ratePerHour;
	const int WORKING_DAYS = companyEmpWage.maxWorkingDays;
	
    int totalWage = 0, totalWorkHours = 0;

    srand(time(NULL));
    for(int day = 1; day <= WORKING_DAYS; day++) {
	    status = ((1 + rand() % 3));
        hour = getHour(status); 

		totalWage += hour * WAGE_PER_HOUR;
	    totalWorkHours += hour;

        if(checkMaxHoursReached(totalWorkHours,companyEmpWage.maxWorkingDays)) {
            displayDetails(totalWage,companyEmpWage.company);
            return totalWage;
        } 
    }
        return 0;
}