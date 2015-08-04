/*
 * Queue.cpp
 *
 */

#include <iostream>
#include "Queue.h"

// constructor
Queue::Queue() {
	capacity = QUEUE_INIT_CAPACITY; 
	queue_array = new Student[QUEUE_INIT_CAPACITY];
	size = 0;

	back = 0;
	front = 0;
}

// destructor
Queue::~Queue() {
	delete [] queue_array;
}

// enqueue a char onto at the back of the queue
void Queue::enqueue(Student c) {
	if (size == capacity) {
		expand();
	}
	queue_array[back] = c; 
	back = (back + 1) % capacity;
	size++;
}

// dequeue a char from the front of the queue
Student Queue::dequeue() {
	Student student_at_front = queue_array[front];
	front = (front + 1) % capacity;
	size--; 
	return student_at_front;
}

// returns true if there are no elements in the
// queue, false if the queue has elements
bool Queue::is_empty() {
	if (size == 0)
		return true;
	else
		return false;
    }

//Double the queue size, copy the values, and reset back and front
void Queue::expand()
{
	Student *temparray = new Student[capacity * 2];
	
	for (int i = 0; i < size; i++) {
		temparray[i] = queue_array[(front + i) % capacity];
	}
	
	front = 0;
	back = size; 
	
	delete[] queue_array;
	queue_array = temparray;
	capacity = capacity * 2;

}