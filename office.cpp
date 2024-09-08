#include <iostream>
#include <vector>
using namespace std;

class Office {
private:
    string departmentName;
    int noofStaff;
    bool isPermanent;

public:
    void AssignOfficeDetails(string deptName, int staffCount, bool permanent) {
        this->departmentName = deptName;
        this->noofStaff = staffCount;
        this->isPermanent = permanent;
    }

    void OfficeDetailsDisplay() {
        cout << "Department Name: " << this->departmentName << endl;
        cout << "Number of Staff: " << this->noofStaff << endl;
        cout << "Is Permanent: " << (this->isPermanent ? "Yes" : "No") << endl;
    }
};

class Staff {
private:
    string Name;
    string Position;
    double salary;

public:
    void AssignStaffDetails(string n, string pos, double s) {
        this->Name = n;
        this->Position = pos;
        this->salary = s;
    }

    void StaffDetailsDisplay() {
        cout << "Staff Name: " << this->Name << endl;
        cout << "Position: " << this->Position << endl;
        cout << "Salary: $" << this->salary << endl;
    }
};

class OfficeHouse {
private:
    string OfficeHouseName;
    vector<Office*> Offices;
    vector<Staff*> StaffMembers;

public:
    void setOfficeHouseName(string name) {
        this->OfficeHouseName = name;
    }

    void AddOffice(Office* office) {
        Offices.push_back(office);
    }

    void AddStaff(Staff* person) {
        StaffMembers.push_back(person);
    }

    void GetOfficeHouseDetails() {
        cout << "Company Name: " << this->OfficeHouseName << endl;
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

int main() {
    OfficeHouse *OfficeHouse1 = new OfficeHouse();
    string name;
    int NumberOfOffices;
    int NumberOfStaff;

    cout << "Enter an Company name: ";
    getline(cin, name);
    OfficeHouse1->setOfficeHouseName(name);

    cout << "Enter Number of Departments: ";
    cin >> NumberOfOffices;

    for (int i = 0; i < NumberOfOffices; i++) {
        string deptName;
        int staffCount;
        bool permanent;
        int num;

        cout << "Enter details of " << i + 1 << " Departments: " << endl;
        cout << "Department Name: ";
        cin.ignore();
        getline(cin, deptName);
        cout << "Number of Staff: ";
        cin >> staffCount;
        cout << "Is the office permanent? (1 for Yes, 0 for No): ";
        cin >> num;
        permanent = (num == 1);

        Office* office = new Office;
        office->AssignOfficeDetails(deptName, staffCount, permanent);
        OfficeHouse1->AddOffice(office);
    }

    cout << "Enter Number of Staff: ";
    cin >> NumberOfStaff;

    for (int i = 0; i < NumberOfStaff; i++) {
        string personName;
        string pos;
        double s;

        cout << "Enter details of " << i + 1 << " staff member: " << endl;
        cout << "Staff Name: ";
        cin.ignore();
        getline(cin, personName);
        cout << "Staff Position: ";
        getline(cin, pos);
        cout << "Staff Salary: ";
        cin >> s;

        Staff* person = new Staff;
        person->AssignStaffDetails(personName, pos, s);
        OfficeHouse1->AddStaff(person);
    }

    cout << endl;
    OfficeHouse1->GetOfficeHouseDetails();
    delete OfficeHouse1;
    return 0;
}
