#include "Student.h"
#include<iostream>
using namespace std;

Student::Student(string name, vector<string> languages,
        int experience,vector<string> available_days,vector<string> subjects, int rating):
        name(name),language(language),experience(experience),available_days(available_days)
            ,subjects(subjects),rating(rating),final_Score(0){}

string Student::get_name()const{
    return name;
}

vector<string> Student::get_language()const{
    return language;
}

int Student :: get_experience()
{
    return experience;
}

vector<string> Student:: get_available_days()const
{
    return available_days;
}

vector<string> Student::get_subjects()const
{
    return subjects;
}

int Student:: get_rating()
{
    return rating;
}

void Student::set_rated_value(int value)
{
    final_Score=value;
}


void Student::connect_with_mentor()
{
    is_connected= true;
}

bool Student::getIsConnected()
  { 
    return is_connected; 
    }


void Student::request(Student & sender)
{
    cout<<"Recieved rqst from student : "<< sender.get_name();
    cout<<endl;
    cout<<"Do you want to accept the request ?\n"<<"enter yes or no :";
    string response;
    cin>>response;
    if(response == "yes")
    {
        cout<<" request accepted ..\n";
    }
    else
    {
        cout<<"Request rejected ..\n";
    }

}   
int Student::get_rated_value()const
{ return final_Score; }