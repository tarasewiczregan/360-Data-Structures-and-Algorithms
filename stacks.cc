#include <iostream>
using namespace std;

class Chunk {
public:
	int x;
	Chunk *next;
	
	Chunk() {
		x = 0;
		next = NULL;
	}
};

//class called "Stack" which is going to create a stack of Chunks
class Stack {
public:
	Chunk *top;		//the main pointer is called "top"
	
	Stack() {
		top = NULL;
	}
	
	//three functions that Stack should perform: add, remove and display
	//1: function to add chunks to our stack
	void push(int value) {
		//check to see if it's empty
		if (top == NULL) {
			top = new Chunk;
			top -> x = value;
		}
		else {
			//stack is not empty, knit it into the structure
			Chunk *temp;
			temp = new Chunk;
			temp -> x = value;
			temp -> next = top;
			top = temp;
		}
	}
	
	//2: function that deletes from the stack
	void pop() {
		//if your stack is empty
		if (top == NULL) {
			cout << "Nothing to delete, it's already empty" <<endl;
			return;
		}
		else {
			Chunk *temp;
			temp = top;
			top = top -> next;
			cout << "About to delete value: " << temp -> x << endl;
			delete temp;
		}
	}
	
	//3: function that displays the stack
	void display() {
		//if it's empty...
		if (top == NULL) {
			cout << "Nothing to see..." << endl;
		}
		else {
			Chunk *temp = top;
			while (temp != NULL) {
				cout << temp -> x << endl;
				temp = temp -> next;
			}
		}
	}
};

int main() {
	Stack myStack;
	int choice = 0;
	int value;
	while (1) {
		cout << "Press 1 to add" << endl;
		cout << "Press 2 to delete" << endl;
		cout << "Press 3 to display" << endl;
		cin >> choice;
		switch(choice) {
			case 1: 
				cout << "Add what?" << endl;
				cin >> value;
				myStack.push(value);
				break;
			case 2:
				myStack.pop();
				break;
			case 3:
				myStack.display();
				break;
		}
	}
	
	return 0;
}
