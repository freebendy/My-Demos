#pragma once

#include <cppunit/extensions/HelperMacros.h>

#include "src/SQLDataAccess.h"

using namespace pctor;

class DataAccessTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(DataAccessTest);
        CPPUNIT_TEST(testDropDatabase);
        CPPUNIT_TEST(testCreateDatabase);
        CPPUNIT_TEST(testCreateTable);
        CPPUNIT_TEST(testAdd);
        //CPPUNIT_TEST(testUpdate);
        CPPUNIT_TEST(testQuery);
        //CPPUNIT_TEST(testDelete);
		//CPPUNIT_TEST(testAddData);
		//CPPUNIT_TEST(testEscape);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void testMethod();
    void testDropDatabase();
    void testCreateDatabase();
    void testChangeDatabase();
    void testCreateTable();
    void testCreateIndex();
    void testAdd();
    void testDelete();
    void testUpdate();    
    void testQuery();
	void testAddData();
	void testEscape();

private:
    SQLDataAccess *m_DataAccess;
};