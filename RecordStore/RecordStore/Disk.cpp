//Shabnam Basmani
//This is an abstract class that is used for all Disk items to inherit from. It is possible to add an additional Item class if needed to handle the record
//store being able to sell items not related to Disks. All disks should have a title and year of issue. This class inherits from treedata to be used in the BST. 
#include "Disk.h"


//Default constructor has no preconditions
//Postconditions: will create a new Disk object 
Disk::Disk(void)
{
	title = " ";
	yearOfIssue = NULL;

}



//virtual destructor used to clean up possible Disk objects
//Preconditions: none
//Postconditions: cleans up any Disk objects
Disk::~Disk(void)
{
}
