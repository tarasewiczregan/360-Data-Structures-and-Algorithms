/* Name: Regan Tarasewicz
 * Pledge: "I pledge my honor that I have abided by the Stevens Honor System." 
 */

#include <iostream>
#include <vector>
using namespace std;

class treeNode {
public:
	int value;
	treeNode *right, *left;

	treeNode() {
		value = 0;
		right = left = NULL;
	}
};

class BST { //Binary Search Tree
public:
	treeNode *root;

	BST() {
		root = NULL;
	}
	//functions that a BST must perform 
	// 1. search for a value 
	void searchBST(int key, treeNode *start) {
		//check to see if you found it (anchor value)
		if (start == NULL) {
			cout << "Could not find value." << endl;
			return;
		}
		else if (key == start -> value){
			cout << "Found it!" << endl;
			return;
		} 
		else {
			if (key > start->value) {
				searchBST(key, start -> right);
			} 
			else {
				searchBST(key, start -> left);
			}
		}
	}
	
	// 2. Add values 
	void addNodeBST(int key) {
		//start by searching for this value
		//if you find it, don't add it
		//if you don't find it, add it where you should have found it
		treeNode *slow, *fast = root;
		
		if (root == NULL) {
			root = new treeNode;
			root -> value = key;
			return;
		}
		else {	
			while (fast != NULL) {
				if (fast -> value == key) {
					//Duplicate, don't add
					cout << "Duplicate" << endl;
					return;
				}
				else if (key > fast -> value) {
					slow = fast;
					fast = fast -> right;
				}
				else {
					slow = fast;
					fast = fast -> left;
				}
			}
		}

		treeNode *temp = new treeNode;
		temp -> value = key;
		
		//does it get added to the left or right
		if (key < slow -> value)
			slow -> left = temp;
		else
			slow -> right = temp;
	}
	
	// 3. Delete values
	//first find the node
	//figure out what kind of node (leaf, 1 child, 2 children)
	void deleteNodeBST(int key, treeNode *start) {
		treeNode *slow, *fast = start;
		
		if (start == NULL) {
			cout << "The tree is empty." << endl;
			return;
		}
		else {
			//loop through to find key value 
			while (fast != NULL || fast -> value != key) {
				if (fast -> value == key) {
					break;
				}
				else if (key > fast -> value) {
					slow = fast;
					fast = fast -> right;
				}
				else {
					slow = fast;
					fast = fast -> left;
				}
			} 
			if(fast == NULL) { 
				cout << "Key not found in tree." << endl; 
				return;
			}
		
			else {
				//Case I: leaf node (no children)
				if (fast -> left == NULL && fast -> right == NULL) {
					if (slow -> left == fast) {
						delete fast;
						slow -> left = NULL;
					}
					else {
						delete fast;
						slow -> right = NULL;
					}
				}
				//Case II: Has exactly one child
				//Four if statements to see if it is left/right and inner left/right that needs to be replaced
				else if ((fast -> left == NULL && fast -> right != NULL) || (fast -> left != NULL && fast -> right == NULL)) {

					if (slow -> right == fast) { 
						if (fast -> right != NULL) {
							slow -> right = fast -> right; 
							delete fast;
						}
						else {
							slow -> right = fast -> left;
							delete fast;
						}
					}
					else if (slow -> left == fast) { 
						if (fast -> right != NULL) {
							slow -> left = fast -> right;  
							delete fast;
						}
						else {
							slow -> left = fast -> left;
							delete fast;
						}
					}
				}
				//Case III: Has two children
				else {
					int replace = minValRSubTree(fast -> right);
					deleteNodeBST(replace, fast);
					fast -> value = replace;
				}
			}
		}
	}
	
	int minValRSubTree(treeNode *start){
		treeNode *temp = start;
		while (temp -> left != NULL) {
			temp = temp -> left;
		}
		return temp -> value;
	}

	void inorder(treeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			inorder(start -> left);
			cout << start -> value << " " << endl;
			inorder(start -> right);
		}
	}
	void preorder(treeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			cout << start -> value << " " << endl;
			preorder(start -> left);
			preorder(start -> right);
		}
	}
	
	void postorder(treeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			inorder(start -> left);
			inorder(start -> right);
			cout << start -> value << " " << endl;
		}
	}
	
	void deleteTree(treeNode *start) {
		if (start == NULL) {
			return;
		}
		else {
			deleteTree(start -> left);
			deleteTree(start -> right);
			cout << "About to delete: " << start -> value << endl;
			delete start;
		}
	}
	
	bool isBalanced(treeNode *start) {
		int rightHeight, leftHeight;
		
		if (start == NULL) {
			return 0;
		}
		else {
			rightHeight = findHeight(start -> right);
			leftHeight = findHeight(start -> left);
			if (((rightHeight - leftHeight) <= 1) && ((rightHeight - leftHeight) >= -1)) {
				if ((isBalanced(start -> right)) && (isBalanced(start -> left))){
					return 1;
				}
			}
			return 0;
		}
	}
	
	int findHeight(treeNode *start) {
		if (start == NULL) {
			return 0;
		}
		else {
			int height = findMax(findHeight(start -> left), findHeight(start -> right));
			return height + 1;
		}
	}
	
	int findMax(int value1, int value2) {
		if (value1 < value2) {
			return value1;
		}
		else {
			return value2;
		}
	}
	
	 bool findPath(treeNode *start,vector<int> &path, int k) {
        if (start == NULL) {
			return false;
		}
        
        path.push_back(start -> value);
        
        if (start -> value == k) {
            return true;
		}
        
        if ( (start -> left && findPath(start -> left, path, k)) ||
            (start -> right && findPath(start -> right, path, k)) ) {
            return true;
		}
 
        path.pop_back();
        return false;
    }
	int firstCommonParent(int value1, int value2) {
        vector<int> path1, path2;
		int i;
        
        if (!findPath(root, path1, value1) || !findPath(root, path2, value2)) {
            return -1;
        }
        
        for (i = 0; i < path1.size() && i < path2.size() ; i++)
            if (path1[i] != path2[i])
                break;
        return path1[i-1];
	}
};

int main()
{
	BST myTree;
	int choice, value, value2;
	while (1) {
		cout << "Press 1 to add BST" << endl;
		cout << "Press 2 to search" << endl;
		cout << "Press 3 to delete" << endl;
		cout << "Press 4 to display in order" << endl;
		cout << "Press 5 to display pre-order" << endl;
		cout << "Press 6 to display post-order" << endl;
		cout << "Press 7 to delete the tree" << endl;
		cout << "Press 8 to check if tree is balanced" << endl;
		cout << "Press 9 to find common parent of two nodes" << endl;
		cin >> choice;

		switch(choice) {
			case 1: cout << "Add what?" << endl;
				cin >> value;
				myTree.addNodeBST(value);
				break;
			case 2: cout << "What are you looking for?" << endl;
				cin >> value;
				myTree.searchBST(value, myTree.root);
				break;
			case 3: cout << "What value do you want to delete?" << endl;
				cin >> value;
				myTree.deleteNodeBST(value, myTree.root);
				break;
			case 4: myTree.inorder(myTree.root);
				break;
			case 5: myTree.preorder(myTree.root);
				break;
			case 6: myTree.postorder(myTree.root);
				break;
			case 7: myTree.deleteTree(myTree.root);
				myTree.root = NULL;
				break;
			case 8: 
				if (myTree.isBalanced(myTree.root)){
					cout << "Tree is balanced." << endl;
				}
				else {
					cout << "Tree is not balanced." << endl;
				}
				break;
			case 9: cout << "Please enter first value." << endl;
				cin >> value;
				cout << "Please enter second value." << endl;
				cin >> value2;
				cout << myTree.firstCommonParent(value, value2) << endl;
				break;
		}
	}
	return 0;
}
