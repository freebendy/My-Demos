#include "ComplexTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ComplexTest );


void ComplexTest::setUp()
{
    c_1_0 = new Complex(1,0);
    c_1_1 = new Complex(1,1);
}

void ComplexTest::tearDown()
{
    delete c_1_0;
    delete c_1_1;
}

void ComplexTest::testEqual()
{
    CPPUNIT_ASSERT(*c_1_0 == *c_1_0);
    CPPUNIT_ASSERT(*c_1_0 == *c_1_1);
}