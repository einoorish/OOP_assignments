#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::test_Kramer(){
    double **temp_data = new double *[4];
    for(int i = 0; i < 4; ++i)
       temp_data[i] = new double [4];
    temp_data[0][0]=1;
    temp_data[0][1]=3;
    temp_data[0][2]=3;
    temp_data[0][3]=4;
    temp_data[1][0]=0;
    temp_data[1][1]=-1;
    temp_data[1][2]=7;
    temp_data[1][3]=8;
    temp_data[2][0]=0;
    temp_data[2][1]=1;
    temp_data[2][2]=11;
    temp_data[2][3]=12;
    temp_data[3][0]=0;
    temp_data[3][1]=1;
    temp_data[3][2]=15;
    temp_data[3][3]=16;

    double* freevars=new double [4];
    freevars[0]=1;
    freevars[1]=2;
    freevars[2]=3;
    freevars[3]=0;
    Matrix matrix(temp_data,freevars,4,4);

    double *res = new double [4];
    res[0] = -12;
    res[1] = 2;
    res[2] = -10;
    res[3] = 9.25;

    QCOMPARE(Factory::createSolveObject(Strategy::Strategies::Kramer)->startMethod(matrix), res);

}

void Test::test_Jacobi(){
    double **temp_data = new double *[4];
    for(int i = 0; i < 4; ++i)
        temp_data[i] = new double [4];
    temp_data[0][0]=-5;
    temp_data[0][1]=1;
    temp_data[0][2]=1;
    temp_data[0][3]=1;
    temp_data[1][0]=1;
    temp_data[1][1]=5;
    temp_data[1][2]=1;
    temp_data[1][3]=1;
    temp_data[2][0]=1;
    temp_data[2][1]=1;
    temp_data[2][2]=5;
    temp_data[2][3]=1;
    temp_data[3][0]=1;
    temp_data[3][1]=1;
    temp_data[3][2]=1;
    temp_data[3][3]=-5;

    double* freevars=new double [4];
    freevars[0]=4;
    freevars[1]=18;
    freevars[2]=22;
    freevars[3]=-14;
    Matrix matrix(temp_data,freevars,4,4);

    double *res = new double [4];
    res[0] = 1;
    res[1] = 2;
    res[2] = 3;
    res[3] = 4;

    QCOMPARE(Factory::createSolveObject(Strategy::Strategies::Jacobi)->startMethod(matrix), res);
}

void Test::test_Gauss(){
    double **temp_data = new double *[4];
    for(int i = 0; i < 4; ++i)
        temp_data[i] = new double [4];
    temp_data[0][0]=1;
    temp_data[0][1]=-1;
    temp_data[0][2]=3;
    temp_data[0][3]=1;
    temp_data[1][0]=4;
    temp_data[1][1]=-1;
    temp_data[1][2]=5;
    temp_data[1][3]=4;
    temp_data[2][0]=2;
    temp_data[2][1]=-2;
    temp_data[2][2]=4;
    temp_data[2][3]=1;
    temp_data[3][0]=1;
    temp_data[3][1]=-4;
    temp_data[3][2]=5;
    temp_data[3][3]=-1;

    double* freevars=new double [4];
    freevars[0]=5;
    freevars[1]=4;
    freevars[2]=6;
    freevars[3]=3;
    Matrix matrix(temp_data,freevars,4,4);

    double *res = new double [4];
    res[0] = 9;
    res[1] = 18;
    res[2] = 10;
    res[3] = -16;

    QCOMPARE(Factory::createSolveObject(Strategy::Strategies::Gauss)->startMethod(matrix), res);
}
