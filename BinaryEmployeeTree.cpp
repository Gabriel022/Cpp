/*
 *
 * Gabriel Facco Bettinelli
 *
 * Final Programming Assignment.
 *
 * May 9, 2017
 *
*/

// Implementation file for the IntBinaryTree class
#include <iostream>
#include "BinaryEmployeeTree.h"
using namespace std;

//**************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by *
// the TreeNode pointer. This function is called recursively. *
//**************************************************************

void BinaryEmployeeTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode; // Insert the node.
    else if ((newNode->Employee.getEmployeeId()) < (nodePtr->Employee.getEmployeeId()))  // Sorting location of nodes based on EmployeeId Number.
        insert(nodePtr->left, newNode); // Search the left branch.
    else
        insert(nodePtr->right, newNode); // Search the right branch.
}

//***********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function. *
//***********************************************************

void BinaryEmployeeTree::insertNode(int employeeId, string employeeName, string employeeDivision, int employeeAge )
{
    TreeNode *newNode = nullptr; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->Employee.setEmployeeId(employeeId);
    newNode->Employee.setEmployeeName(employeeName);
    newNode->Employee.setEmployeeDivision(employeeDivision);
    newNode->Employee.setEmployeeAge(employeeAge);
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
//***************************************************

void BinaryEmployeeTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//*******************************************************
// searchNode search for the especific employee ID
// and if it founds returns 0 and output the info.
// Otherwise the functions returns -1.
//*******************************************************

int BinaryEmployeeTree::searchNode(int a)
{
    TreeNode *nodePtr = root;

    while (nodePtr) // Searching left tree brand.
    {
        if (nodePtr->Employee.getEmployeeId() == a)
        {
            cout << endl << "Employee Found!" << endl;
            cout << nodePtr->Employee.getEmployeeId()<<" " << nodePtr->Employee.getEmployeeName()<<", ";
            cout << nodePtr->Employee.getEmployeeDivision()<<","<<nodePtr->Employee.getEmployeeAge() << endl << endl;
            return 0;
        }

        else
        {
            nodePtr = nodePtr->left;
        }
    }
    nodePtr = root;
    while(nodePtr) // Searching right tree brand.
    {
        if (nodePtr->Employee.getEmployeeId() == a)
        {
            cout << endl << "Employee Found!" << endl;
            cout << nodePtr->Employee.getEmployeeId()<<" " << nodePtr->Employee.getEmployeeName()<<", ";
            cout << nodePtr->Employee.getEmployeeDivision()<<","<<nodePtr->Employee.getEmployeeAge() << endl << endl;
            return 0;
        }

        else
        {
            nodePtr = nodePtr->right;
        }
    }
    return -1;
}

//***********************************************
// remove calls deleteNode to delete the *
// node whose value member is the same as num. *
//***********************************************

void BinaryEmployeeTree::remove(int num)
{
    deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value *
// member is the same as num. *
//********************************************

void BinaryEmployeeTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->Employee.getEmployeeId())
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->Employee.getEmployeeId())
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}



//***********************************************************
// makeDeletion takes a reference to a pointer to the node *
// that is to be deleted. The node is removed and the *
// branches of the tree below the node are reattached. *
//***********************************************************

void BinaryEmployeeTree::makeDeletion(TreeNode *&nodePtr)
{
    // Define a temporary pointer to use in reattaching
    // the left subtree.
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach the left child.
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child.
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        // Move one node to the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

//*************************************************************
// The displayInOrder member function displays the values *
// in the subtree pointed to by nodePtr, via inorder traversal.
// If list is empty is going to output List Empty. *
//*************************************************************

void BinaryEmployeeTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->Employee.getEmployeeId()<<" " << nodePtr->Employee.getEmployeeName()<<", ";
        cout << nodePtr->Employee.getEmployeeDivision()<<","<<nodePtr->Employee.getEmployeeAge() << endl;
        displayInOrder(nodePtr->right);
    }
}

//*************************************************************
// The displayPreOrder member function displays the values *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//*************************************************************

void BinaryEmployeeTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->Employee.getEmployeeId() << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

//*************************************************************
// The displayPostOrder member function displays the values *
// in the subtree pointed to by nodePtr, via postorder traversal. *
//*************************************************************

void BinaryEmployeeTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
//        cout << nodePtr->value << endl;
    }
}

/* Function to get the count of leaf nodes in a binary tree*/
int BinaryEmployeeTree::getLeafCount(TreeNode *nodePtr) const
{
    if(nodePtr == NULL)
        return 0;
    if(nodePtr->left == NULL && nodePtr->right==NULL)
        return 1;
    else
        return getLeafCount(nodePtr->left)+ getLeafCount(nodePtr->right);
}



/* Compute the "maxDepth" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int BinaryEmployeeTree::maxHeight(TreeNode *nodePtr) const
{
    if (nodePtr==NULL)
       return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxHeight(nodePtr->left);
        int rDepth = maxHeight(nodePtr->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth+1);
        else
            return(rDepth+1);
   }
}



/* Get width of a given level */
int BinaryEmployeeTree::getWidth(TreeNode *nodePtr, int level) const
{

    if(nodePtr == NULL)
        return 0;

    if(level == 1)
        return 1;

    else if (level > 1)
        return getWidth(nodePtr->left, level-1) + getWidth(nodePtr->right, level-1);
    else
        return 0;
}

/* Function to get the maximum width of a binary tree*/
int BinaryEmployeeTree::getMaxWidth(TreeNode *nodePtr) const
{
    int maxWidth = 0;
    int width;
    int h = TreeHeight();
    int i;

    /* Get width of each level and compare
     the width with maximum width so far */
    for(i=1; i<=h; i++)
    {
        width = getWidth(root, i);
        if(width > maxWidth)
        maxWidth = width;
    }
    return maxWidth;
}

//Function Searchs for the employees with less than 25 years, and then print their info.
void BinaryEmployeeTree::searchYoungs(TreeNode *nodePtr) const
{

  if (nodePtr)
    {
        searchYoungs(nodePtr->left);
        if(nodePtr->Employee.getEmployeeAge() < 25)
        {
            cout << nodePtr->Employee.getEmployeeId()<<" " << nodePtr->Employee.getEmployeeName()<<", ";
            cout << nodePtr->Employee.getEmployeeDivision()<<","<<nodePtr->Employee.getEmployeeAge() << endl;
        }
        searchYoungs(nodePtr->right);
    }
    return;
}

// Function that validates Employee Id. If Id is already in use returns -1.
int BinaryEmployeeTree::validateEmployeeID(TreeNode *nodePtr, int &id ) const
{
    nodePtr = root;

    while(nodePtr) // Searching left brand.
    {
        if(nodePtr->Employee.getEmployeeId() == id)
        {
             return -1;
        }
        else
        {
            nodePtr = nodePtr->left;
        }
    }
    nodePtr = root;
    while(nodePtr) // Searching right brand.
    {
        if(nodePtr->Employee.getEmployeeId() == id)
        {
             return -1;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }
    return 0;

}
