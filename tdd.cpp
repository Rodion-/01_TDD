#include "tdd.h"

#include <gtest/gtest.h>

result* TDD::solve(double a, double b, double c)
{

    static result res = { 0  , 0 };

    double eps=0.0001;

    double D = b*b - 4*a*c;

    //  	4   a == 0

    if( fabs( a ) < eps )   throw a;

    //  	1     x^2+1 = 0 no roots a=1 b=0 c=1 =>D=-4


    if( D < 0 ) return &res;

    //  	3
    if( fabs( D ) < eps )
    {
        res.x1 = -b/2*a;
        res.x2 = res.x1;

        return &res;
    }

    //  	2   x^2-1 = 0  has two roots
    if( D > 0 )
    {
        res.x1 = ( -b - sqrt ( D ) ) / 2*a;
        res.x2 = ( -b + sqrt ( D ) ) / 2*a;

        return &res;
    }

    //  	5
    if( isnan( D ) )
    {
        std::cout<<"D is nan"<<std::endl;
        throw -1.0;
    }

    //  	6
    if( isinf( D ) )
    {
        std::cout<<"D is inf"<<std::endl;
        throw -1.0;
    }

}

void unit_tests :: run_test(double a, double b, double c , const result& _res )
{
    res = obj->solve( a , b , c );

    if( res != nullptr )
    {
        assert( res->x1 == _res.x1 );
        assert( res->x2 == _res.x2 );
    }
}
