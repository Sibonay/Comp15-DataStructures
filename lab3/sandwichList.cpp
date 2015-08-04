/* sandwichList.cpp
 * Comp 15 
 * Spring 2014 
 * Lab 4
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];
	orderCount = 0;

	back = 0;
	front = 0;
}

SandwichList::~SandwichList(){
	delete[] orders;
}

bool SandwichList::isEmpty()
{
	if (orderCount() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{    
    return orderCount;
        // you could use the following arithmetic (but be careful):
	//return (back - front + capacity) % capacity; -> but only works if not full
}

//function to remove Order from the front of the queue
Order SandwichList::dequeue()
{
    Order order_at_front = orders[front];
    front = (front + 1) % capacity;
    orderCount--; 
    return order_at_front;
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::enqueue(const Order& sw)
{
    if (orderCount == capacity) {
	expandList();
    }
    orders[back] = sw; 
    back = (back + 1) % capacity;
    orderCount++;
}



//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
    Order *temparray = new Order[capacity * 2];
    
    for (int i = 0; i < orderCount; i++) {
	temparray[i] = orders[(front + i) % capacity];
    }
    
    front = 0;
    back = orderCount; 
    
    delete[] orders;
    orders = temparray;
    capacity = capacity * 2;

}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



