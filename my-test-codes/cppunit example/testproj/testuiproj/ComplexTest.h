#include "complex.h"
#include <cppunit/extensions/HelperMacros.h>

class ComplexTest : public CPPUNIT_NS::TestFixture
{
   CPPUNIT_TEST_SUITE(ComplexTest);
   CPPUNIT_TEST(testEqual);
   CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();
    void testEqual();
private:
    Complex *c_1_0, *c_1_1;
};