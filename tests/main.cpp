#include <tst_odataentityplugin.h>
#include <tst_odataurlparsing.h>
#include <QtTest/QtTest>
int main(int argc, char** argv)
{

    qputenv("QT_QTESTLIB_RUNNING", "1");

    QList<QObject *> testClasses;

    testClasses.push_back(new ODataEntityPluginTest());
    testClasses.push_back(new ODataURLParsingTest());

   QObject * currentTest;
   int status;
   foreach(QObject * test, testClasses)
   {
	  QTest::qInit(test, argc, argv);
      status |= QTest::qRun();
      QTest::qCleanup();
   }
   return status;
}
