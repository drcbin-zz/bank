#include "TicMachine.h"
TicMachine::TicMachine(Queue<Ticket*>* oldTicQueue, condition_variable* recCond){
    //初始化开始营业时间,开始营业
    time_t now = time(0);
    this->m_isRunning = true;
    this->m_oldTicQueue = oldTicQueue;
    this->m_recCond = recCond;
    m_startTime = localtime(&now);
    m_startTime->tm_year += 1900;
    m_startTime->tm_mon += 1;

    m_nowTime = m_startTime;

    //设置结束营业时间
    m_closingTime = new tm(*m_startTime);
    m_closingTime->tm_min += 8;    //营业8分钟

    //初始化总服务人数
    this->m_serviceNum = 0;
    for(int i = 0; i < 8; i++){m_eachServiceNum[i] = 0;}

    //初始化排队人数
    this->m_waitNum = 0;
    for(int i = 0; i < 8; i++){m_eachWaitNum[i] = 0;}

    //初始化最后一次回收id:m_lastRecoverId
    // m_lastRecoverId = 0;


    //初始化id前置编号
    m_preID = "D" + to_string(m_startTime->tm_year) + to_string(m_startTime->tm_mon) + to_string(m_startTime->tm_mday) + "C";
}

Ticket* TicMachine::createTicket(int b){
    unique_lock<mutex> locker(m_countLock);
    // countCond.wait(locker);
    m_serviceNum++;
    m_eachServiceNum[b]++;
    m_waitNum++;
    m_eachWaitNum[b]++;
    locker.unlock();
    return new Ticket(m_preID + to_string(m_serviceNum), b, m_waitNum);
}


//获取各种统计数据
int TicMachine::serviceNum(){
    return m_serviceNum;
}
int TicMachine::serviceNum(int b){
    return m_eachServiceNum[b];
}
int TicMachine::waitCount(){
    return m_waitNum;
}
int TicMachine::waitCount(int b){
    return m_eachWaitNum[b];
}


//是否还是营业时间
bool TicMachine::isStillWork(){
    return m_isRunning;
}

void TicMachine::checkIsRunningOrNot(){
    time_t now;
    while(true){
        now = time(0);
        m_nowTime = localtime(&now);
        int now1 = m_nowTime->tm_hour*3600 + m_nowTime->tm_min*60 +  m_nowTime->tm_sec;
        int closeTime = m_closingTime->tm_hour*3600 + m_closingTime->tm_min*60 +  m_closingTime->tm_sec;
        if(now1 > closeTime){
            this->m_isRunning = false;
            break;
        }
        this_thread::sleep_for(chrono::seconds(1));
        cout << m_nowTime->tm_min  << ":" << m_nowTime->tm_sec << endl;
    }
}

//回收小票
void TicMachine::recover(ProcessWindow*& processWindow){
    string s;

    while(true){
        //加锁修改数据操作
        unique_lock<mutex> locker(m_countLock);
        m_recCond->wait(locker);
        if(!m_oldTicQueue->isEmpty()){
            Ticket* oldTic = m_oldTicQueue->pop();
            s = "正在回收号小票.";
//            fun(s);
            processWindow->processWindowAppend(s);
            this->m_waitNum--;
            this->m_eachWaitNum[oldTic->businessId()]--;
            writeToLog(oldTic);
            s = "回收完成,已将小票信息保存到文件.";
            processWindow->processWindowAppend(s);
        }
        locker.unlock();
    }
}

void TicMachine::writeToLog(Ticket *tic){
        ofstream f("/home/chenbin/log.txt", ios::app);
        if(!f){
            cout << "open error" << endl;
            return ;
        }
        f << "*********************************************" << endl;

        //id
        f << "*ID: " << tic->id()<<"                              *" << endl;

        //BusinessId
        f << "*BusinessId: " << tic->businessId()<<"                              *" << endl;


        //ArriveTime
        f << "*ArriveTime: " << tic->arriveTime()->tm_hour << ":"<<
              tic->arriveTime()->tm_min << ":"
           << tic->arriveTime()->tm_sec <<"                        *" << endl;


         //WaitNum
        f << "*WaitNum: " << tic->waitCount()<<"                                 *" << endl;


         //status
         string s;
         if(tic->statusCode == 0){
            s = "Fail";
         }
         if(tic->statusCode == 1){
             s = "Success";
         }
         f << "*Status: " << s <<"                            *" << endl;

          //dealwindowID
         f << "*DealWindowID: " << tic->windowId<<"                            *" << endl;


         //dealTime
         f << "*DealTime: " << tic->banliTime()->tm_hour << ":"
             <<  tic->banliTime()->tm_min << ":" <<
               tic->banliTime()->tm_sec << "                          *" << endl;

        f << "*********************************************" << endl << endl << endl << endl << endl;
        f.close();
}
