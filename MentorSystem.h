#ifndef MENTORSYSTEM_H
#define MENTORSYSTEM_H

#include "Student.h"
#include <vector>
#include<string>
using namespace std;

class MentorSystem
{
    private:
    vector<Student> students;


    public:
    
    void add_student(const Student& student);

    void read_data_from_file(string& filename);

    void display_student_info(Student& student);

    void write_data_to_file(const string& filename);

    vector<Student>  matching_algorithm(string language, string day,string subject,
    string prioritized_param,int rating_weight);

    void connect_stdnt_wth_mntr(Student& student, Student& mentor);

    void sendRequestToMentor(const Student& mentor,  const Student& sender);

    Student read_student_data(istream& stream);

    void write_student_data(Student& student, ostream& stream);   

};

#endif