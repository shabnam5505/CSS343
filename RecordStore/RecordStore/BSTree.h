
//Writen by: Shabnam Basmani, Date: 2/20/15
//This BST serves as a container for TreeData objects 
//Objects will not be inserted if there are duplicates; instead a quanity counter in TreeData will be incremented 
//Objects will only be deleted if quanity in TreeData is set to 1
//Additional functionally is given in the .h file
//This file contains the functionally of the binary search tree which stores a pointer to the character data


#pragma once
#include <iostream>
using namespace std;

class TreeData;
//Node struct contains a pointer to a TreeData obj, a right and left pointer to create the BST, and a counter for duplicate objects 
class BSTree
{
	  struct Node 
	  {
		  TreeData* data;           // pointer to actual data stored
		  Node* left;               // pointer to left child Node, left subtree
		  Node* right;    
		  Node()
		  {
			  left = NULL;
			  right = NULL;
		  }
	  };
	  

	//output operator overload will allow the << to recognize a BST object (can be used to print out to console)
	//Post Condition: The << operator will recognize a BSTree object
	friend ostream& operator<<(ostream &os, BSTree &obj);

public:
	//Default constructor
	BSTree(void);
	//Constructor that takes in a TreeData* obj. Will set root equal to null and insert obj into BST.
	BSTree(TreeData* t);

	//Insert method allows you to insert a TreeData object into the BST
	//Precondition: must pass in a pointer to TreeData obj and assumes the tree is sorted in non-decending order
	//Postcondtion: inserts an object into the binary search tree or if object already exists increments quanity on TreeData and returns true if data is inserted
	bool insert(TreeData *);


	//Make Empty deletes all elements from the BST
	//No preconditions
	//Postcondition: removes all nodes and their data from the BST
	void makeEmpty();

	//isEmpty returns if the tree is empty or not
	//Preconditions: none
	//Postconditions: will return a bool depending on the whether or not the tree is empty
	bool IsEmpty();
	

	//Retrive method returns the address of the TreeData obj stored in the BST if it exists
	//Precondtion: must pass at const ref to a TreeData obj
	//Postcondition: returns a pointer to the object on the BST or NULL if no object exists
	const TreeData *retrieve(const TreeData &);

	//Remove method allows you to remove a TreeData object from the BST
	//Precondition: must pass in a const TreeData obj and assumes data is sorted in a non-decending order
	//Postcondition: removes a given obj from the BST or deincrements the quanity and returns true if obj is found and removed
	bool remove(TreeData &);

	//Overloaded copy constructor is used to create a deep copy of all objects in the BST for a newly created object
	//no preconditions will be used when necessary automatically
	//Postcondition: After copy is complete you should have two BST's that are identical without reusing pointers
	BSTree(const BSTree &obj);

	//Overloaded assignment operator will assign the this object the values and data of the BST being passed in. Should create a deep copy.
	//no preconditions will be used when necessary automatically
	//Postcondition: After assignment is complete you should two BST's that are indentical without reusing pointers
	BSTree& operator=(const BSTree &source);

	
	//Overloaded equals operator checks to see if two BST are equal to one another by comparing all of the data in the TreeData and BST
	//no preconditions
	//will return true if BST's are the same and false if not
	bool operator==(const BSTree& obj) const;

	//Overloaded not equals operator checks to see if two BST are not equal to one another by comparing all of the data in the TreeData and BST
	//no preconditions
	//will return false if BST's are the same and true if not
	bool operator!=(const BSTree& obj) const;

	//This is the default destructor which calls make empty to clean up the tree
	virtual ~ BSTree(void);

	//Output method retrives all node pointer to the tree
	//Preconditions: Tree must have already been initialized
	//Postconditions: will return values to other classes in order to print out data
	void Output();
private:

	//Node pointer to the head of the tree
   Node* root;

   //Output helper is a helper method for output
   //Preconditions: Tree must have already been intialized
   //Postconditions: Will use the root pointer to trace through the tree returning all values in order
   Node* outputHelper(Node *root);


   //Helper method for the makeEmpty method needed to pass in the root Node
   //Precondition: takes a Node pointer
   //Postcondition: Recusively calls itself until to delete all nodes and their data in the BST
   void deleteTree(Node* &ptr);

	//Helper method for the insert method needed to pass in the root Node
	//Precondition: takes a Node pointer and TreeData pointer and assumes the tree is sorted in non-decending order
	//Postcondition: Recusively calls itself until it finds a place in the tree to insert the node and returns if inserted
   bool insertHelper(Node *&ptr, TreeData *obj);

	//Helper method for the retrive method needed to pass in the root Node
	//Precondition: takes a Node pointer and const ref TreeData obj
	//Postcondition: Recusively calls itself until if finds the given obj and returns a pointer to the data
   const TreeData *retriveHelper(Node *ptr, const TreeData &obj);

   	//This is a helper method for serveral other methods to check if the object exists so the counter can be updated if the value already exists
	//Precondition: takes a Node pointer and const ref TreeData obj
	//Postcondition: Finds if an object already exists on the Tree and returns a pointer to that Node
	//this is method is used for determining if the quanity of an object needs to be incremented or decremented
   Node* findDups(Node *ptr, const TreeData &t);

	//Helper method remove method needed to pass in the root Node
	//Precondition: takes a Node pointer and const ref TreeData obj
	//Postcondition: Calls the proper method that will handles deleting a node and its data and returns a bool
   bool deleteNode(Node *& root,TreeData &item);

	//Helper method for the deleteNode method 
	//Precondition: takes a Node pointer 
	//Postcondition: Deletes the root node and handles special cases for removing a Node and data
   void deleteRoot(Node *&root);

	//Helper method for the deleteRoot method needed to pass in the root Node
	//Precondition: takes a Node pointer 
	//Postcondition: Determines with TreeData obj is on the left side and returns a pointer to a TreeData obj
   TreeData *findAndDeleteSmallest(Node *&root);

   	//Helper method for the output method 
	//Precondition: must pass in a ostream and node pointer
	//Postcondition: Sets the ostream to take in the data of each Node on the tree
	ostream& outputHelper(ostream &output, Node *root);
	
	//Helper method for the overloaded operator 
	//Precondition: must pass in an ostream
	//Postcondition: Calls the outputHelper method passing in the root node
	ostream& Output(ostream &output);

	friend ostream& operator<<(ostream &os, BSTree &obj);

};