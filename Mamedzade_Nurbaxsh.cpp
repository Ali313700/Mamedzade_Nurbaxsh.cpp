#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    string studentId;
    vector<float> grades;
    float average;
};

float calculateAverage(const vector<float>& grades) {
    float sum = 0;
    for (float grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

void editStudent(Student& student) {
    cout << "\nEdit student information:\n";
    cout << "Enter student's first name: ";
    getline(cin, student.firstName);

    cout << "Enter student's last name: ";
    getline(cin, student.lastName);

    cout << "Enter student ID: ";
    getline(cin, student.studentId);

    int numGrades;
    cout << "Enter the number of grades: ";
    cin >> numGrades;
    cin.ignore();

    student.grades.resize(numGrades);

    cout << "Enter the grades:\n";
    for (int i = 0; i < numGrades; ++i) {
        cout << "Grade " << i + 1 << ": ";
        cin >> student.grades[i];
    }
    cin.ignore();

    student.average = calculateAverage(student.grades);
}

void deleteStudent(vector<Student>& students, int index) {
    students.erase(students.begin() + index);
}

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();

    vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent number " << i + 1 << ":\n";

        cout << "Enter student's first name: ";
        getline(cin, students[i].firstName);

        cout << "Enter student's last name: ";
        getline(cin, students[i].lastName);

        cout << "Enter student ID: ";
        getline(cin, students[i].studentId);

        int numGrades;
        cout << "Enter the number of grades: ";
        cin >> numGrades;
        cin.ignore();

        students[i].grades.resize(numGrades);

        cout << "Enter the grades:\n";
        for (int j = 0; j < numGrades; ++j) {
            cout << "Grade " << j + 1 << ": ";
            cin >> students[i].grades[j];
        }
        cin.ignore();

        students[i].average = calculateAverage(students[i].grades);
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display student information\n";
        cout << "2. Edit student information\n";
        cout << "3. Delete student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\nStudent information:\n";
            for (int i = 0; i < students.size(); ++i) {
                cout << "\nStudent number " << i + 1 << ":\n";
                cout << "First Name: " << students[i].firstName << "\n";
                cout << "Last Name: " << students[i].lastName << "\n";
                cout << "Student ID: " << students[i].studentId << "\n";
                cout << "Average: " << students[i].average << "\n";
                cout << "Grades: ";
                for (float grade : students[i].grades) {
                    cout << grade << " ";
                }
                cout << "\n";
            }
        } else if (choice == 2) {
            int index;
            cout << "Enter the student number to edit (starting from 1): ";
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= students.size()) {
                editStudent(students[index - 1]);
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 3) {
            int index;
            cout << "Enter the student number to delete (starting from 1): ";
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= students.size()) {
                deleteStudent(students, index - 1);

cout << "Student deleted successfully.\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}