#include <cstring>
#include <tdd.h>



int main ( int argc , char** argv )
{
	{
		using namespace std;
		
        try
        {
            cout<<"TDD"<<endl;

            unit_tests u_test( make_unique<TDD>() );

            static double a;
            static double b;
            static double c;

            result res;

            //  test 1
            a = 1;
            b = 0;
            c = 1;

            res.x1 = 0;
            res.x2 = 0;

            u_test.run_test( a ,b , c , res );


            //  test 2
            a = 1;
            b = 0;
            c = -1;

            res.x1 = -1;
            res.x2 = 1;

            u_test.run_test( a ,b , c , res );

            //  test 3
            a = 1;
            b = 2;
            c = 1;

            res.x1 = -1;
            res.x2 = res.x1;

            u_test.run_test( a ,b , c , res );

            //  test 4
            a = 0;
            b = 2;
            c = 1;

            res.x1 = 0;
            res.x2 = 0;

            u_test.run_test( a ,b , c , res );

            cout<<"end"<<endl;

        }
        catch( double err )
        {
            cout<<"m error : " << err <<endl;
        }
	}
	return 0;
}
