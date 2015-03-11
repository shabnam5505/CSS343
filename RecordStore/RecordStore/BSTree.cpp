//Writen by: Shabnam Basmani, Date: 2/20/15
//This BST serves as a container for TreeData objects 
//Objects will not be inserted if there are duplicates; instead a quanity counter in TreeData will be incremented 
//Objects will only be deleted if quanity in TreeData is set to 1
//Additional functionally is given in the .h file
//This file contains the functionally of the binary search tree which stores a pointer to the character data
#include "BSTree.h"
#include "TreeData.h"


//Default constructor
//No preconditions
//Postconditions: creates a new instance of a BSTree object
BSTree::BSTree(void)
{
	root = NULL;
}

//This is a helper method for serveral other methods to check if the object exists so the counter can be updated if the value already exists
//Precondition: takes a Node pointer and const ref TreeData obj
//Postcondition: Finds if an object already exists on the Tree and returns a pointer to that Node
//this is method is used for determining if the quanity of an object needs to be incremented or decremented
BSTree::Node* BSTree::findDups(Node *ptr, const TreeData &t)
{
	if (ptr == NULL) 
		return NULL;
	else if (t == *ptr->data)
	{
		return ptr;
	}
	else if (t < *ptr->data)
	{
		return findDups(ptr->left, t);
	}
	else
	{
		return findDups(ptr->right, t);
	}
}

//updateQuanity is used when inventory items are loaded orginally, this allows for inventory to specifify 
//how many items are being initialized
//Preconditions: An pointer to the object as already been inserted in the tree
//Postconditions: Updates the counter variable on the node
void BSTree :: updateQuanity(TreeData *obj, int numOfItems)
{
	Node *updateNode = findDups(root, *obj);
	updateNode->counter = numOfItems;
}

//Insert method allows you to insert a TreeData object into the BST
//Precondition: must pass in a pointer to TreeData obj and assumes the tree is sorted in non-decending order
//Postcondtion: inserts an object into the binary search tree or if object already exists increments quanity on TreeData and returns true if data is inserted
bool BSTree::insert(TreeData *obj)
{
	if (root == NULL)
	{
		Node *ptr = new Node;
		root = ptr;
		root->data = obj;	
		return true;

	}
	return insertHelper(root, obj);
}

//Helper method for the insert method needed to pass in the root Node
//Precondition: takes a Node pointer and TreeData pointer and assumes the tree is sorted in non-decending order
//Postcondition: Recusively calls itself until it finds a place in the tree to insert the node and returns if inserted
bool BSTree :: insertHelper(Node *&ptr, TreeData *obj)
{
	Node *t = findDups(ptr, *obj);
	if (t != NULL)
	{
		t->counter ++;
		delete obj;
		obj = NULL;
		return true;
	}

	if (ptr == NULL)
	{
		Node *temp = new Node;
		ptr = temp;
		ptr->data = obj;
		return true;
	}
	 if (*obj < *ptr->data)
	{
		return insertHelper(ptr->left, obj);
	}
	else 
		return insertHelper(ptr->right, obj);
}


//Remove method allows you to remove a TreeData object from the BST
//Precondition: must pass in a const TreeData obj and assumes data is sorted in a non-decending order
//Postcondition: removes a given obj from the BST or deincrements counter and returns true if obj is found and removed
bool BSTree::remove(TreeData &obj)
{
	return deleteNode(root, obj);
}

//Helper method remove method needed to pass in the root Node
//Precondition: takes a Node pointer and const ref TreeData obj
//Postcondition: Calls the proper method that will handles deleting a node and its data and returns a bool
bool BSTree :: deleteNode(Node *& root,TreeData &item)
{
	if (root == NULL) return false;
	if (*root->data == item)
	{
		//if (root->data->getQuanity() == 1)
		if(root->counter == 1)
		{
			deleteRoot(root);
			return true;
		}
		else
		{
			root->counter --;
			return true;
		}
	}


	if (item < *root->data)
		return deleteNode(root->left, item);
	else
		return deleteNode(root->right, item);
}

//Helper method for the deleteNode method 
//Precondition: takes a Node pointer 
//Postcondition: Deletes the root node and handles special cases for removing a Node and data
void BSTree::deleteRoot(Node *&todelete)
{
	if (todelete->right == NULL && todelete->left == NULL)
	{
		delete todelete->data;
		todelete->data = NULL;
		delete todelete;
		todelete = NULL;
	}
	if (todelete->left == NULL)
	{
		Node *temp = todelete;
		todelete = todelete->right;
		delete temp->data;
		temp->data = NULL;
		delete temp;
		temp = NULL;
	}
	else if (todelete->right == NULL)
	{
		Node *temp = todelete;
		todelete = todelete->left;
		delete temp->data;
		temp->data = NULL;
		delete temp;
		temp = NULL;
	}
	else
	{
		delete todelete->data;
		todelete->data = findAndDeleteSmallest(todelete->right);
	}

		
}

//Helper method for the deleteRoot method needed to pass in the root Node
//Precondition: takes a Node pointer 
//Postcondition: Determines with TreeData obj is on the left side and returns a pointer to a TreeData obj
TreeData* BSTree::findAndDeleteSmallest(Node *&todelete)
{
	if (todelete->left == NULL)
	{
		TreeData *item = todelete->data;
		Node *temp = todelete;
		todelete = todelete->right;
		delete temp;
		temp = NULL;
		return item;
	}
	else
		return findAndDeleteSmallest(todelete->left);
}



//Retrive method returns the address of the TreeData obj stored in the BST if it exists
//Precondtion: must pass at const ref to a TreeData obj
//Postcondition: returns a pointer to the object on the BST or NULL if no object exists
const TreeData* BSTree :: retrieve(const TreeData &obj)
{
	return retriveHelper(root, obj);
}

//Helper method for the retrive method needed to pass in the root Node
//Precondition: takes a Node pointer and const ref TreeData obj
//Postcondition: Recusively calls itself until if finds the given obj and returns a pointer to the data
const TreeData* BSTree :: retriveHelper(Node *ptr, const TreeData &obj)
{
	//if (ptr == NULL) return NULL;
	if (obj == *ptr->data)
	{
		return (ptr->data);
	}
	else if (obj < *ptr->data)
	{
		if (ptr->left == NULL)
			return NULL;
		else
			return retriveHelper(ptr->left, obj);
	}
	else
	{
		if (ptr->right == NULL)
			return NULL;
		else
			return retriveHelper(ptr->right, obj);
	}
	return NULL;
}



//}//Make Empty deletes all elements from the BST
//No preconditions
//Postcondition: removes all nodes and their data from the BST
void BSTree::makeEmpty()
{
	deleteTree(root);
}

//Helper method for the makeEmpty method needed to pass in the root Node
//Precondition: takes a Node pointer
//Postcondition: Recusively calls itself until to delete all nodes and their data in the BST
void BSTree::deleteTree(Node *&ptr)
{
	if (ptr != NULL)
	{
		if (ptr->left != NULL) deleteTree(ptr->left); // Clear left sub-tree
		if (ptr->right != NULL) deleteTree(ptr->right); // Clear right sub-tree
		delete ptr->data;
		ptr->data = NULL; //Destory TreeData obj
		//ptr->left = NULL;
		//ptr->right = NULL;
		delete ptr;    // Destroy this 
		ptr = NULL;
	}
}

//Helper method for the overloaded output operator 
//Precondition: must pass in an ostream
//Postcondition: Calls the outputHelper method passing in the root node
void BSTree :: Output()
{
	if(root != NULL)
		outputHelper(root);
	else
		cout << "No output available." << endl;
}

//Helper method for the output method 
//Precondition: must pass in a ostream and node pointer
//Postcondition: Sets the ostream to take in the data of each Node on the tree
BSTree::Node* BSTree::outputHelper(Node *root)
{
	if (root != NULL) 
	{
		//ostream &os(*root->left->data);
		outputHelper(root->left);
		root->data->display(*root->data, root->counter);
		outputHelper(root->right);
	}
	else return NULL;
	
}

//output operator overload will allow the << to recognize a BST object (can be used to print out to console)
//Post Condition: The << operator will recognize a BSTree object
ostream& operator<<(ostream &os, BSTree &obj)
{
	obj.Output();
	return os;
	
}


//isEmpty returns if the tree is empty or not
//Preconditions: none
//Postconditions: will return a bool depending on the whether or not the tree is empty
bool BSTree :: IsEmpty()
{
	if(root == NULL)
		return true;
	else return false;
}


//This is the default destructor which calls make empty to clean up the tree
//Preconditons: tree has been intialized
//Postconditions: calls deletetree method to clean up the tree's memory
BSTree::~BSTree(void)
{
	deleteTree(root);

}