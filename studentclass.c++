#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// ================= STUDENT CLASS =================
class Student {
private:
    string indexNumber;
    string fullName;

public:
    // Constructor
    Student(string idx, string name) {
        indexNumber = idx;
        fullName = name;
    }

    // Getters
    string getIndexNumber() const {
        return indexNumber;
    }

    string getFullName() const {
        return fullName;
    }

    // Display student details
    void display() const {
        cout << indexNumber << " - " << fullName << endl;
    }
};

// Vector to store students
vector<Student> students;

// ================= FUNCTION DECLARATIONS =================
void loadStudentsFromFile();
void saveStudentsToFile();
void registerStudent();
void viewStudents();
void searchStudent();

// ================= MAIN FUNCTION =================
int main() {

    loadStudentsFromFile();

    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM (WEEK 1) =====\n";
        cout << "1. Register Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// ================= LOAD STUDENTS =================
void loadStudentsFromFile() {
    ifstream file("students.txt");

    if (!file) {
        return; // File doesn't exist yet
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idx, name;

        getline(ss, idx, ',');
        getline(ss, name);

        students.push_back(Student(idx, name));
    }

    file.close();
}

// ================= SAVE STUDENTS =================
void saveStudentsToFile() {
    ofstream file("students.txt");

    for (const Student &s : students) {
        file << s.getIndexNumber() << "," 
             << s.getFullName() << endl;
    }

    file.close();
}

// ================= REGISTER STUDENT =================
void registerStudent() {
    string idx, name;

    cout << "Enter Index Number: ";
    cin >> idx;
    cin.ignore();

    cout << "Enter Full Name: ";
    getline(cin, name);

    // Check duplicate
    for (const Student &s : students) {
        if (s.getIndexNumber() == idx) {
            cout << "Student already exists!\n";
            return;
        }
    }

    students.push_back(Student(idx, name));
    saveStudentsToFile();

    cout << "Student registered successfully!\n";
}

// ================= VIEW STUDENTS =================
void viewStudents() {
    if (students.empty()) {
        cout << "No students registered.\n";
        return;
    }

    cout << "\n===== REGISTERED STUDENTS =====\n";
    for (const Student &s : students) {
        s.display();
    }
}

// ================= SEARCH STUDENT =================
void searchStudent() {
    string idx;

    cout << "Enter Index Number to search: ";
    cin >> idx;

    for (const Student &s : students) {
        if (s.getIndexNumber() == idx) {
            cout << "Student Found:\n";
            s.display();
            return;
        }
    }

    cout << "Student not found.\n";
}
