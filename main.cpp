#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    // Define a List object.
    List list;

    // Append some values to the list.
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);

    list.insertNode(10.5);

    // Display the list.
    cout << "Here are the initial values:\n";
    list.displayList();
    cout << endl;

    // Delete the middle node.
    cout << "Now deleting the node in the middle.\n";
    list.deleteNode(7.9);

    // Display the list.
    cout << "Here are the nodes left.\n";
    list.displayList();
    cout << endl;
    return 0;

}