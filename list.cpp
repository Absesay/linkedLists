#include <iostream>
#include "list.h"
using namespace std;

void List::appendNode(double num) {
    Node *newNode;
    Node *nodePtr;

    // allocate a new node
    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    // if list empty make new node first node
    if (!head)
        head = newNode;
    else {
        nodePtr = head;
        while(nodePtr->next)
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}

void List::displayList() const
{
 Node *nodePtr; // To move through the list

 // Position nodePtr at the head of the list.
 nodePtr = head;

 // While nodePtr points to a node, traverse
 // the list.
 while (nodePtr)
 {
 // Display the value in this node.
 cout << nodePtr->value << endl;

 // Move to the next node.
 nodePtr = nodePtr->next;
 }
}

void List::insertNode(double num)
{
    Node *newNode; // A new node
    Node *nodePtr; // To traverse the list
    Node *previousNode = nullptr; // The previous node

    // Allocate a new node and store num there.
    newNode = new Node;
    newNode->value = num;

    // If there are no nodes in the list
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else // Otherwise insert after the previous node.
        {
        previousNode->next = newNode;
        newNode->next = nodePtr;
        }
    }
}

void List::deleteNode(double num) {
    Node *nodePtr;
    Node *prevNode;

    // if list empty, do nothing
    if (!head)
        return;
    // check first node
    if(head->value == num){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value != num) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr) {
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

List::~List(){
    Node *nodePtr; // To traverse the list
    Node *nextNode; // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
 }