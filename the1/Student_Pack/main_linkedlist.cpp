#include <iostream>

#include "LinkedList.hpp"

int main() {
    LinkedList<int> llist;

    llist.printAllNodes();

    llist.insertAtTheFront(1);
    llist.insertAtTheFront(12);

    llist.insertAtTheEnd(2);
    llist.insertAtTheEnd(4);
    llist.insertAtTheEnd(6);

    llist.printAllNodes();

  /*  llist.removeAllNodes();  deneme */

    llist.removeNode(llist.findNode(6));

    llist.printAllNodes();

    return 0;
}