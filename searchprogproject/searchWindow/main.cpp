#include "mainwindow.h"

#include "../searchfolderLibrary/searchfolderlibrary.h"

#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainWindow   w;
        w.show();

        SearchfolderLibrary finder;
        // Good Case :


       /* finder.setStartDirectory("C:/Users/33762/Pictures/logo");
        finder.setFilters("*.jpg,*.png");


        QElapsedTimer myTimer;

        myTimer.start();

        finder.start();


        if (finder.results().size() == 15)
            qDebug() << "Result size is OK";
        else
            qDebug() << "Result size is KO, size is: " << finder.results().size();
        qDebug() << finder.results();

        int current = finder.currentProgress();
        int max     = finder.maxProgress();
        qDebug() << current;
        qDebug() << max;
        finder.stop();
        qDebug() << "Elapsed Time :" << myTimer.elapsed();*/

        // Bad Case :
        /*finder.setStartDirectory("C:/Toto");
        finder.setFilters(",,,");*/
    return a.exec();
}
