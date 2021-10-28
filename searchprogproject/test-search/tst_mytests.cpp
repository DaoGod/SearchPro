#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class myTests : public QObject
{
    Q_OBJECT

public:
    myTests();
    ~myTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

myTests::myTests()
{

}

myTests::~myTests()
{

}

void myTests::initTestCase()
{

}

void myTests::cleanupTestCase()
{

}

void myTests::test_case1()
{

}

QTEST_MAIN(myTests)

#include "tst_mytests.moc"
