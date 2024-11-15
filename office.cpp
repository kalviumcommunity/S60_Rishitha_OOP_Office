#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class: Office
class Office {
private:
    string departmentName;
    int noofStaff;
    bool isPermanent;

public:
    // Constructor
    Office(string deptName = "", int staffCount = 0, bool permanent = false)
        : departmentName(deptName), noofStaff(staffCount), isPermanent(permanent) {
        cout << "Office created: " << departmentName << endl;
    }

    // Destructor
    virtual ~Office() {
        cout << "Office destroyed: " << departmentName << endl;
    }

    virtual void AssignOfficeDetails(string deptName, int staffCount, bool permanent) {
        departmentName = deptName;
        noofStaff = staffCount;
        isPermanent = permanent;
    }

    string getDepartmentName() const {
        return departmentName;
    }

    int getNoofStaff() const {
        return noofStaff;
    }

    bool getIsPermanent() const {
        return isPermanent;
    }

    // Virtual method for polymorphism
    virtual void OfficeDetailsDisplay() const {
        cout << "Department Name: " << getDepartmentName() << endl;
        cout << "Number of Staff: " << getNoofStaff() << endl;
        cout << "Is Permanent: " << (getIsPermanent() ? "Yes" : "No") << endl;
    }
};

// Derived Class: TechOffice
class TechOffice : public Office {
private:
    string techFocusArea;

public:
    TechOffice(string deptName, int staffCount, bool permanent, string techArea)
        : Office(deptName, staffCount, permanent), techFocusArea(techArea) {}

    void AssignTechOfficeDetails(string deptName, int staffCount, bool permanent, string techArea) {
        AssignOfficeDetails(deptName, staffCount, permanent);
        techFocusArea = techArea;
    }

    void OfficeDetailsDisplay() const override {
        Office::OfficeDetailsDisplay();
        cout << "Tech Focus Area: " << techFocusArea << endl;
    }
};

// Staff Class
class Staff {
private:
    string Name;
    string Position;
    double salary;

public:
    // Constructor
    Staff(string n = "", string pos = "", double s = 0.0)
        : Name(n), Position(pos), salary(s) {
        cout << "Staff created: " << Name << endl;
    }

    // Destructor
    ~Staff() {
        cout << "Staff destroyed: " << Name << endl;
    }

    void AssignStaffDetails(string n, string pos, double s) {
        Name = n;
        Position = pos;
        salary = s;
    }

    string getName() const {
        return Name;
    }

    string getPosition() const {
        return Position;
    }

    double getSalary() const {
        return salary;
    }

    virtual void StaffDetailsDisplay() const {
        cout << "Staff Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: $" << getSalary() << endl;
    }
};

// Derived Class: Manager
class Manager : public Staff {
private:
    string officeLocation;

public:
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    void StaffDetailsDisplay() const override {
        Staff::StaffDetailsDisplay();
        cout << "Office Location: " << officeLocation << endl;
    }
};

// OfficeHouse Class
class OfficeHouse {
private:
    string OfficeHouseName;
    vector<Office*> Offices;
    vector<Staff*> StaffMembers;
    static int OfficeHouseCount;

public:
    // Constructor
    OfficeHouse(string name = "") : OfficeHouseName(name) {
        OfficeHouseCount++;
        cout << "OfficeHouse created: " << OfficeHouseName << endl;
    }

    // Destructor
    ~OfficeHouse() {
        cout << "OfficeHouse destroyed: " << OfficeHouseName << endl;
        for (Office* office : Offices) delete office;
        for (Staff* staff : StaffMembers) delete staff;
        OfficeHouseCount--;
    }

    static int getOfficeHouseCount() {
        return OfficeHouseCount;
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

    void GetOfficeHouseDetails() const {
        cout << "Company Name: " << OfficeHouseName << endl;
        cout << "Departments: " << endl;
        for (const Office* office : Offices) {
            office->OfficeDetailsDisplay();
        }
        cout << "Staff Details: " << endl;
        for (const Staff* staff : StaffMembers) {
            staff->StaffDetailsDisplay();
        }
    }
};

int OfficeHouse::OfficeHouseCount = 0;

// Main Function
int main() {
    int OfficeHouseCount;
    cout << "Enter number of office houses you want to create: ";
    cin >> OfficeHouseCount;
    cin.ignore();

    for (int j = 0; j < OfficeHouseCount; j++) {
        OfficeHouse* OfficeHouse1 = new OfficeHouse();
        string name;
        int NumberOfOffices;

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
            string techArea;
            int num;

            cout << "Enter details of Department " << i + 1 << ":" << endl;
            cout << "Department Name: ";
            getline(cin, deptName);
            cout << "Number of Staff: ";
            cin >> staffCount;
            cout << "Is Permanent? (1 for Yes, 0 for No): ";
            cin >> num;
            permanent = (num == 1);
            cin.ignore();

            cout << "Tech Focus Area: ";
            getline(cin, techArea);

            Office* techOffice = new TechOffice(deptName, staffCount, permanent, techArea);
            OfficeHouse1->AddOffice(techOffice);
        }

        OfficeHouse1->GetOfficeHouseDetails();
        delete OfficeHouse1;
    }

    return 0;
}
