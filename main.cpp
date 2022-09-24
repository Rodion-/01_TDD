#include <iostream>
#include <cstring>
#include <math.h>
#include <assert.h>

typedef struct result
{
    double x1;
    double x2;
} result;

class TDD
{
    public:

    TDD(){}
    ~TDD(){}

    result* solve(double a, double b, double c);
};

result* TDD::solve(double a, double b, double c)
{
    try
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
    catch( double err )
    {
        std::cout<<"err : " << err << std::endl;
    }
}

TDD tdd;

int main ( int argc , char** argv )
{
	{
		using namespace std;
		
        try
        {
            cout<<"TDD"<<endl;

            static double a;
            static double b;
            static double c;

            result* res = nullptr;

            //  test 1
            a = 1;
            b = 0;
            c = 1;

            {

                res = tdd.solve( a , b, c );

                if( res != nullptr )
                {
                    assert( res->x1 == 0 );
                    assert( res->x2 == 0 );
                }
            }

            //  test 2
            a = 1;
            b = 0;
            c = -1;

            {

                res = tdd.solve( a , b, c );

                if( res != nullptr )
                {
                    assert( res->x1 == -1 );
                    assert( res->x2 ==  1 );
                }
            }

            a = 1;
            b = 2;
            c = 1;

            //  test 3
            {

                res = tdd.solve( a , b, c );

                if( res != nullptr )
                {
                    assert( res->x1 == -1 );
                    assert( res->x2 == res->x1 );
                }
            }

            //  test 4
            a = 0;
            b = 2;
            c = 1;

            {

                res = tdd.solve( a , b, c );

                if( res != nullptr )
                {
                    assert( res->x1 == 0 );
                    assert( res->x2 == 0 );
                }

            }


            cout<<"end"<<endl;

        }
        catch( double err )
        {
            cout<<"m error : " << err <<endl;
        }
	}
	return 0;
}
