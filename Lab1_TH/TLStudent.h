//
// Created by macbook on 28/11/2023.
//
#ifndef PRINCIPLE_OOP_TLSTUDENT_H
#define PRINCIPLE_OOP_TLSTUDENT_H
#include<iostream>
#include "TLClass.h"
namespace std {

    class TLStudent {
    private:
        string id;
        string name;
        string address;
        string description;
        TLClass tlClass;
        double note;
    public:
        string getId_Student(){
            return id;
        }
        string getName_Student(){
            return name;
        }
        string getAddress_Student(){
            return address;
        }
        string getDescription_Student(){
            return description;
        }
        TLClass getTCLass_Student(){
            return tlClass;
        }
        double getNode_Student(){
            return note;
        }
        void setId_Student(string id){
            this->id = id;
        }
        void setName_Student(string name){
            this->name = name;
        }
        void setDescription_Student(string description){
            this->description = description;
        }
        void setAddress_Student(string address){
            this->address = address;
        }
        void setTLClass_Student(const TLClass& tlClass) {
            this->tlClass = tlClass;
        }
        void setNote_Student(double note){
            this->note = note;
        }
        void input_Student(){
            string id, name, description, address;
            TLClass tlClass;
            cout << "Enter ID of Student:  "; cin >> id;
            this->setId_Student(id);
            cout << "Enter Name of Student: ";
            cin.ignore();
            getline(cin,name);
            this->setName_Student(name);
            cout << "Enter Description of Student: "; cin >> description;
            this->setDescription_Student(description);
            cout << "Enter Address of Student: "; cin >> address;
            this->setAddress_Student(address);
            cout << "Information of TLClass: \n--------------------------" << endl; tlClass.input();
            this->setTLClass_Student(tlClass);
            cout << "Enter point of student: "; cin >> note;
            this->setNote_Student(note);
        }
        void ouput_Student(){
            cout << "Id of Student: " << this->getId_Student() << endl;
            cout << "Name of Student: " << this->getName_Student() << endl;
            cout << "Description of Student: " << this->getDescription_Student() << endl;
            cout << "Address of Student: " << this->getAddress_Student() << endl;
            cout << "----------------------------" << endl;
            cout << "TLClass : ";
            this->tlClass.output();
            cout << "Point of Student: " <<  this->getNode_Student() << endl;
        }
    };

} // std

#endif //PRINCIPLE_OOP_TLSTUDENT_H
