#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
    string surname;
    string name;
    int marks[3];
    int credits;
    int index; // порядковый номер студента в исходном файле
};

bool operator<(const Student& s1, const Student& s2) {
    if (s1.credits != s2.credits) {
        return s1.credits > s2.credits;
    } else if (s1.surname != s2.surname) {
        return s1.surname < s2.surname;
    } else {
        return s1.index < s2.index;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<Student> students(n);
    for (int i = 0; i < n; ++i) {
        fin >> students[i].surname >> students[i].name;
        for (int j = 0; j < 3; ++j) {
            fin >> students[i].marks[j];
        }
        students[i].credits = 0;
        students[i].index = i;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (students[i].marks[j] >= 65) {
                ++students[i].credits;
            }
        }
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < n; ++i) {
        fout << students[i].surname << ' ' << students[i].name << ' ';
        for (int j = 0; j < 3; ++j) {
            fout << students[i].marks[j] << ' ';
        }
        fout << endl;
    }

    return 0;
}
