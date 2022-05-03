#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
    private:
        // Variables
        string studentName;
        int ID;
        int studentNumber;
        string diplomaName;
        double averageMark;
        string modules[5];
        int results[5];

    public:
        Student();
        ~Student();

        double calcAverage();

        bool pass();
        void displayResults();

        // Accessors
        string getStudentName();
        int getID();
        int getStudentNumber();
        string getDiplomaName();
        double getAverageMark();
        string getModuleName(int index);

        // Mutators
        void setStudentName(string name);
        void setID(int id);
        void setStudentNumber(int num);
        void setDiplomaName(string dipName);
        void setAverageMark(double mark);
        void setExamResult(int r, int index);

        friend ostream &operator << (ostream &outs, const Student &s);
};
//----CLASSEND----------//
// Default constructor
Student::Student() {
    studentName = "";
    ID = 0;
    studentNumber = 0;
    diplomaName = "";
    averageMark = 0;
    for (int i = 0; i < 5; i++) {
        modules[i] = "";
        results[i] = 0;
    }
}

// Destructor
Student::~Student() {
    cout << "Bye!" << endl;
}
double Student::calcAverage() {
    double temp = 0.0;
    for (int i = 0; i < 5; i++) {
        temp += results[i];
    }
    averageMark = temp / 5.0;
    return temp / 5.0;
}
bool Student::pass() {
    for (int i = 0; i < 5; i++) {
    if (results[i] < 50) {
    return false;
}
}
return false;
}
void Student::displayResults() {
    cout << studentName << endl;
    cout << studentNumber << endl;
    cout << diplomaName << endl;
    for (int i = 0; i < 5; i++) {
        cout << modules[i] << ": " << results[i] << endl;
    }
    cout << "AVERAGE MARK: " << averageMark << endl;
    if (pass()) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }

    cout << endl;
}

// Accessors
string Student::getStudentName() {
    return studentName;
}
int Student::getID() {
    return ID;
}
int Student::getStudentNumber() {
    return studentNumber;
}
string Student::getDiplomaName() {
    return diplomaName;
}
double Student::getAverageMark() {
    return averageMark;
}
string Student::getModuleName(int index) {
    return modules[index];
}

// Mutators
void Student::setStudentName(string name) {
    studentName = name;
}
void Student::setID(int id) {
    ID = id;
}
void Student::setStudentNumber(int num) {
    studentNumber = num;
}
void Student::setDiplomaName(string dipName) {
    diplomaName = dipName;
    if (diplomaName == "Garden Design") {
    for (int i = 0; i < 5; i++) {
    modules[i] = "G" + to_string(i + 1);
    }
    } else if (diplomaName == "Gourmet Cooking") {
    for (int i = 0; i < 5; i++) {
    modules[i] = "C" + std::to_string(i + 1);
}
}
}
void Student::setAverageMark(double mark) {
    averageMark = mark;
}
void Student::setExamResult(int r, int index) {
    results[index] = r;
}

ostream& operator << (ostream &outs, const Student &s) {
    bool pass = true;

    outs << "Student name: " << s.studentName << endl;
    outs << "Student ID: " << s.ID << endl;
    outs << "Student number: " << s.studentNumber << endl;
    outs << "Diploma name: " << s.diplomaName << endl;
    for (int i = 0; i < 5; i++) {
        outs << s.modules[i] << ": " << s.results[i] << endl;
        if (s.results[i] < 50) {
            pass = false;
}
}

outs << "AVERAGE MARK: " << s.averageMark << endl;
if (pass) {
    outs << "Result: PASSED" << endl << endl;
} else {
    outs << "Result: FAILED" << endl << endl;
}

return outs;
}

//--------FUNCTIONSEND---------//
int main() {
    Student students[3];

    students[0].setStudentName("John Martin");
    students[1].setStudentName("Busi Molefe");
    students[2].setStudentName("Sean Naidoo");

    students[0].setID(78120189);
    students[1].setID(81011201);
    students[2].setID(69812018);

    students[0].setStudentNumber(12345);
    students[1].setStudentNumber(23456);
    students[2].setStudentNumber(34567);

    students[0].setDiplomaName("Garden Design");
    students[1].setDiplomaName("Gourmet Cooking");
    students[2].setDiplomaName("Garden Design");

    for (int i = 0; i < 3; i++) {
        cout << students[i].getStudentName() << endl;
        cout << students[i].getID() << endl;
        cout << students[i].getStudentNumber() << endl;
        cout << students[i].getDiplomaName() << endl;
        cout << "Enter results: " << endl;
        for (int j = 0; j < 5; j++) {
            int mark;
            cout << students[i].getModuleName(j) << ": ";
            cin >> mark;
            students[i].setExamResult(mark, j);
}
        cout << endl;
}
    students[0].calcAverage();
    students[1].calcAverage();
    students[2].calcAverage();

    ofstream fout;
    fout.open("RegisteredStudentsResults");

    if (fout.fail()) {
        cout << "Failed to output to file." << endl;
        exit(1);
    }

    fout << students[0] << students[1] << students[2];
    fout.close();

    cout << endl;
    cout << "RESULTS:" << endl;

    students[0].displayResults();
    students[1].displayResults();
    students[2].displayResults();

    return 0;
}


