#include <QtTest>
#include <QCoreApplication>

#include "../file_search/filesearcher.h"

// add necessary includes here

class FileSearcherTest : public QObject
{
    Q_OBJECT
    FileSearcher *filesearcher;
public:
    FileSearcherTest();
    ~FileSearcherTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

FileSearcherTest::FileSearcherTest()
{

}

FileSearcherTest::~FileSearcherTest()
{

}

void FileSearcherTest::initTestCase()
{
    filesearcher = new FileSearcher();
    filesearcher->setStartDirectory("C:/Users/Lacaze/Pictures");
    filesearcher->setFilters("*.png,*.jpg");
    filesearcher->start();
}

void FileSearcherTest::cleanupTestCase()
{

}

void FileSearcherTest::test_case1()
{
    qDebug() << __FUNCTION__ << __LINE__  << filesearcher->startDirectory();
    QCOMPARE(filesearcher->results().count(), 3);
}

QTEST_MAIN(FileSearcherTest)

#include "tst_filesearchertest.moc"
