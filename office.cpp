#include <iostream>
#include <vector>
using namespace std;

class Office {
private:
    string departmentName;
    int noofStaff;
    bool isPermanent;

public:
    void OfficeDisplay() {
        cout << "This is an Office class" << endl;
    }

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
    void StaffDisplay() {
        cout << "I am a staff person in this Office." << endl;
    }

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

int main() {
    Office Office1;
    Staff Person1;

    Office1.OfficeDisplay();
    Person1.StaffDisplay();

    Office1.AssignOfficeDetails("Human Resources", 10, true);
    Office1.OfficeDetailsDisplay();

    cout << endl;

    Person1.AssignStaffDetails("Alice", "HR Manager", 60000);
    Person1.StaffDetailsDisplay();

    return 0;
}
