//
// Created by jaox on 8/28/18.
//

#ifndef LISTADOBLECIRCULARENLAZADA_NODE_H
#define LISTADOBLECIRCULARENLAZADA_NODE_H



#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

};



#endif //LISTADOBLECIRCULARENLAZADA_NODE_H
