#include "EmployeeWage.h"
class Input{
public:
  
    void userInput() {
        EmployeeWage emp;
        emp.calculateMonthlyWage("Dmart", 20, 100, 100);
        emp.calculateMonthlyWage("Kmart", 40, 50, 40);
    }
};
int main() {
    Input input;
    input.userInput(); 
}