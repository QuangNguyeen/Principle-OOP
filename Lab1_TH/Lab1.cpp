#include<iostream>
#include<vector>
#include "TLStudent.h"
using namespace std;
void displayMenu();
void addStudent(vector<TLStudent> &students);
void removeStudent(vector<TLStudent> &students, string id_remove);
void findStudentByID(vector<TLStudent> students, string id_find);
void displayStudents(TLStudent student);
void displayStudentsByClass(vector<TLStudent> students);
double findMaxNoteStudent(vector<TLStudent> students);
bool compare_ID_Student(TLStudent student, string id_find);
int main(){
    vector<TLStudent> students;
    int choice;
    while(true){
        displayMenu();
        cout << "Enter your choice: (choice 0 to exit) "; cin >> choice;
        switch(choice){
            case 1:{
                addStudent(students);
                cout << students.size();
                break;
            }

            case 2:{
                string id_remove;
                cout << "Enter the student id to remove: ";
                cin >> id_remove;
                removeStudent(students, id_remove);
                break;
            }
            case 3:{
                string id_find;
                cout << "Enter the student id to search: ";
                cin >> id_find;
                findStudentByID(students,id_find);
                break;
            }
            case 4: {
                cout << "List of students: " << endl;
                cout << "ID Student" << "\t" << "ID Class" << "\t" << "Name Student" << endl;
                cout << "--------------------------------------------" << endl;
                for(int i = 0; i < students.size(); i++){
                    displayStudents(students[i]);
                }
                break;
            }
            case 5:{
                displayStudentsByClass(students);
                break;
            }
            case 6:{
                int count = 0;
                cout << "List students: \n";
                for(int i = 0; i < students.size(); i++){
                    if(students[i].getNode_Student() >= 5){
                        displayStudents(students[i]);
                        count++;
                    }
                }
                cout << "The number of students with scores greater than or equal to 5: " << count << endl;
                break;
            }
            case 7:{
                int count = 0;
                cout << "List stundets: \n";
                for(int i = 0; i < students.size(); i++){
                    if(students[i].getNode_Student() < 5){
                        displayStudents(students[i]);
                        count++;
                    }
                }
                cout << "The number of students with scores less than 5: " << count << endl;
                break;
            }
            case 8:{
                double maxNode = findMaxNoteStudent(students);
                int count = 0;
                for(int i = 0; i < students.size(); i++){
                    if(students[i].getNode_Student() == maxNode){
                        displayStudents(students[i]);
                        count++;
                    }
                }
                cout << "Number students: " << count << endl;
                break;
            }
            case 0:
                cout << "Goodbye!";
                exit(0);
            default:
                cout << "Enter choice from 0 to 8." << endl;
        }
    }
}
void displayMenu(){
    cout << "Student management program" << endl;
    cout << "1. Add new students to the list" << endl;
    cout << "2. Remove students from the list" << endl;
    cout << "3. Search students by ID" << endl;
    cout << "4. List all students" << endl;
    cout << "5. List students by class id" << endl;
    cout << "6. List the list of students with scores greater than or equal to 5.0 and the number of students" << endl;
    cout << "7. List the list of students with scores below 5.0 and the number of students" << endl;
    cout << "8. List the students with the highest scores and the number of students" << endl;
}
void addStudent(vector<TLStudent> &students) {
    TLStudent newStudent;
    newStudent.input_Student();
    bool studentExists = false;
    for (int i = 0; i < students.size(); i++) {
        if (newStudent.getId_Student() == students[i].getId_Student()) {
            cout << "Student already exists" << endl;
            studentExists = true;
            break;
        }
    }
    if (!studentExists) {
        students.push_back(newStudent);
        cout << "Student added successfully" << endl;
    }
}

bool compare_ID_Student(TLStudent student, string id_find){
    return student.getId_Student() == id_find;
}
void findStudentByID(vector<TLStudent> students, string id_find){
    bool check = false;
    for(int i = 0; i < students.size(); i++){
        if(compare_ID_Student(students[i],id_find)) {
            check = true;
            students[i].ouput_Student();
            break;
        }
    if(!check){
        cout << "Not found !" << endl;
    }
    }
}
void removeStudent(vector<TLStudent> &students, const string id_remove) {
    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (compare_ID_Student(students[i], id_remove)) {
            students.erase(students.begin() + i);
            cout << "Remove successfully !" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not in the list" << endl;
    }
}
void displayStudents(TLStudent student){
        cout << student.getId_Student() << "\t\t"
             << student.getTCLass_Student().getId()
             << "\t\t" << student.getName_Student() << endl;
}

void displayStudentsByClass(vector<TLStudent> students) {
    vector<TLClass> classmate;
    TLClass currentClass;
    for(int i = 0; i < students.size(); i++){
        currentClass = students[i].getTCLass_Student();
        classmate.push_back(currentClass);
    }

    // Remove duplicates based on class ID
    for (int i = 0; i < classmate.size(); ++i) {
        for (int j = i + 1; j < classmate.size();) {
            if (classmate[i].getId() == classmate[j].getId()) {
                classmate.erase(classmate.begin() + j);
            } else {
                ++j;
            }
        }
    }

    // Display students by class
    for (int i = 0; i < classmate.size(); i++) {
        cout << "Class: " << classmate[i].getName() << endl;
        cout << "---------------------------\n";
        for (int j = 0; j < students.size(); j++) {
            if (classmate[i].getId() == students[j].getTCLass_Student().getId()) {
                cout << students[j].getId_Student() << "\t\t"
                     << students[j].getTCLass_Student().getId() << "\t\t"
                     << students[j].getName_Student() << endl;
            }
        }
        cout << endl;
    }
}

double findMaxNoteStudent(vector<TLStudent> students){
    double maxNote = 0;
    for(int i = 0; i<students.size(); i++){
        if(students[i].getNode_Student() > maxNote){
            maxNote = students[i].getNode_Student();
        }
    }
    return maxNote;
}




