#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<vector>
using namespace std;
class Student{
    private:
    string name;
    vector<string> language;
    vector<string>available_days;
    vector<string> subjects;
    int experience;
    int rating;
    int final_Score;
    bool is_connected;
    

    public:
    Student(string name,vector<string> languages,int experience,
    vector<string> available_days,vector<string> subjects, int rating);


    string get_name()const;
    vector<string> get_language()const;
    int get_experience();
    vector<string> get_available_days()const;
    vector<string> get_subjects()const;
    int get_rating();

    int get_rated_value()const;

    void set_rating(int value);

    void connect_with_mentor();
    void request( Student& sender);

void set_rated_value(int value);


    bool getIsConnected() ;

};


#endif