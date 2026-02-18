#include <iostream>
#include <fstream>

using namespace std;

// ================= ATTENDANCE SESSION CLASS =================
class AttendanceSession {
private:
    string courseCode;
    string date;
    string startTime;
    int duration; // in hours

public:
    // Constructor
    AttendanceSession(string code, string d, string time, int dur) {
        courseCode = code;
        date = d;
        startTime = time;
        duration = dur;
    }

    // Generate filename
    string generateFileName() const {
        return "session_" + courseCode + "_" + date + ".txt";
    }

    // Save session details to file
    void saveToFile() const {
        string filename = generateFileName();
        ofstream file(filename);

        if (!file) {
            cout << "Error creating session file.\n";
            return;
        }

        file << "Course Code: " << courseCode << endl;
        file << "Date: " << date << endl;
        file << "Start Time: " << startTime << endl;
        file << "Duration: " << duration << " hours" << endl;
        file << "----------------------------------------" << endl;

        file.close();
        cout << "Session created successfully!\n";
        cout << "File created: " << filename << endl;
    }
};

// ================= FUNCTION =================
void createLectureSession() {
    string courseCode, date, startTime;
    int duration;

    cout << "\n===== CREATE LECTURE SESSION =====\n";

    cout << "Enter Course Code: ";
    cin >> courseCode;

    cout << "Enter Date (YYYY_MM_DD): ";
    cin >> date;

    cout << "Enter Start Time (HH:MM): ";
    cin >> startTime;

    cout << "Enter Duration (hours): ";
    cin >> duration;

    AttendanceSession session(courseCode, date, startTime, duration);
    session.saveToFile();
}

// ================= MAIN =================
int main() {

    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM (WEEK 2) =====\n";
        cout << "1. Create Lecture Session\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createLectureSession();
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 2);

    return 0;
}
