/*
 *
 * Gabriel Facco Bettinelli
 *
 * Final Programming Assignment.
 *
 * May 9, 2017
 *
*/

// Specification file for the BinaryEmployeeTree class
#ifndef BINARYEMPLOYEETREE_H
#define BINARYEMPLOYEETREE_H

#include "EmployeeInfo.h"

class BinaryEmployeeTree
{
private:
    struct TreeNode
    {
        EmployeeInfo Employee; // Instance of the EmployeeInfo Class.
        TreeNode *left; // Pointer to left child node
        TreeNode *right; // Pointer to right child node
    };

    TreeNode *root; // Pointer to the root node

    // Private member functions

    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void searchYoungs(TreeNode *) const;  // Function that search for young employees.
    int validateEmployeeID(TreeNode *, int &id) const; // Function that validates Employee Id.
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    int getLeafCount(TreeNode *) const;
    int maxHeight(TreeNode *nodePtr) const;
    int getMaxWidth(TreeNode *nodePtr) const;
    int getWidth(TreeNode *nodePtr, int level) const;

public:
    // Constructor
    BinaryEmployeeTree()
        { root = nullptr; }

    // Destructor
    ~BinaryEmployeeTree()
        { destroySubTree(root); }

    // Binary tree operations
    void insertNode(int employeeId, string employeeName, string employeeDivision, int employeeAge);
    int searchNode(int);

    void findYoungEmployees() const
        { searchYoungs(root);}

    int validatingEmployeeID(int b) const
        { return validateEmployeeID(root,b); }

    void remove(int);
    void displayInOrder() const
        { displayInOrder(root); }

    void displayPreOrder() const
        { displayPreOrder(root); }

    void displayPostOrder() const
        { displayPostOrder(root); }

    // Function that returns numbers of leaf nodes.
    int countingLeafs() const
        { return getLeafCount(root); }

    //Function that returns Tree Height.
    int TreeHeight() const
        {  return maxHeight(root); }
    //Function that returns max Width of tree.
    int TreeMaxWidth() const
        {  return getMaxWidth(root); }
};
#endif

