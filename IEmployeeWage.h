#include <iostream>
using namespace std;

class IEmployeeWage {
    virtual int addCompanyEmpWage( string companyName, int ratePerHour, int  maxWorkingDays, int maxWorkHour) = 0;
    virtual void computeEmpWage() = 0;
};