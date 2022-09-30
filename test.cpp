#include <tdd.h>

#include <gtest/gtest.h>

TEST( test1, test)
{
    static double a;
    static double b;
    static double c;

    result* res;

    a = 1;
    b = 0;
    c = 1;

    TDD tdd;

    res = tdd.solve( a , b , c );

    EXPECT_EQ( res->x1 , 0 );
    EXPECT_EQ( res->x2, 0 );

}

TEST( test2, test)
{
    static double a;
    static double b;
    static double c;

    result* res;

    a = 1;
    b = 0;
    c = -1;

    TDD tdd;

    res = tdd.solve( a , b , c );

    EXPECT_EQ( res->x1 , -1 );
    EXPECT_EQ( res->x2, 1 );

}

TEST( test3, test)
{
    static double a;
    static double b;
    static double c;

    result* res;

    a = 1;
    b = 2;
    c = 1;

    TDD tdd;

    res = tdd.solve( a , b , c );

    EXPECT_EQ( res->x1 , -1 );
    EXPECT_EQ( res->x2, res->x1 );

}

TEST( test5, test)
{
    static double a;
    static double b;
    static double c;

    result* res;

    a = 0;
    b = 2;
    c = 1;

    TDD tdd;

    EXPECT_ANY_THROW (  res = tdd.solve( a , b , c ); );
}
