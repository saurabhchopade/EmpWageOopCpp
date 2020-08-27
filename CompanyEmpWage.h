#include <iostream>
using namespace std;
class CompanyEmpWage{
public:
    int ratePerHour, maxWorkingDays, maxWorkingHours, totalWage;

	string company;
    CompanyEmpWage(){
    }

    CompanyEmpWage(string companyName,int ratePerHour,int  maxWorkingDays,int maxWorkHour){
        this->company = companyName;
        this->ratePerHour = ratePerHour;
        this->maxWorkingDays = maxWorkingDays;
        this->maxWorkingHours =maxWorkHour;
    }
 
    void setTotalWage(int totalWage) {
        this->totalWage = totalWage;
    }
};