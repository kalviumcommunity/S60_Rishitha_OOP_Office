#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

class Office {
private:
    string departmentName;
    int noofStaff;
    bool isPermanent;

public:
    Office() {}

    void AssignOfficeDetails(string deptName, int staffCount, bool permanent) {
        departmentName = deptName;
        noofStaff = staffCount;
        isPermanent = permanent;
    }

    string getDepartmentName() {
        return departmentName;
    }

    int getNoofStaff() {
        return noofStaff;
    }

    bool getIsPermanent() {
        return isPermanent;
    }

    void OfficeDetailsDisplay() {
        cout << "Department Name: " << getDepartmentName() << endl;
        cout << "Number of Staff: " << getNoofStaff() << endl;
        cout << "Is Permanent: " << (getIsPermanent() ? "Yes" : "No") << endl;
    }
};

class Staff {
private:
    string Name;
    string Position;
    double salary;

public:
    Staff() {}

    void AssignStaffDetails(string n, string pos, double s) {
        Name = n;
        Position = pos;
        salary = s;
    }

    string getName() {
        return Name;
    }

    string getPosition() {
        return Position;
    }

    double getSalary() {
        return salary;
    }

    void StaffDetailsDisplay() {
        cout << "Staff Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: $" << getSalary() << endl;
    }
};

class OfficeHouse {
private:
    string OfficeHouseName;
    vector<Office*> Offices;
    vector<Staff*> StaffMembers;
    static int OfficeHousecount;

public:
    OfficeHouse() {
        OfficeHousecount++;
    }

    static int getOfficeHouseCount() {
        return OfficeHousecount;
    }

    void setOfficeHouseName(string name) {
        OfficeHouseName = name;
    }

    void AddOffice(Office* office) {
        Offices.push_back(office);
    }

    void AddStaff(Staff* person) {
        StaffMembers.push_back(person);
    }

    void GetOfficeHouseDetails() {
        cout << "Company Name: " << OfficeHouseName << endl;
        cout << "Departments: " << endl;
        for (int i = 0; i < Offices.size(); i++) {
            Offices[i]->OfficeDetailsDisplay();
        }
        cout << "Staff Details: " << endl;
        for (int j = 0; j < StaffMembers.size(); j++) {
            StaffMembers[j]->StaffDetailsDisplay();
        }
    }
};

int OfficeHouse::OfficeHousecount = 0;

int main() {
    int OfficeHouseCount;
    cout << "Enter number of office houses you want to create: ";
    cin >> OfficeHouseCount;
    cin.ignore();

    for (int j = 0; j < OfficeHouseCount; j++) {
        OfficeHouse* OfficeHouse1 = new OfficeHouse();
        string name;
        int NumberOfOffices;
        int NumberOfStaff;

        cout << "Enter a Company name: ";
        getline(cin, name);
        OfficeHouse1->setOfficeHouseName(name);

        cout << "Enter Number of Departments: ";
        cin >> NumberOfOffices;
        cin.ignore();

        for (int i = 0; i < NumberOfOffices; i++) {
            string deptName;
            int staffCount;
            bool permanent;
            int num;

            cout << "Enter details of " << i + 1 << " Department: " << endl;
            cout << "Department Name: ";
            getline(cin, deptName);
            cout << "Number of Staff: ";
            cin >> staffCount;
            cout << "Is the office permanent? (1 for Yes, 0 for No): ";
            cin >> num;
            permanent = (num == 1);
            cin.ignore();

            Office* office = new Office();
            office->AssignOfficeDetails(deptName, staffCount, permanent);
            OfficeHouse1->AddOffice(office);
        }

        cout << "Enter Number of Staff: ";
        cin >> NumberOfStaff;
        cin.ignore();

        for (int i = 0; i < NumberOfStaff; i++) {
            string personName;
            string pos;
            double s;

            cout << "Enter details of " << i + 1 << " staff member: " << endl;
            cout << "Staff Name: ";
            getline(cin, personName);
            cout << "Staff Position: ";
            getline(cin, pos);
            cout << "Staff Salary: ";
            cin >> s;
            cin.ignore();

            Staff* person = new Staff();
            person->AssignStaffDetails(personName, pos, s);
            OfficeHouse1->AddStaff(person);
        }

        cout << endl;
        OfficeHouse1->GetOfficeHouseDetails();
        delete OfficeHouse1;
    }

    cout << "Total number of offices added: " << OfficeHouse::getOfficeHouseCount() << endl;

    return 0;
}
