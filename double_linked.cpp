//
// Created by rizki on 10/15/16.
//

#include <stdlib.h>
#include "double_linked.h"
using namespace std;

address allocate(Node n){
    address p = (address) malloc(sizeof(struct Node));
    p->data = n.data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void createEmpty(List *l){
    l->head = NULL;
    l->tail = NULL;
}

bool isEmpty(List l){
    return l.head == NULL && l.tail == NULL;
}

address findElm(int data,List l){
    if (isEmpty(l))
        cout << "List kosong" << endl;
    else{
        address p = l.head;
        while (p->data!= data && p!=NULL)
            p = p->next;
        return p;
    }
}

void insertFirst(List *l, Node n){
    address p = allocate(n);
    if (isEmpty(*l)) {
        l->head = p;
        l->tail = p;
    } else{
        p->next = l->head;
        l->head->prev = p;
        l->head = p;
    }
}

void insertLast(List *l, Node n){
    address p = allocate(n);
    if(isEmpty(*l)){
        l->head = p;
        l->tail = p;
    } else{
        p->prev = l->tail;
        l->tail->next = p;
        l->tail = p;
    }
}

void insertAfter(List *l, int data, Node n){
    address prev = findElm(data,*l);
    address p = allocate(n);
    if(prev->next!=NULL){
        p->next = prev->next;
        p->prev = prev;
        prev->next = p;
        p->next->prev = p;
    } else{
        p->prev = prev;
        prev->next = p;
        l->tail = p;
    }

}

void insertBefore(List *l, int data, Node n){
    address elm = findElm(data,*l);
    address p = allocate(n);
    if(elm->prev!=NULL){
        p->next = elm;
        p->prev = elm->prev;
        elm->prev->next = p;
        elm->prev = p;
    } else{
        p->next = elm;
        elm->prev = p;
        l->head = p;
    }

}

void deleteFirst(List *l){
    if(isEmpty(*l))
        cout << "List kosong" << endl;
    else{
        address tmp = l->head;
        l->head->next->prev = NULL;
        l->head = l->head->next;
        free(tmp);
    }
}

void deleteLast(List *l){
    if(isEmpty(*l))
        cout << "List kosong" << endl;
    else{
        address tmp = l->tail;
        l->tail->prev->next = NULL;
        l->tail = l->tail->prev;
        free(tmp);
    }
}

void deleteElm(List *l,Node node){
    if(isEmpty(*l))
        cout << "List kosong" << endl;
    else{
        if(node.data == l->head->data)
            deleteFirst(l);
        else if(node.data == l->tail->data)
            deleteLast(l);
        else{
            address p = l->head;
            while (p!=NULL && p->data!=node.data)
                p = p->next;
            if(p!=NULL){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                free(p);
            }
        }
    }
}

void printForward(List l){
    if(isEmpty(l))
        cout << "List kosong" << endl;
    else{
        address p = l.head;
        while (p!=NULL){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void printBackward(List l){
    if(isEmpty(l))
        cout << "List kosong" << endl;
    else{
        address p = l.tail;
        while (p!=NULL){
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }
}