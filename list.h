//
// Created by jaox on 8/28/18.
//

#ifndef LISTADOBLECIRCULARENLAZADA_LIST_H
#define LISTADOBLECIRCULARENLAZADA_LIST_H


#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
private:
    Node<T>* start;

public:
    List(){
        start= nullptr;
    };

    T front(){
        if(!start) {
            throw "List is empty";
        }
        return start->data;
    };
    T back(){
        if(!start) {
            throw "List is empty";
        }
        return start->prev->data;
    };
    void push_front(T value) {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        if(empty()){
            temp->prev = temp;
            temp->next = temp;
        }else {
            temp->next = start;
            temp->prev = start->prev;
            start->prev = temp;
            temp->prev->next = temp;
        }
        start = temp;
    };
    void push_back(T value) {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        if(empty()){
            temp->prev = temp;
            temp->next = temp;
            cout<<"empty! agregando valor "<<value<<endl;
            start = temp;
        }else {
            temp->next = start;
            temp->prev = start->prev;
            start->prev->next = temp;
            start->prev = temp;
            cout<<"agregando valor "<<value<<endl;
        }
    };
    void pop_front(){
        if(empty()) {
            cout<<"List is empty"<<endl;
        }else if(start == start->next){
            delete start;
            start = nullptr;
        }else{
            start->next->prev = start->prev;
            start->prev->next = start->next;
            Node<T>* temp = new Node<T>();
            temp = start;
            start = temp->next;
            delete temp;
            temp = nullptr;
        }
    };
    bool empty() {
        if(!start) return true;
        else return false;
    };
    void pop_back() {
        if(empty()) {
            cout<<"List is empty"<<endl;
        }else if(start == start->next){
            delete start;
            start = nullptr;
        }else{
            Node<T> *temp = new Node<T>();
            temp = start->prev;
            start->prev = start->prev->prev;
            start->prev->next = start;
            delete temp;
            temp = nullptr;
        }
    };
    T get(int position) {
        Iterator<T> it = begin();
        int i = 0;
        do {
            if(i == position)break;
            ++i;
            ++it;
        } while(it!=begin());
        return *it;
    };
    void concat(List<T> *other) {
        if(empty() && !other->empty()){
            start = other->start;
        } else if(!empty() && other->empty()){
            cout<<"Your list not change anything"<<endl;
        } else if(empty() && other->empty()) {
            cout<<"Lists are empty"<<endl;
        } else {
            Node<T> *last1 = new Node<T>();
            Node<T> *last2 = new Node<T>();
            last1 = start->prev;
            last2 = other->start->prev;
            start->prev = last2;
            last1->next = other->start;
            other->start->prev = start;
            last2->next = start;
            last1 = nullptr;
            last2 = nullptr;
        }
    };
    int size() {
        int size = 0;
        Iterator<T> it = begin();
        do{
            ++it;
            size++;
        } while(it != begin());
        return size;
    };
    void clear() {

    };

    ~List();
    Iterator<T> begin() {
        return Iterator<T>(start);
    };
    Iterator<T> end() {
        return Iterator<T>(start->prev);
    }
};


#endif //LISTADOBLECIRCULARENLAZADA_LIST_H
