#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
private:
    double getAvg() const {
        return (score[0] + score[1] + score[2]) / 3.0;
    }

public:
    string name;
    string sid;
    int *score;

    Student() {
        score = new int[3];
    }

    ~Student() {
        delete[] score;
    }

    void print() const {
        cout << "[" << sid << "] " << name << endl;
        cout << "The Average score is " << fixed << setprecision(1) << getAvg() << endl;
    }
};

int main() {
    Student student;

    // 학생 정보 입력
    cin >> student.sid >> student.score[0] >> student.score[1] >> student.score[2];
    
    cin.ignore(); // 버퍼 비우기

    getline(cin, student.name);

    // 학생 정보 출력
    student.print();

    return 0;
}
