#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Separate Class for Office Details
class OfficeDetailsManager {
public:
    static void AssignOfficeDetails(string& deptName, int& staffCount, bool& permanent,
                                    const string& newDeptName, int newStaffCount, bool newPermanent) {
        deptName = newDeptName;
        staffCount = newStaffCount;
        permanent = newPermanent;
    }
};

// Abstract Base Class: Office
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

    void AssignDetails(string deptName, int staffCount, bool permanent) {
        OfficeDetailsManager::AssignOfficeDetails(departmentName, noofStaff, isPermanent,
                                                  deptName, staffCount, permanent);
    }

    string getDepartmentName() const { return departmentName; }
    int getNoofStaff() const { return noofStaff; }
    bool getIsPermanent() const { return isPermanent; }

    // Pure virtual function for polymorphism
    virtual void OfficeDetailsDisplay() const = 0;
};

// Derived Class: TechOffice
class TechOffice : public Office {
private:
    string techFocusArea;

public:
    TechOffice(string deptName, int staffCount, bool permanent, string techArea)
        : Office(deptName, staffCount, permanent), techFocusArea(techArea) {}

    void AssignDetails(string deptName, int staffCount, bool permanent, string techArea) {
        Office::AssignDetails(deptName, staffCount, permanent);
        techFocusArea = techArea;
    }

    void OfficeDetailsDisplay() const override {
        cout << "Department Name: " << getDepartmentName() << endl;
        cout << "Number of Staff: " << getNoofStaff() << endl;
        cout << "Is Permanent: " << (getIsPermanent() ? "Yes" : "No") << endl;
        cout << "Tech Focus Area: " << techFocusArea << endl;
    }
};

// Separate Class for Staff Details
class StaffDetailsManager {
public:
    static void AssignStaffDetails(string& name, string& position, double& salary,
                                   const string& newName, const string& newPosition, double newSalary) {
        name = newName;
        position = newPosition;
        salary = newSalary;
    }
};

// Abstract Base Class: Staff
class Staff {
private:
    string Name;
    string Position;
    double salary;

public:
    // Constructor
    Staff(string n = "", string pos = "", double s = 0.0) : Name(n), Position(pos), salary(s) {
        cout << "Staff created: " << Name << endl;
    }

    // Destructor
    virtual ~Staff() { cout << "Staff destroyed: " << Name << endl; }

    void AssignDetails(string n, string pos, double s) {
        StaffDetailsManager::AssignStaffDetails(Name, Position, salary, n, pos, s);
    }

    string getName() const { return Name; }
    string getPosition() const { return Position; }
    double getSalary() const { return salary; }

    // Pure virtual function for polymorphism
    virtual void StaffDetailsDisplay() const = 0;
};

// Derived Class: Manager
class Manager : public Staff {
private:
    string officeLocation;

public:
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    void StaffDetailsDisplay() const override {
        cout << "Staff Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << "Office Location: " << officeLocation << endl;
    }
};

// OfficeHouse Class
class OfficeHouse {
private:
    string OfficeHouseName;
    vector<Office*> Offices;
    vector<Staff*> StaffMembers;

public:
    // Constructor
    OfficeHouse(string name = "") : OfficeHouseName(name) {
        cout << "OfficeHouse created: " << OfficeHouseName << endl;
    }

    // Destructor
    ~OfficeHouse() {
        cout << "OfficeHouse destroyed: " << OfficeHouseName << endl;
        for (Office* office : Offices) delete office;
        for (Staff* staff : StaffMembers) delete staff;
    }

    void setOfficeHouseName(string name) { OfficeHouseName = name; }

    void AddOffice(Office* office) { Offices.push_back(office); }
    void AddStaff(Staff* person) { StaffMembers.push_back(person); }

    void GetOfficeHouseDetails() const {
        cout << "Company Name: " << OfficeHouseName << endl;
        cout << "Departments: " << endl;
        for (const Office* office : Offices) office->OfficeDetailsDisplay();
        cout << "Staff Details: " << endl;
        for (const Staff* staff : StaffMembers) staff->StaffDetailsDisplay();
    }
};

// Main Function
int main() {
    int OfficeHouseCount;
    cout << "Enter number of office houses you want to create: ";
    cin >> OfficeHouseCount;
    cin.ignore();

    for (int j = 0; j < OfficeHouseCount; j++) {
        OfficeHouse* OfficeHouse1 = new OfficeHouse();
        string name;
        int NumberOfOffices, numberOfStaff;

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

        cout << "Enter Number of Staff Members: ";
        cin >> numberOfStaff;
        cin.ignore();

        for (int i = 0; i < numberOfStaff; i++) {
            string name, position, location;
            double salary;
            cout << "Enter details for Staff member " << i + 1 << ": " << endl;
            cout << "Name: ";
            getline(cin, name);
            cout << "Position: ";
            getline(cin, position);
            cout << "Salary: ";
            cin >> salary;
            cin.ignore();
            cout << "Office Location: ";
            getline(cin, location);

            Staff* staff = new Manager(name, position, salary, location);
            OfficeHouse1->AddStaff(staff);
        }

        OfficeHouse1->GetOfficeHouseDetails();
        delete OfficeHouse1;
    }

    return 0;
}
