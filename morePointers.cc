#include <iostream>
using namespace std;

class Tab {
public:
	int width;
	int height;
	Tab *next;
	
	Tab() {
		width = 40;
		height = 20;
		next = NULL;
	}

};

int main() {
	Tab *ptr;
	Tab *helper;
	
	//first tab
	//<pointer> = new <type-of-object>
	ptr = new Tab;
	
	//let's jounrey into this chunk in the heap using the pointer
	//change width 100, height 60
	ptr -> width = 100;
	ptr -> height = 60;
	
	//new tab connected to the first one
	ptr -> next = new Tab;
	ptr -> next -> width = 140;
	ptr -> next -> height = 40;
	
	//let's create a third box; such that the second one points to the third
	ptr -> next -> next = new Tab;
	ptr -> next -> next -> width = 180;
	ptr -> next -> next -> height = 190;
	
	//ptr -> next -> next = NULL; //never do this without thinking
	//^you get rid of the location, can't find it again even though you still own it
	
	//let's create a new tab, and we'll knit this in and make it the "first" tab
	helper = new Tab;
	helper -> next = ptr; //ptrA = ptrB :: addr in ptrB is copied into ptrA
	ptr = helper;
	
	//to remove a chunk, use 'delete'
	//delete <pointer>; --> won't delete the pointer, but it deletes the chunk
	helper = ptr; //save the addr of the chunk you want to delete
	ptr = ptr -> next;
	delete helper;
	
	
	
	return 0;
}
