#include <iostream>
using namespace std;

class Chunk {
public:
	int value;
	Chunk *next;
	
	Chunk() {
		value = 0;
		next = NULL;
	}
};

class Queue {
public:
	Chunk *head;
	
	Queue() {
		head = NULL;
	}
	
	//1: Add Chunks
	void enqueue(int x) {
		if (head == NULL) {
			head = new Chunk;
			head -> value = x;
		}
		else {
			Chunk *helper = new Chunk;
			helper -> value = x;
			helper -> next = head;
			head = helper;
		}
	}
	
	//2: Delete Chunks
	void dequeue() {
		if (head == NULL) {
			cout << "Empty Queue, nothing here to remove.." << endl;
		}
		else if (head -> next == NULL) {
			cout << "About to delete: " << head -> value << endl;
			delete head;
			head = NULL;
		}
		else {
			Chunk *chase, *follow = new Chunk;
			chase = follow = head;
			while (chase -> next != NULL) {
				follow = chase;
				chase = chase -> next;
			}
			follow -> next = NULL;
			cout << "About to delete: " << chase -> value << endl;
			delete chase;
		}
	}
	
	//3: Display
	void display() {
		if (head == NULL) {
			cout << "Nothing to see..." << endl;
		}
		else {
			Chunk *temp = head;
			while (temp != NULL) {
				cout << temp -> value << endl;
				temp = temp -> next;
			}
		}
	}
};

int main() {
	Queue q;
	int choice, val;
	
	while (1) {
		cout << "Press 1 to enqueue" << endl;
		cout << "Press 2 to dequeue" << endl;
		cout << "Press 3 to display" << endl;
		cin >> choice;
		switch(choice) {
			case 1: 
				cout << "Add what?" << endl;
				cin >> val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.display();
				break;
		}
	}

	return 0;
}
