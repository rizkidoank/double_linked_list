//
// Created by rizki on 10/15/16.
//

#ifndef DOUBLE_LINKED_LIST_DOUBLE_LINKED_H
#define DOUBLE_LINKED_LIST_DOUBLE_LINKED_H

#include <stdlib.h>
#include <iostream>
//struktur tipe data
typedef struct Node* address;
struct Node{
    int data;
    address prev;
    address next;
};
struct List{
    address head;
    address tail;
};

//alokasi memori
address allocate(Node n);
//membuat list kosong, head(l) = null
void createEmpty(List *l);
// cek status kosong atau tidak
bool isEmpty(List l);
// cari elemen pada list berdasar data masukan, mengembalikan alamat node
address findElm(int data, List l);

// INSERT
void insertFirst(List *l, Node n);
void insertLast(List *l, Node n);
void insertAfter(List *L, int data, Node n);
void insertBefore(List *l, int data, Node n);
void printForward(List l);
void printBackward(List l);

// DELETE
void deleteFirst(List *l);
void deleteLast(List *l);
void deleteElm(List *l, Node node);


#endif //DOUBLE_LINKED_LIST_DOUBLE_LINKED_H
