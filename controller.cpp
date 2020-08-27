#include "EmployeeWage.h"
class Input{
public:
  
    void userInput() {
        EmployeeWage *apple = new EmployeeWage();
        apple->addCompanyEmpWage("Bridgelabz",20,50,100);
        apple->computeEmpWage();
    }
};
int main() {
    Input input;
    input.userInput(); 
}