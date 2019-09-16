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

class Stack {
public:
	Chunk *top;	
	
	Stack() {
		top = NULL;
	}
	
	//1: Add Chunks
	void push(int value) {
		if (top == NULL) {
			top = new Chunk;
			top -> x = value;
		}
		else {
			Chunk *temp;
			temp = new Chunk;
			temp -> x = value;
			temp -> next = top;
			top = temp;
		}
	}
	
	//2: Delete Chunks
	void pop() {
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
	
	//3: Display
	void display() {
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
