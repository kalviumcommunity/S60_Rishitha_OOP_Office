#include <iostream>
#include <vector>
using namespace std;

class Office{
    private :
    string departmentName;
    int noofStaff;
    bool isPermanent;

    public:

    void OfficeDisplay(){
        cout<<"This a Office class"<<endl;
    }
};

class Staff{
    private:
    string Name;
    string Position;
    double salary;

    public:

    void StaffDisplay(){
      cout<<"I am a staff person in this Office."<<endl;
    }
};

int main(){
Office Office1;
Staff Person1;

Office1.OfficeDisplay();
Person1.StaffDisplay();

};