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

class LL {
public:
	Chunk *head;
	int length; 
	
	LL() {
		head = NULL;
		length = 0;
	}
	
	//1: Add Chunks
	void insertAtPos(int x, int pos) {
		if (pos > 0 && pos <= length + 1) {
			Chunk *temp = new Chunk;
			temp -> value = x;
			
			if (pos == 1) {
				//Add to Front
				temp -> next = head;
				head = temp;
			}
			else if (pos == length + 1) {
				//Add to End
				Chunk *helper = head;
				while (helper -> next != NULL) {
					helper = helper -> next;
				}
				helper -> next = temp;
			}
			else {
				//Add to Middle
				Chunk *helper = head;
				for (int i = 1; i < pos -1; i ++) {
					helper = helper -> next;
				}
				temp -> next = helper -> next;
				helper -> next = temp;
			}
			length ++;
		}
		else {
			cout << "Invalid position, cannot add." << endl;
		}
	}
	
	//2: Delete Chunks
	void removeFromPos(int pos) {
		if (pos > 0 && pos <= length) {
			if (pos == 1) {
				Chunk *temp = head;
				head = head -> next;
				delete temp;
			}
			else if (pos == length) {
				Chunk *helper = head;
				while (helper -> next -> next != NULL) {
					helper = helper -> next;
				}
				delete helper -> next;
				helper -> next = NULL;
			}
			else {
				Chunk *fast, *slow;
				fast = slow = head;
				for (int i = 1; i < pos; i++) {
					slow = fast;
					fast = fast -> next;
				}
				slow -> next = fast -> next;
				delete fast;
			}
			length --;
		}
		else {
			cout << "Can't delete stuff that does not exist." << endl;
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
	LL l;
	int choice, val, pos;
	
	while (1) {
		cout << "Press 1 to add" << endl;
		cout << "Press 2 to delete" << endl;
		cout << "Press 3 to display" << endl;
		cin >> choice;
		switch(choice) {
			case 1: 
				cout << "Add what?" << endl;
				cin >> val;
				cout << "Where do you want to put it?" << endl;
				cin >> pos;
				l.insertAtPos(val, pos);
				break;
			case 2:
				cout << "Which position are you removing?" << endl;
				cin >> pos;
				l.removeFromPos(pos);
				break;
			case 3:
				l.display();
				break;
		}
	}
	
	return 0;
}
