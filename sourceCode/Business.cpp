
#ifndef BUSINESS_H
#define BUSINESS_H

#include<thread>
#include <condition_variable>
#include "Queue.h"
#include "Ticket.h"
#include "Customer.h"

//唤醒小票回收线程的条件, 唤醒窗口办理的条件, 唤醒打票机器工作的条件
std::condition_variable recCond, lineCond, personCond;

//一把操作小票回收队列的锁,一把办理队伍的锁, 一把等待取票人队列的锁
std::mutex recQueueLock, lineQueueLock, personQueueLock;

// 三个队列: 等待取票队列, 排队办理业务队列, 废旧小票待回收队列
Queue<Ticket*> *oldTicQueue = new Queue<Ticket*>;
Queue<Customer*> *lineQueue = new Queue<Customer*>, *personQueue = new Queue<Customer*>;

#endif /*  */
