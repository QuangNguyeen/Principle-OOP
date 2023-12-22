#include<iostream>
using namespace std;
class Employee{
protected:
    string name;
    int age;
    double salary;
public:
    Employee(){
        this->name = "Nguyen Van Quang";
        this->age = 20;
        this->salary = 1000;
    }
    Employee(string name1, int age1, double sal1){
        this->name = name1;
        this->age = age1;
        this->salary = sal1;
    }
    string getName(){
        return this->name;
    }
    int getAge(){
        return this->age;
    }
    double getSalary(){
        return this->salary;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setSalary(double sal){
        this->salary = sal;
    }
    virtual void setIntroduce(){
        cout << "I am a employee";
    }
    virtual void output(){
        cout << "Name: " << this->name << "\t" << "Age: " << this->age << "\t" << "Salary: " << this->salary << endl;
    }
};
class Doctor: public Employee{
private:
    double fee;
    string speciality;
public:
    double getFee(){
        return this->fee;
    }
    string getSpeciality(){
        return this->speciality;
    }
    void setIntroduce(){
        cout << "I am a doctor";
    }
    void output(){
        cout << "Name: " << this->name << "\t"
        << "Age: " << this->age << "\t"
        << "Salary: " << this->salary  << "\t"
        << "Fee: " << this->fee << "\t"
        << "Speciality: " << this->speciality << "\t"
        << endl;
    }
};
int main(){
    int n;
    cout << "Enter the number "
    return 0;
}