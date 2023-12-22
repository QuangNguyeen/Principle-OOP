#include<iostream>
namespace std {
    class TLClass {
    private:
        string id;
        string name;
        string description;
        string position;
    public:
        string getId() {
            return id;
        }

        string getName() {
            return name;
        }

        string getDescription() {
            return description;
        }

        string getPosition() {
            return position;
        }

        void setID(string id) {
            this->id = id;
        }

        void setName(string name) {
            this->name = name;
        }

        void setDescription(string description) {
            this->description = description;
        }

        void setPosition(string position) {
            this->position = position;
        }

        void input() {
            string id, name, description, position;
            cout << "Enter id of class: ";
            cin >> id;
            this->setID(id);
            cout << "Enter name class: ";
            cin.ignore();
            getline(cin,name);
            this->setName(name);
            cout << "Enter description class: ";
            cin >> description;
            this->setDescription(description);
            cout << "Enter position class: ";
            cin >> position;
            this->setPosition(position);
        }

        void output() {
            cout << "ID of Class: " << this->getId() << endl;
            cout << "Name of Class: " << this->getName() << endl;
            cout << "Description of Class: " << this->getDescription() << endl;
            cout << "Position of Class: " << this->getPosition() << endl;
        }
    };
}
