#include<iostream>
#include<vector>
using namespace std;
struct date{
    int day, month, year;
};
class Device{
protected:
    string id;
    string name;
    string manufacturer;
    date importedDate;
public:
    virtual void toString() = 0;
    // Constructor
    Device(){}
    // getter
    string getID(){
        return id;
    }
    string getName(){
        return name;
    }
    string getManuFacturer(){
        return manufacturer;
    }
    date getImportedDate(){
        return importedDate;
    }
    // setter
    void setID(string id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
    void setManuFacturer(string Manu){
        this->manufacturer = Manu;
    }
    void setImportedDate(date Date){
        this->importedDate = Date;
    }
    friend istream& operator>>(istream & in, Device& dv);
    friend ostream& operator<<(ostream & out, Device& dv);

};
istream& operator>>(istream & in, Device& dv){
    cout << "Enter ID device: "; in >> dv.id;
    cout << "Enter Name Device: "; in >> dv.name;
    cout << "Enter Manufacturer of Device: "; in >> dv.manufacturer;
    cout << "Enter Imported Date of Device: "; in >> dv.importedDate.day >> dv.importedDate.month >> dv.importedDate.year;
    return in;
}
ostream& operator<<(ostream & out, Device& dv){
    cout << "ID: " << dv.id << "\t" << "Name: " << dv.name << "\t" << "Manufacturer: " << dv.manufacturer << "\t"
    << "Imported Date: " << dv.importedDate.day << "-" << dv.importedDate.month << "-" << dv.importedDate.year << endl;
    return out;
}
class Computer : public Device{
private:
    string cpu;
    string ram;
public:
    // Constructor
    Computer(){};
    void setCPU(string CPU){
        this->cpu = CPU;
    }
    void setRAM(string RAM){
        this->ram = RAM;
    }
    string getCPU(){
        return cpu;
    }
    string getRAM(){
        return ram;
    }
    void toString(){
        cout << "Override virtual function";
    };
    friend istream & operator >> (istream & in, Computer & cp);
    friend ostream & operator << (ostream & out, Computer & cp);

};
istream & operator >> (istream & in, Computer & cp){
    Device &device = cp;
    in >> device;
    cout << "Enter value of CPU: "; in >> cp.cpu;
    cout << "Enter value of RAM: "; in >> cp.ram;
    return in;
}
ostream & operator << (ostream & out, Computer & cp){
    Device &device = cp;
    cout << device << endl;
    cout << "CPU: " << cp.cpu << "\t" << "RAM: " << cp.ram << endl;
    return out;
}
class Monitor : public Device{
private:
    string size;
public:
    // Constructor
    Monitor(){};
    void setSize(string SIZE){
        this->size = SIZE;
    }
    string getSize(){
        return size;
    }
    void toString(){
        cout << "Override virtual function";
    };
    friend istream & operator >> (istream & in, Monitor & mn);
    friend ostream & operator << (ostream & out, Monitor & mn);
};
istream & operator >> (istream & in, Monitor & mn){
    Device &device = mn;
    in >> device;
    cout << "Enter value of size: "; in >> mn.size;
    return in;
}
ostream & operator << (ostream & out, Monitor & mn){
    Device &device = mn;
    out << device << endl;
    cout << "Size: " << mn.size << endl;
    return out;
}
int main(){
    Device **list = NULL;
    int n;
    cout << "Enter number of the Device: "; cin >> n;
    list = new Device *[n];
    int countComputer = 0, countMonitor = 0;
    for(int i = 0; i < n; i++){
        int choice;
        cout << "Enter value of choice: ( 0 is Computer, 1 is Monitor ) "; cin >> choice;
        if(choice == 0){
            countComputer++;
            list[i] = new Computer;
            cin >> *list[i];
        } else if(choice == 1){
            countMonitor++;
            list[i] = new Monitor;
            cin >> *list[i];
        }
    }
    cout << "\nInformation of Devices: \n";
    for(int i = 0; i < n; i++){
        cout << *list[i];
    }
    cout << endl;
    cout << "Computer: " << countComputer << " devices" << endl;
    cout << "Monitor: " << countMonitor << " devices";
    return 0;
}
