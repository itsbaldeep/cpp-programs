#include <iostream>
#include <string.h>

using namespace std;

class Student {
    protected:
        int roll_no;
        char name[40];
        char address[100];
        float percentage;

    public:
        Student();
        Student(int roll_no, const char* name, const char* address, float percentage);
        void display();
};

class WorkingStudent : public Student {
    private:
        int salary;

    public:
        WorkingStudent();
        WorkingStudent(int roll_no, const char* name, const char* address, float percentage, int salary);
        void display();
};

int main() {
    cout << "Enter details of Student" << endl;
    Student s;
    cout << endl << "Student details" << endl;
    s.display();

    cout << endl << "Enter details of Working Student" << endl;
    WorkingStudent ws;
    cout << endl << "Working student details" << endl;
    ws.display();

    return 0;
}

Student::Student() {
    cout << "Enter the student roll number: ";
    cin >> roll_no;
    getchar();
    cout << "Enter the student name: ";
    cin.getline(name, 40);
    cout << "Enter the student address: ";
    cin.getline(address, 100);
    cout << "Enter the student percentage: ";
    cin >> percentage;
}

Student::Student(int roll_no, const char* name, const char* address, float percentage) {
    this->roll_no = roll_no;
    strcpy(this->name, name);
    strcpy(this->address, address);
    this->percentage = percentage;
}

void Student::display() {
    cout << "Student Roll No.: " << roll_no << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Address: " << address << endl;
    cout << "Student Percentage: " << percentage << endl;
}

WorkingStudent::WorkingStudent() : Student() {
    cout << "Enter the salary: ";
    cin >> salary;
}

WorkingStudent::WorkingStudent(int roll_no, const char* name, const char* address, float percentage, int salary) : Student(roll_no, name, address, percentage) {
    this->salary = salary;
}

void WorkingStudent::display() {
    Student(*this).display();
    cout << "Student Salary: " << salary << endl;
}

