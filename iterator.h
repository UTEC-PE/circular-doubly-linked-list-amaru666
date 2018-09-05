//
// Created by jaox on 8/28/18.
//

#ifndef LISTADOBLECIRCULARENLAZADA_ITERATOR_H
#define LISTADOBLECIRCULARENLAZADA_ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
private:
    Node<T>* current; //Esta clase es un iterador que tiene
                      //un puntero de tipo nodo
public:
    Iterator(){
        current = nullptr;
    };
    Iterator(Node<T>* node){
        current = node;
    };

    Iterator<T> operator=(Iterator<T> node){
        current = node.current;
        return *this;
    };
    bool operator!=(Iterator<T> cmp){
        return current!=cmp.current;
    };
    Iterator<T> operator++(){
        current=current->next;
        return *this;
    };
   Iterator<T> operator--(){
       current = current->prev;
       return *this;
    };
    T operator*(){
        return current->data;
    };
};


#endif //LISTADOBLECIRCULARENLAZADA_ITERATOR_H
