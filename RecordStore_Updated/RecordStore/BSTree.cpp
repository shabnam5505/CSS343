//Writen by: Shabnam Basmani, Date: 1/15/15
//This program purpose is to count the frequency of each character in a given text file
//Additional functionally is given in the .h file
//This file contains the functionally of the binary search tree which stores a pointer to the character data
#include "BSTree.h"
#include "TreeData.h"


BSTree::BSTree(void)
{
	root = NULL;
}


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

void BSTree :: updateQuanity(TreeData *obj, int numOfItems)
{
	Node *updateNode = findDups(root, *obj);
	updateNode->counter = numOfItems;
}


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


bool BSTree :: insertHelper(Node *&ptr, TreeData *obj)
{
	Node *t = findDups(ptr, *obj);
	if (t != NULL)
	{
		//t->data->setQuanity(t->data->getQuanity() + 1);
		t->counter ++;
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
			//root->data->setQuanity(root->data->getQuanity() - 1);
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




const TreeData* BSTree :: retrieve(const TreeData &obj)
{
	return retriveHelper(root, obj);
}


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



//TreeData* BSTree :: Search(const TreeData &item)
//{
//	return SearchTree(item, root);
//}
//
//
//TreeData* BSTree :: SearchTree(const TreeData &item, Node* thisNode)
//{
//	if (thisNode == NULL) return NULL;
//	else if (item == *thisNode->data)
//	{
//		return (thisNode->data);
//	}
//	else if (item < *thisNode->data)
//	{
//		return SearchTree(item, thisNode->left);
//	}
//	else
//	{
//		return SearchTree(item, thisNode->right);
//	}
//

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
	obj.Output(os);
	return os;
	
}


//Helper method for the overloaded output operator 
//Precondition: must pass in an ostream
//Postcondition: Calls the outputHelper method passing in the root node
ostream& BSTree :: Output(ostream &output)
{
	return output;
}

//Helper method for the output method 
//Precondition: must pass in a ostream and node pointer
//Postcondition: Sets the ostream to take in the data of each Node on the tree
ostream& BSTree::outputHelper(ostream &output, Node *root) 
{
	
	if (root != NULL) 
	{
		outputHelper(output, root->left);
		root->data->display(*root->data, root->counter);
		outputHelper(output, root->right);
	}
	return output;
}



bool BSTree :: IsEmpty()
{
	if(root == NULL)
		return true;
	else return false;
}



BSTree::~BSTree(void)
{
	deleteTree(root);

}