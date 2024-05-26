#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<string>
#include <queue>


#include "MentorSystem.h"
using namespace std;


int main()
{
    MentorSystem mentorSystem;

    int choice;
    bool running = true;

    while (running) {
        cout << "\nOptions:\n";
        cout << "1. Add a student\n";
        cout << "2. Search for a mentor\n";
        cout << "3. Save student data to file\n";
        cout << "4. Exit\n";
        
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, language, availableDaysStr, bestSubjectsStr;
                vector<string> proficientLanguages, availableDays, bestSubjects;
                int experience, rating;

                cout << "Enter student name: ";
                cin >> name;

                cin.ignore();

                cout << "Enter proficient languages (comma-separated): ";
                getline(cin, language);
                istringstream iss(language);
                while (getline(iss, language, ',')) {
                    proficientLanguages.push_back(language);
                }

                cout << "Enter experience (in years): ";
                cin >> experience;

                cin.ignore();

                cout << "Enter available days (comma-separated): ";
                getline(cin, availableDaysStr);
                istringstream issDays(availableDaysStr);
                while (getline(issDays, language, ',')) {
                    availableDays.push_back(language);
                }

                cout << "Enter subjects known best (comma-separated): ";
                getline(cin, bestSubjectsStr);
                istringstream issSubjects(bestSubjectsStr);
                while (getline(issSubjects, language, ',')) {
                    bestSubjects.push_back(language);
                }

                cout << "Enter rating (1-10): ";
                cin >> rating;

                mentorSystem.add_student(Student(name, proficientLanguages, experience, availableDays, bestSubjects, rating));
                break;
            }
            case 2: {
                string language, day, subject, prioritizedParam;
                int ratingWeight;

                cout << "Enter the language you're proficient in: ";
                cin >> language;
                cout << "Enter the day you're available (e.g., Monday): ";
                cin >> day;
                cout << "Enter the subject you want to learn: ";
                cin >> subject;
                cout << "Enter the parameter you want to prioritize (language, experience, availability, subject, rating): ";
                cin >> prioritizedParam;

                if (prioritizedParam == "rating") {
                    cout << "Enter the weight for rating (out of 100): ";
                    cin >> ratingWeight;
                } else {
                    ratingWeight = 20;
                }

                // Retrieve mentors based on user input
                vector<Student> matchingStudents = mentorSystem.matching_algorithm(language, day, subject, prioritizedParam, ratingWeight);

                // Display the matching students with their rankings
                cout << "\nMatching students:\n";
                for (int i = 0; i < matchingStudents.size(); ++i) {
                    cout << i + 1 << ". ";
                    mentorSystem.display_student_info(matchingStudents[i]);
                    cout << endl;
                }

                // Request a mentor
                cout << "Choose a mentor to send a request (enter corresponding number): ";
                int mentorIndex;
                cin >> mentorIndex;
                if (mentorIndex > 0 && mentorIndex <= matchingStudents.size()) {
                    Student& chosenMentor = matchingStudents[mentorIndex - 1];
                    mentorSystem.sendRequestToMentor(chosenMentor, Student("Requester", {language}, 0, {day}, {subject}, 0));
                } else {
                    cout << "Invalid mentor choice.\n";
                }
                break;
            }
            case 3:
                mentorSystem.write_data_to_file("student_data.txt");
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
