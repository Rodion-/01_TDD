#include <iostream>
#include <cstring>
#include <math.h>

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

        //  4   a == 0

        if( fabs( a ) < eps )   throw a;

        //  1     x^2+1 = 0 no roots a=1 b=0 c=1 =>D=-4
        if( D < 0 ) return &res;

        //  3
        if( fabs( D ) < eps )
        {
            res.x1 = -b/2*a;
            res.x2 = 0;

            return &res;
        }

        //  2   x^2-1 = 0  has two roots
        if( D > 0 )
        {
            res.x1 = ( -b - sqrt ( D ) ) / 2*a;
            res.x2 = ( -b + sqrt ( D ) ) / 2*a;

            return &res;
        }


        //  5
        if( isnan( D ) )
        {
            std::cout<<"D is nan"<<std::endl;
            throw -1.0;
        }

        //  6
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

            result* res = nullptr;

            res = tdd.solve( 1 , 0 , 1 );

            if( res != nullptr )
            cout<<"x1= "<<res->x1<<" x2= "<<res->x2<<endl;

            res = tdd.solve( 1 , -2 , -1 );

            if( res != nullptr )
            cout<<"x1= "<<res->x1<<" x2= "<<res->x2<<endl;

            res = tdd.solve( 1 , 2 , 1 );

            if( res != nullptr )
            cout<<"x1= "<<res->x1<<" x2= "<<res->x2<<endl;

            res = tdd.solve( 0 , 2 , 1 );

            if( res != nullptr )
            cout<<"x1= "<<res->x1<<" x2= "<<res->x2<<endl;

            res = tdd.solve( 1 , 0.002 , 0.0000001 );

            if( res != nullptr )
            cout<<"x1= "<<res->x1<<" x2= "<<res->x2<<endl;

            cout<<"end"<<endl;

        }
        catch( double err )
        {
            cout<<"error : " << err <<endl;
        }
	}

	return 0;
}
