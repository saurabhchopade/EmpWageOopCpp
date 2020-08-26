#include "EmployeeWage.h"
class Input{
public:
  
    void userInput() {
        EmployeeWage *apple = new EmployeeWage("Apple", 20, 100, 100);
        apple->calculateMonthlyWage();
        EmployeeWage *google = new EmployeeWage("Google", 40, 60, 50);
        google->calculateMonthlyWage();
    }
};
int main() {
    Input input;
    input.userInput(); 
}