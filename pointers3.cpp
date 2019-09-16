#include <iostream>
using namespace std;


class Tab {
public:
	Tab *next;

	Tab() {
		width = 30;
		height = 30;
		next = NULL;
	}
};

int main(){
	Tab *head, *helper;
	//first table
	head = new Tab;
	
	//second tab, such that first points to it
	head -> next = new Tab;
	
	head -> next -> next = new Tab;
	
	head -> next -> next -> next = new Tab;
	
	//task1: delete the last chunk
	//set helper to pointer to the last chunk
	helper = head -> next -> next -> next;
	delete helper;
	head -> next -> next -> next = NULL;
	
	//task2: add the fourth chunk back
	head -> next -> next -> next = new Tab
	//put 10s, 20s, 30s, and 40s in the chunks
	head -> width = head -> height = 10;
	head -> next -> width = head -> next -> height = 20;
	head -> next -> next -> width = head -> next -> next -> height = 30;
	head -> next -> next -> next -> width = head -> next -> next -> next -> height = 40;
	
	//task3: delete the third chunk
	//helper gets the addr of the third chunk
	helper = head -> next -> next;
	head -> next -> next = head -> next -> next -> next; //head -> next -> next = helper -> next
	cout << "About to delete" << endl;
	cout << helper -> width << " " << helper -> height;
	delete helper;
	cout << head -> next -> next -> width << endl;
	
	//task4: let's add that chunk back (between the 2nd and 3rd)
	//first get a new tab
	helper = new Tab;
	helper -> width = helper -> height = 30;
	helper -> next = head -> next -> next;
	head -> next -> next = helper;
	//just confirming the third is back!
	cout << head -> next -> next -> width << endl;
	
	
	return 0;
}
