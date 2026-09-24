## Project Overview

The Peer Mentoring System is a console-based C++ application designed to help students find suitable mentors based on their skills, experience, availability, subjects, and ratings. The system maintains student profiles and uses a weighted matching algorithm to rank potential mentors according to the user's requirements.

The application allows users to add student profiles containing information such as proficient languages, experience, available days, subjects, and ratings. Users can then search for mentors by specifying their preferred language, availability, and subject, while also choosing a parameter to prioritize during matching.

The mentor matching algorithm calculates a weighted score using language, experience, availability, subjects, and rating. Users can prioritize one of these parameters, increasing its contribution to the final score. Potential mentors are then ranked based on their calculated scores and displayed to the user.

The system also supports sending mentor requests, allowing the selected mentor to accept or reject a request. Student information can be saved to a file for persistent storage.

The project demonstrates object-oriented programming in C++, including the use of classes, encapsulation, STL containers, string parsing, file handling, and a weighted scoring and ranking algorithm.
