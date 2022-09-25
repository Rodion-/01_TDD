#ifndef TDD_H
#define TDD_H

#include <iostream>
#include <math.h>
#include <assert.h>
#include <memory>

typedef struct result
{
    double x1;
    double x2;
} result;

class ITDD
{
    public:
    virtual result* solve(double a, double b, double c) = 0;
};

class TDD : public ITDD
{
    public:

    TDD(){}
    ~TDD(){}

    result* solve(double a, double b, double c);
};

class unit_tests
{
    std::unique_ptr<ITDD> obj;
    result* res;

    public:

    unit_tests( std::unique_ptr<ITDD> _obj ):obj( std::move( _obj ) ){}
    ~unit_tests(){}


    void run_test(double a, double b, double c , const result& _res );

};


#endif // TDD_H
