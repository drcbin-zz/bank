#ifndef QUEUE_H
#define QUEUE_H
#include <mutex>
#include <string>
using namespace std;
template<class T> class Queue_node{
    public:
        T data;
        Queue_node<T> *next;
        Queue_node();
        Queue_node(T data);
};
template<class T> class Queue{
    private:
        mutex lock;
        Queue_node<T> *head,*last;
        int m_length,MAXSIZE;
        bool m_hasMaxSize;
    public:
        Queue();
        Queue(int MAXSIZE);
        void push(T data);
        T pop();
        T get();
        bool isEmpty();
        bool isFull();
        void empty();
        int length();
};

//define of Queue_node
template<class T> Queue_node<T>::Queue_node(){
    this->next = NULL;
}
template<class T> Queue_node<T>::Queue_node(T data){
    this->next = NULL;
    this->data = data;
}


// define of Queue
template<class T>Queue<T>::Queue(){
    this->head = NULL;
    this->last = NULL;
    m_hasMaxSize = false;
    m_length = 0;
}
template<class T>Queue<T>::Queue(int MAXSIZE){
    this->head = NULL;
    this->last = NULL;
    m_hasMaxSize = true; 
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
    unique_lock<mutex> locker(lock);
    if(!head){
        head = new Queue_node<T>(data);
        last = head;
        m_length++;
        return;
    }
    if(m_hasMaxSize){
        if(m_length >= MAXSIZE){
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
    m_length++;
    locker.unlock();
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

    //加锁操作
    unique_lock<mutex> locker(lock);
    if(head == last){
        T data = head->data;
        head = last = NULL;
        m_length--;
        return data;
    }
    Queue_node<T> *p = head;
    T data = head->data;
    head = head->next;
    delete p;
    m_length--;
    locker.unlock();
    return data;
}
template<class T>bool Queue<T>::isFull(){
    if(m_hasMaxSize){
        return m_length>=MAXSIZE?true:false;
    }
    return false;
}
template<class T>bool Queue<T>::isEmpty(){
    if(head == last && head == NULL){
        return true;
    }
    return false;
}
template<class T>int Queue<T>::length(){
    return this->m_length;
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
        m_length--;
    }
    last = NULL;
}
#endif /*  */
