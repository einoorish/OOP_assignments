#ifndef FACTORY_H
#define FACTORY_H
#import "solve.h"

class Factory
{
public:
    static Solve* createSolveObject(int methodNumber);
};

#endif // FACTORY_H
