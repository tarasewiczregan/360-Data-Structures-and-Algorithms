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

int main() {
	Chunk *head, *helper;
	
	//task-0: set up
	head = new Chunk;
	head -> next = new Chunk;
	head -> next -> next = new Chunk;
	
	//task-1: add a new chunk to the beginning
	helper = new Chunk;
	helper -> next = head;
	head = helper;
	
	//task-2: get rid of first chunk
	helper = head;
	head = head -> next;
	delete helper;

	//task-3: add a new chunk all the way at the end
	head -> next -> next -> next = new Chunk;
	
	//task-4: undo task-3
	helper = head -> next -> next -> next;
	head -> next -> next -> next = NULL;
	delete helper;
	
	//task-5: insert a chunk in position 2
	helper = new Chunk;
	helper -> next = head -> next;
	head -> next = helper;
	
	//task-6: undo task-5
	helper = head -> next;
	head -> next = head -> next -> next;
	delete helper;
	
	return 0;
}
