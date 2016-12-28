#include "A.h"
#ifndef B_H
#define B_H

class B
{
private:
    A* a;

public:
    B();
    void display();
    virtual ~B();
};

#endif /* B_H */
