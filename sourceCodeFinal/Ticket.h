#ifndef TICKET_H
#define TICKET_H
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Ticket
{
private:
    //private member

    tm *m_arriveTime, *m_banliTime;
    /* 到达时间*/

    string m_id;
    /* 小票的编号 */

    int m_business;
    /* 待办理的业务编号 */

    int m_waitCount;
    /* 当前前面等待的人数 */

public:
    //public menber

    bool statusCode;
    /* 小票的状态码:
     * false:还未办理,默认
     * true: 办理成功
     */

    int windowId;
    /* 小票的受理窗口,初始值为0,表示不存在的窗口id */

public:
    // public function
    Ticket(string id, int businessId, int waitCount);
    /* id:小票的编号
     * businessId:需要办理的业务的代码
     * waitCount: 取票时等待的人数
     */

    tm* arriveTime();
    /* 返回小票上的到达时间 */

    void setBanliTime(tm*);
    tm* banliTime();

    int waitCount();
    /* 返回小票上的等待时间 */

    string id();
    /* 返回小票的id编号 */

    int businessId();
    /* 返回小票上的业务编号 */
};
#endif /* TICKET_H */
