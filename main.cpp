#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void remove(int data);
	  int sum();
    void display();
};

// Initialize the lists management information
LinkedList::LinkedList(){
    this->length = 0; // Your code here
    this->head = NULL; // Your code here
}

// Clear the list management information and release all allocated Nodes
LinkedList::~LinkedList(){
   Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		delete current;
		current = this->head;
    }
    std::cout << "LIST DELETED: " << this->length << std::endl;
}

// Add a new node that contains 'data'
void LinkedList::add(int dat){ //changed "data" to "dat"


  // Your code here
  Node* p = new Node;
  
  p->data = dat; //send help pls SOS
  p->next = head;
  head = p;
  length++;
}


// Locate the node that contains 'val' in the list and remove the node
void LinkedList::remove(int val){
  
  // Your code here
  Node* current = head;
  Node* previous = new Node;
  while(current && current->data != val){
    previous = current;
    current = current->next;
  }
  if (current){
    if(current->next == head){
      head = current->next;
    }
    else if(current->next != head){
      previous->next = current->next;
    }
  }
  delete current;
  length--;
}


// Sum all the integer data elements in the list
int LinkedList::sum(){
  
  // Your code here
    int sum = 0;
    Node* current = head;
    while(current){
        sum += current->data;
        current = current->next;
    } 
    
	  return sum;
}

// print the entire list's data
void LinkedList::display(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}


// Main performs various list operations and reports results
int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
	int j = 49;
	int sum = 0;
	int testSum = 0;
	
	// Install inital values in list
    for (int i = 0; i < 50; i += 2)
    {
		testSum = testSum + i + j;
        list->add(i);
        list->add(j);
		j -= 2;
    }
	
    list->display();
	std::cout << "List initial sum: " << testSum << std::endl;
	sum = list->sum(); //help here
	std::cout << "List initial sum: " << sum << std::endl;
	if (sum != testSum)
	{
		std::cout << "Ooops!  Initialization failed" << std::endl;
		return(1);
	}
 
	// Test 1
	std::cout << std::endl << "- - - -" << std::endl;
	list->remove(2);
    list->display();
    std::cout << "List Length: " << list->length << std::endl;
	sum = list->sum();
	std::cout << "sum 1: " << sum << std::endl;
	
	// Test 2
	std::cout << std::endl << "- - - -" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		list->remove(i);
	}
    list->display();
    std::cout << "List Length: " << list->length << std::endl;
	sum = list->sum();
	std::cout << "sum 2: " << sum << std::endl;
 
    delete list;
    return 0;
}
