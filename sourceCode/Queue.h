#ifndef QUEUE_H
#define QUEUE_H


#include<string>
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
        Queue_node<T> *head,*last;
        int length,MAXSIZE;
        bool hasMaxSize;
    public:
        Queue();
        Queue(int MAXSIZE);
        void push(T data);
        T pop();
        T get();
        bool isEmpty();
        bool isFull();
        void empty();
        int getLength();
};
#endif /*  */
