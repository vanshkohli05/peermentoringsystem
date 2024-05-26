#include "MentorSystem.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>


void MentorSystem::add_student(const Student& student)
{
    students.push_back(student);
    
}


void MentorSystem::read_data_from_file(string& filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student student = read_student_data(ss);
        add_student(student);
    }
    file.close();
}




void MentorSystem::display_student_info(Student& student)
{
    cout<<"Name : "<<student.get_name()<<endl;
    cout<<"Proficient language : ";
    for(auto& lang :student.get_language())
    {
        cout<<" "<<lang;
    }

    cout<<endl;
    cout<<"Experience : "<<student.get_experience()<<" years"<< endl;
    cout<<"Available Days : ";
    for(auto& day : student.get_available_days())
    {
        cout<< " "<<day;
    }

    cout<< endl;

    cout << "Best Subjects:";
    for (const auto& subj : student.get_subjects()) {

        cout << " " << subj;
    }
    cout << std::endl;
    cout << "Rating: " << student.get_rating() << endl;
    cout << "Ranking: " << student.get_rated_value() << endl;
    cout << std::endl;

}



void MentorSystem::write_data_to_file(const string& filename)
{
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    for (auto& student : students) {
        write_student_data(student,file);
    }

    file.close();
    cout << "Student data saved to file: " << filename << endl;
}


vector<Student> MentorSystem:: matching_algorithm(string language, 
string day, string subject, string prioritizedParam, int ratingWeight)
{
    vector<Student> matchingStudents= students;

    int language_weight=20;
    int experience_weight=20;
    int availability_weight=20;
    int subject_weight=20;



    if(prioritizedParam=="language")
    {
        language_weight=30;

     }
    
    else if (prioritizedParam == "experience")
     {
        experience_weight = 30;
    } 
    else if (prioritizedParam == "availability") {
        availability_weight = 30;
    } 
    else if (prioritizedParam == "subject") {
        subject_weight = 30;
    } 
    else if (prioritizedParam == "rating") {
        ratingWeight = 30;
    }


    for (auto& student : matchingStudents) 
    {
        int ratedValue = (student.get_language().size() * language_weight) +
                         (student.get_experience() * experience_weight) +
                         (student.get_available_days().size() * availability_weight);

    
    if (prioritizedParam == "subject") {
            bool hasSubject = false;
            for (auto& subj :student.get_subjects() ) {
                if (subj == subject) {
                    hasSubject = true;
                    break;
                }
            }
            // If the mentor doesn't have the subject, assign a rating of 0
            if (!hasSubject) {
                ratedValue += 0;
            } 
            else {
                ratedValue += subject_weight;
            }
    }
        else {
            ratedValue += (student.get_subjects().size() * subject_weight);
        }

        ratedValue += (student.get_rating() * ratingWeight);
        student.set_rated_value(ratedValue);
}

int size = static_cast<int>(matchingStudents.size());
for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
        if (matchingStudents[i].get_rated_value()< matchingStudents[j].get_rated_value()) {
            swap(matchingStudents[i], matchingStudents[j]);
        }
    }
}
return matchingStudents;

}


void MentorSystem::connect_stdnt_wth_mntr(Student& student,Student& mentor) {
    student.connect_with_mentor();


    cout << "Connected with mentor: " << mentor.get_name() << endl;
}


void MentorSystem::sendRequestToMentor(const Student& mentor, const Student& sender) {
    cout << "Received request from student: " << sender.get_name() << std::endl;
    cout << "Details of requester:\n";
    cout << "Name: " << sender.get_name() << std::endl;
    cout << "Proficient Languages:";
    for (auto& lang : sender.get_language()) {
        cout << " " << lang;
    }
    cout << endl;
    cout << "Available Days:";
    for (auto& day : sender.get_available_days()) {
        cout << " " << day;
    }
    cout << endl;
    cout << "Help in subject:";
    for (const auto& subj : sender.get_subjects()) {
        cout << " " << subj;
    }
    cout << endl;




    cout << "Do you want to accept the request? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes") {
        cout << "Request accepted!\n";
    } else {
        cout << "Request rejected.\n";
    }
}



Student MentorSystem::read_student_data(istream& stream)
{
     string name, language, availableDaysStr, bestSubjectsStr;
    vector<string> proficientLanguages, availableDays, Subjects;
    int experience, rating;

    getline(stream, name);
    stream >> experience >> rating;
    stream.ignore(); // Consume newline character

    getline(stream, language);
    stringstream ssLang(language);
    while (getline(ssLang, language, ',')) {
        proficientLanguages.push_back(language);
    }

    getline(stream, availableDaysStr);
    stringstream ssDays(availableDaysStr);
    while (getline(ssDays, language, ',')) {
        availableDays.push_back(language);
    }

    getline(stream, bestSubjectsStr);
    stringstream ssSubjects(bestSubjectsStr);
    while (getline(ssSubjects, language, ',')) {
        Subjects.push_back(language);
    }

    
    string separator;
    getline(stream, separator);

    return Student(name, proficientLanguages, experience, availableDays, Subjects, rating);
   
}




void MentorSystem::write_student_data(Student& student,ostream& stream)
{
    stream << student.get_name() << std::endl;
    stream << student.get_experience() << " " << student.get_rating() << std::endl;

    stream << student.get_language()[0];
    for (size_t i = 1; i < student.get_language().size(); ++i) {
        stream << "," << student.get_language()[i];
    }
    stream << std::endl;

    stream << student.get_available_days()[0];
    for (size_t i = 1; i < student.get_available_days().size(); ++i) {
        stream << "," << student.get_available_days()[i];
    }
    stream << std::endl;

    stream << student.get_subjects()[0];
    for (size_t i = 1; i < student.get_subjects().size(); ++i) {
        stream << "," << student.get_subjects()[i];
    }
    stream << endl;
}


