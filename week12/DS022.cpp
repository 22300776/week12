#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int lc;
    int rc;

    bool isValidScore(int score) const {
        return score >= 0 && score <= 495;
    }

public:
    Student() : lc(0), rc(0) {}

    Student(string name, int lc, int rc) : name(name), lc(lc), rc(rc) {}

    void input() {
        getline(cin, name);

        
        while (!(cin >> lc) || !isValidScore(lc)) {
            cout << "LC> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    
        while (!(cin >> rc) || !isValidScore(rc)) {
            cout << "RC> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void print() const {
        cout << "[" << name << "]" << endl;
        cout << "LC - " << lc << " " << (lc >= 350 ? "Pass" : "Fail") << endl;
        cout << "RC - " << rc << " " << (rc >= 350 ? "Pass" : "Fail") << endl;
        cout << "Total - " << (lc + rc) << endl;
    }
};

int main() {
    Student student;
    student.input();
    student.print();

    return 0;
}
