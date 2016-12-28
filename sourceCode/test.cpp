#include <thread>
#include <iostream>
using namespace std;
class A{
    public:
        void dosomething(){
            cout << "Hello" << endl;
        }
        void runThread(){
            thread t(dosomething);
            t.join();
        }
};
