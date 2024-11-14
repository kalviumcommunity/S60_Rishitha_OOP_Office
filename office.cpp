#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    ~Office() {
        cout << "Office destroyed: " << departmentName << endl;
    }

    void AssignOfficeDetails(string deptName, int staffCount, bool permanent) {
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

    void OfficeDetailsDisplay() const {
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

    void StaffDetailsDisplay() const {
        cout << "Staff Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: $" << getSalary() << endl;
    }
};

class Manager : public Staff {
private:
    string officeLocation;

public:
    // Constructor that also takes office location
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    void AssignManagerDetails(string n, string pos, double s, string location) {
        AssignStaffDetails(n, pos, s);
        officeLocation = location;
    }

    string getOfficeLocation() const {
        return officeLocation;
    }

    void ManagerDetailsDisplay() const {
        Staff::StaffDetailsDisplay();
        cout << "Office Location: " << officeLocation << endl;
    }
};

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
        string managerName;
        double managerSalary;
        string location;

        cout << "Enter OfficeHouse manager name: ";
        getline(cin, managerName);
        cout << "Enter Manager Salary: ";
        cin >> managerSalary;
        cout << "Enter Location: ";
        cin.ignore();
        getline(cin, location);

        Manager manager1(managerName, "Manager", managerSalary, location);
        manager1.ManagerDetailsDisplay();
        cout << endl;

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

            Office* office = new Office(deptName, staffCount, permanent);
            OfficeHouse1->AddOffice(office);
        }

        cout << "Enter Total Number of Staff for the Office House: ";
        cin >> NumberOfStaff;
        cin.ignore();

        for (int i = 0; i < NumberOfStaff; i++) {
            string personName;
            string pos;
            double s;

            cout << "Enter details of " << i + 1 << " staff member: " << endl;
            cout << "Staff Name: ";
            getline(cin, personName);
            cout << "Position: ";
            getline(cin, pos);
            cout << "Salary: $";
            cin >> s;
            cin.ignore();

            Staff* person = new Staff(personName, pos, s);
            OfficeHouse1->AddStaff(person);
        }

        cout << endl;
        OfficeHouse1->GetOfficeHouseDetails();
        delete OfficeHouse1;
    }

    cout << "Total number of Office Houses: " << OfficeHouse::getOfficeHouseCount() << endl;
    return 0;
}
