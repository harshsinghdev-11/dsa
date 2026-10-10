#include <bits/stdc++.h>
using namespace std;

// The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users.
// To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class).
// If you want others to read or modify the value of a private member, you can provide public get and set methods.

class Employee{
    private:
    int salary;
    public:
    int getSalary(){
        return this->salary;
    }
    bool setSalary(int salary){
        if(salary<0) return false;
        this->salary = salary;
        return true;
    }
};

int main(){
    Employee emp1;
    cout<<emp1.getSalary()<<endl;
    cout<<emp1.setSalary(2000);
    cout<<emp1.getSalary();
}
