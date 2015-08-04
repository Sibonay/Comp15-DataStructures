/*
 * IsisCourse.cpp
 *
 */

#include <iostream>
#include "IsisCourse.h"
using namespace std; 

IsisCourse::IsisCourse() {
	class_capacity = 0; // no students allowed in yet
}

IsisCourse::IsisCourse(int init_capacity) {
	class_capacity = init_capacity;
}

IsisCourse::~IsisCourse() {
	// nothing to do
}

void IsisCourse::set_class_cap(int cap) {
	class_capacity = cap;
	if (roster.size() < class_capacity) {
		update_enrollments();
	}
}

IsisCourse::ENROLLMENT_STATUS IsisCourse::enroll_student(Student s) {
	if (s.major) { // student is a major so will go directly into class 
		if (get_roster_size() == class_capacity) { // class is full
			major_waitlist.enqueue(s);  // put on major waitlist
			return MAJOR_WAITLIST;
		} else { // there is space in the class 
			roster.add(s); // student added to class 
			return ENROLLED;
		}
	} else { // student is not a major, goes directly onto waitlist
			other_waitlist.enqueue(s);
			return OTHER_WAITLIST;
	}
}

bool IsisCourse::drop_student(Student s) {	
	bool found_student = false; // if we find the student to drop
	
	found_student = roster.drop(s); // tries to drop student from class
	
	// if student was not in class
	// tries to remove student from major waitlist
	// if not on major waitlist, tries to remove from minor waitlist
	if (found_student == false) {
		found_student = remove_student_from_waitlist(&major_waitlist, s, 
							   found_student); 
		if (found_student == false) {
			found_student = remove_student_from_waitlist(
					&other_waitlist, s, found_student);
		}
	}

	// if we dropped a student, there should be room on the roster
	update_enrollments();
	return found_student; // true if student has been successfully dropped
}

	
int IsisCourse::waitlist_position(ENROLLMENT_STATUS status, Student s) {
	int position;
	
	if (status == NONE) {  
	    position = -1;
	} if (status == MAJOR_WAITLIST) {
		position = find_position(&major_waitlist, s);
	} if (status == OTHER_WAITLIST) {
		position = find_position(&other_waitlist, s);
	}
	    
	return position;    
}

// returns an ENROLLMENT_STATUS that says which list
// (or none) that the student is on.
IsisCourse::ENROLLMENT_STATUS IsisCourse::status(Student s) {
	if (roster.is_enrolled(s)) { 
		return 	ENROLLED;
	}
	else if (is_on_waitlist(&major_waitlist, s)) {
		return MAJOR_WAITLIST;
	} else if (is_on_waitlist(&other_waitlist, s)) {
		return OTHER_WAITLIST;
	}
	else {
		return NONE; // student is neither enrolled in class 
	}	             // nor on a waitlist	
}

void IsisCourse::print_list(ENROLLMENT_STATUS status) {
	Queue *waitlist_queue;
	Queue temp_queue;
	if (status == ENROLLED) {
		roster.print_class();
		return;
	}
	if (status == MAJOR_WAITLIST) {
		waitlist_queue = &major_waitlist;
	}
	else {
		waitlist_queue = &other_waitlist;
	}
	
	// prints either the major waitlist or the other waitlist, depending on
	// the student's enrollment status
	// prints in the form "<waitlist position>. <name>"
	Student current;
	int waitlist_position = 1;

	while (!waitlist_queue->is_empty()) {
		current = waitlist_queue->dequeue();
		cout << waitlist_position << ". " << current.name << endl;
		temp_queue.enqueue(current); 
		waitlist_position++;
	}
	// puts all students back in the original queue
	while (!temp_queue.is_empty()) {
		current = temp_queue.dequeue();
		waitlist_queue->enqueue(current);
	}
}

// put students from the waitlists into the class
// in priority (majors first, then others), up to
// the class capacity.
void IsisCourse::update_enrollments() {
	int space_in_class = (get_class_cap() - get_roster_size());
	// moves students from major waitlist into class first
	// stops when major waitlist is emptied or class is at capacity
	while ((space_in_class > 0) and (!major_waitlist.is_empty())) { 
		Student current = major_waitlist.dequeue();
		roster.add(current);
		space_in_class--;
	} // moves students from other waitlist into class
	while ((space_in_class > 0) and (!other_waitlist.is_empty())) { 
		Student current = other_waitlist.dequeue();
		roster.add(current);
		space_in_class--;
	}
}

bool IsisCourse::remove_student_from_waitlist(Queue *waitlist, Student s, 
					    bool found_student) {
	Queue temp_queue;
	Student current;
	bool has_been_found = found_student; 
	
	while (!waitlist->is_empty()) {
		current = waitlist->dequeue();
		if (current.name == s.name) {
			has_been_found = true;
			continue; // does not move this particular student to
				  // the temp queue (therefore student is 
				  // removed from waitlist altogether)
		}
		temp_queue.enqueue(current); 
	}
	while (!temp_queue.is_empty()) {
		current = temp_queue.dequeue();
		waitlist->enqueue(current);
	}
	return has_been_found;
}

// assumes that student s is definitely in the waitlist 
int IsisCourse::find_position(Queue *waitlist, Student s) {
	int position = 0;	
	Queue temp_queue;
	Student current;

	// dequeues and then requeues entire waitlist (so waitlist is not
	// changed), but position value stops increasing when student is found
	while (!waitlist->is_empty()) {
		current = waitlist->dequeue();
		temp_queue.enqueue(current);
		position++;
		
		if (current.name == s.name) {
			while (!waitlist->is_empty()) {
				current = waitlist->dequeue();
				temp_queue.enqueue(current);
			}
			break;
		}
	}
	while (!temp_queue.is_empty()) {
		current = temp_queue.dequeue();
		waitlist->enqueue(current);
	}
	return position;
}


bool IsisCourse::is_on_waitlist(Queue *waitlist, Student s) {
	Queue temp_queue;
	Student current;
	bool found_student = false; // true if student is on waitlist 
	
	while (!waitlist->is_empty()) {
		current = waitlist->dequeue();
		temp_queue.enqueue(current); 

		if (current.name == s.name) {
			found_student = true;
		}
	}
	while (!temp_queue.is_empty()) {
		current = temp_queue.dequeue();
		waitlist->enqueue(current);
	}
	
	return found_student;
}