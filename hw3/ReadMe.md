# ReadMe for COMP 15 HW3
## ISIS Course Roster and Waitlists

1.  Purpose: to model the Tufts SIS task of placing students into a course 
    that has certain requirements. Model details:
    - students who are majoring in the subject go directly into the class
      roster (unless the class is at its defined capacity, in which case
      they go onto the waitlist for majors)
    - non-majors go directly onto the non-major waitlist (if there is extra
      space in the class after all majors are enrolled, non-majors will be 
      added
    - students can be dropped from the class, in which case people come off
      the waitlist in the order above until the class is at capacity 

2.  List of files:
    - IsisCourse.h
    - IsisCourse.cpp
    - Set.h
    - Set.cpp
    - Queue.h
    - Queue.cpp
    - ReadMe.md

3.  Compile: use included Makefile

4.  Abstract Data Types used:
    - Sets (data structure: dynamic arrays)
    - Queues (data structure: dynamic arrays)

5.  Algorithm:
    - the course is modelled with the Class "IsisCourse" 
    - the set models the actual class roster i.e. a list of students in the class
    - the Queue models the two waitlists: the waitlists for students majoring in
      the subject, and the waitlist for non-majors 

6.  Credit: 
    - Jialu Wei and I discussed ideas for this homework - she gave me the idea 
    of using helper functions to make my code more modular
    - Dylan Phelan was an incredibly helpful TA! 

