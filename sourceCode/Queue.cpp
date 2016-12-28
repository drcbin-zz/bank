#include "Queue.h"

template<class T> Queue_node<T>::Queue_node(){
    this->next = NULL;
}

template<class T> Queue_node<T>::Queue_node(T data){
    this->next = NULL;
    this->data = data;
}

template<class T>Queue<T>::Queue(){
    this->head = NULL;
    this->last = NULL;
    hasMaxSize = false;
    length = 0;
}
template<class T>Queue<T>::Queue(int MAXSIZE){
    this->head = NULL;
    this->last = NULL;
    hasMaxSize = true; 
    if(MAXSIZE <= 0){
        string VALUEERROR = "VALUEERROR";
        try{
            throw VALUEERROR;
        }catch(string e){
            throw e;
        }
    }
    this->MAXSIZE = MAXSIZE;
}
template<class T>void Queue<T>::push(T data){
    if(!head){
        head = new Queue_node<T>(data);
        last = head;
        length++;
        return;
    }
    if(hasMaxSize){
        if(length >= MAXSIZE){
            string OVERFLOWERROR = "OVERFLOWERROR";
            try{
                throw OVERFLOWERROR;
            }catch(string e){
                throw e;
            }
        }
    }
    last->next = new Queue_node<T>(data);
    last = last->next;
    length++;
}
template<class T>T Queue<T>::pop(){
    if(head == last && head == NULL){
        string OVERFLOWERROR = "OVERFLOWERROR";
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    if(head == last){
        T data = head->data;
        head = last = NULL;
        length--;
        return data;
    }
    Queue_node<T> *p = head;
    T data = head->data;
    head = head->next;
    delete p;
    length--;
    return data;
}
template<class T>bool Queue<T>::isFull(){
    if(hasMaxSize){
        return length>=MAXSIZE?true:false;
    }
    return false;
}
template<class T>bool Queue<T>::isEmpty(){
    if(head == last && head == NULL){
        return true;
    }
    return false;
}
template<class T>int Queue<T>::getLength(){
    return this->length;
}
template<class T>T Queue<T>::get(){
    if(!last){
        string OVERFLOWERROR = "OVERFLOWERROR";
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    return last->data;
}
template<class T>void Queue<T>::empty(){
    while(head){
        last = head;
        head = head->next;
        delete last;
        length--;
    }
    last = NULL;
}
