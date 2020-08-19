#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

class List {
    private:
        struct Node {
            double value;
            Node *next;
        };

        Node *head;

    public:
        // constructor
        List() {
            head = nullptr;
        }

        // destructor
        ~List();

        // list operations
        void appendNode(double);
        void insertNode(double);
        void deleteNode(double);
        void displayList() const;
};

#endif