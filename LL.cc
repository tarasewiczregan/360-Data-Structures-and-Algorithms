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

//a linked list of chunks
class LL {
public:
	Chunk *head;
	int = length; //keep track of how many chunks you have
	
	//0: Constructor
	LL() {
		head = NULL;
		length = 0;
	}
	
	//1: Function that let's you add chunks
	void insertAtPos(int x, int pos) {
		//figure out if the position is valid
		if (pos > 0 && pos <= length + 1) {
			Chunk *temp = new Chunk;
			temp -> value = x;
			//let's figure out case - I/II/III (i.e., first, last, or middle)
			if (pos == 1) {
				//case I: All the way to the front
				temp -> next = head;
				head = temp;
			}
			else if (pos == length + 1) {
				//case II: All the way to the end
				Chunk *helper = head;
				while (helper -> next != NULL) {
					helper = helper -> next;
				}
				//at this point, helper is all the way at the end
				helper -> next = temp;
			}
			else {
				//adding somewhere in the middle
				Chunk *helper = head;
				for (int i = 1; i < pos -1; i ++) {
					helper = helper -> next;
				}
				temp -> next = helper -> next;
				helper -> next = temp;
			}
			length ++; //do not forget!!
		}
		else {
			cout << "Invalid position, cannot add." << endl;
		}
	}
	
	//2: Function to remove chunks
	void removeFromPos(int pos) {
		//figure out if this position is valid
		if (pos > 0 && pos <= length) {
			//case I, II, or III: first, last, or somwhere in the middle
			if (pos == 1) {
				Chunk *temp = head;
				head = head -> next;
				delete temp;
				//same as Stack
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
	
	//3: Function to display
};

int main() {
	
	
	return 0;
}
