#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Separate Class for Office Details (Handles office data assignments)
class OfficeDetailsManager {
public:
    // Method to assign details of an office (uses reference parameters)
    static void AssignOfficeDetails(string& deptName, int& staffCount, bool& permanent,
                                    const string& newDeptName, int newStaffCount, bool newPermanent) {
        deptName = newDeptName;  
        staffCount = newStaffCount;  
        permanent = newPermanent;  
    }
};

// Abstract Base Class: Office (The general idea of an office with some properties)
class Office {
private:
    string departmentName;
    int noofStaff;
    bool isPermanent;

public:
    // Constructor to initialize office details
    Office(string deptName = "", int staffCount = 0, bool permanent = false)
        : departmentName(deptName), noofStaff(staffCount), isPermanent(permanent) {
        cout << "Office created: " << departmentName << endl; 
    }

    // Destructor to notify when an office is destroyed
    virtual ~Office() {
        cout << "Office destroyed: " << departmentName << endl;  
    }

    // Getter methods for department details
    string getDepartmentName() const { return departmentName; }
    int getNoofStaff() const { 
        return noofStaff; 
        }
    bool getIsPermanent() const { return isPermanent; }

    // Pure virtual function for polymorphism (different behavior in derived classes)
    virtual void OfficeDetailsDisplay() const = 0;
};

// Derived Class: TechOffice (Specific type of office with tech-related focus)
class TechOffice : public Office {
private:
    string techFocusArea;

public:
    // Constructor to initialize both office and tech focus details
    TechOffice(string deptName, int staffCount, bool permanent, string techArea)
        : Office(deptName, staffCount, permanent), techFocusArea(techArea) {}

    // Display the office details along with tech focus area
    void OfficeDetailsDisplay() const override {
        cout << "Department Name: " << getDepartmentName() << endl;
        cout << "Number of Staff: " << getNoofStaff() << endl;
        cout << "Is Permanent: " << (getIsPermanent() ? "Yes" : "No") << endl;
        cout << "Tech Focus Area: " << techFocusArea << endl;  // Display specific tech area
    }
};

// Separate Class for Staff Details (Handles staff data assignments)
class StaffDetailsManager {
public:
    // Method to assign details of staff members (uses reference parameters)
    static void AssignStaffDetails(string& name, string& position, double& salary,
                                   const string& newName, const string& newPosition, double newSalary) {
        name = newName;  // Assign new staff name
        position = newPosition;  // Assign new position
        salary = newSalary;  // Assign new salary
    }
};

// Abstract Base Class: Staff (The general idea of a staff member with some properties)
class Staff {
private:
    string Name;
    string Position;
    double salary;

public:
    // Constructor to initialize staff details
    Staff(string n = "", string pos = "", double s = 0.0) : Name(n), Position(pos), salary(s) {
        cout << "Staff created: " << Name << endl; 
    }

    // Destructor to notify when a staff member is destroyed
    virtual ~Staff() { cout << "Staff destroyed: " << Name << endl; }  

    // Getter methods for staff details
    string getName() const { return Name; }
    string getPosition() const { return Position; }
    double getSalary() const { return salary; }

    // Pure virtual function for polymorphism (different behavior in derived classes)
    virtual void StaffDetailsDisplay() const = 0;
};

// Derived Class: Manager (Specific type of staff with additional office location info)
class Manager : public Staff {
private:
    string officeLocation;

public:
    // Constructor to initialize both staff and office location details
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    // Display staff details along with office location
    void StaffDetailsDisplay() const override {
        cout << "Staff Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << "Office Location: " << officeLocation << endl;  // Display office location
    }
};

// Class to manage a collection of offices and staff members
class OfficeHouse {
private:
    string OfficeHouseName;
    vector<Office*> Offices;  
    vector<Staff*> StaffMembers; 

public:
    // Constructor to initialize office house name
    OfficeHouse(string name = "") : OfficeHouseName(name) {
        cout << "OfficeHouse created: " << OfficeHouseName << endl;
    }

    // Destructor to clean up created offices and staff members
    ~OfficeHouse() {
        cout << "OfficeHouse destroyed: " << OfficeHouseName << endl;  
        for (Office* office : Offices) delete office;  
        for (Staff* staff : StaffMembers) delete staff; 
    }

    // Set the name of the office house
    void setOfficeHouseName(string name) { OfficeHouseName = name; }

    // Add an office to the office house
    void AddOffice(Office* office) { Offices.push_back(office); }
    // Add a staff member to the office house
    void AddStaff(Staff* person) { StaffMembers.push_back(person); }

    // Get details of all offices and staff members in the office house
    void GetOfficeHouseDetails() const {
        cout << "Company Name: " << OfficeHouseName << endl;
        cout << "Departments: " << endl;
        for (const Office* office : Offices) office->OfficeDetailsDisplay();  
        cout << "Staff Details: " << endl;
        for (const Staff* staff : StaffMembers) staff->StaffDetailsDisplay(); 
    }
};

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

        // Loop to add offices to the office house
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

            // Create and add new TechOffice to the office house
            Office* techOffice = new TechOffice(deptName, staffCount, permanent, techArea);
            OfficeHouse1->AddOffice(techOffice);
        }

        cout << "Enter Number of Staff Members: ";
        cin >> numberOfStaff;
        cin.ignore();

        // Loop to add staff members to the office house
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

            // Create and add new Manager to the office house
            Staff* manager = new Manager(name, position, salary, location);
            OfficeHouse1->AddStaff(manager);
        }

        // Display office house details
        OfficeHouse1->GetOfficeHouseDetails();
        delete OfficeHouse1;  
    }

    return 0;
}
