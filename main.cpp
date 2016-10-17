#include <iostream>
#include <stdlib.h>
#include "double_linked.h"
using namespace std;

int main() {
    cout << "Doubly Linked List" << endl;
    address pointer;
    List list;
    Node node;

    createEmpty(&list);

    for(int i=0;i < 2;i++){
        node.data = i;
        insertFirst(&list,node);
        node.data = node.data + 1;
        insertLast(&list,node);
    }

    node.data = 4;
    insertAfter(&list,2,node);
    node.data = 5;
    insertAfter(&list,0,node);

    node.data = 3;
    insertBefore(&list,1,node);
    node.data = 6;
    insertBefore(&list,5,node);

    deleteFirst(&list);
    deleteLast(&list);

    node.data = 6;
    deleteElm(&list,node);

    node.data = 2;
    deleteElm(&list,node);
    node.data = 1;
    deleteElm(&list,node);

    cout << "Head : " << list.head->data << endl;
    cout << "Tail : " << list.tail->data << endl;

    printForward(list);
    printBackward(list);

    return 0;
}