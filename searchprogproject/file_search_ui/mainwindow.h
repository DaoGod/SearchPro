#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../file_search/filesearcher.h"

#include <QMainWindow>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

 private slots:
   void on_startDirectory_textChanged(const QString &arg1);

   void on_filters_textChanged(const QString &arg1);

   void on_btnSearch_clicked();

   void on_btnCancel_clicked();

   void on_btnBrowse_clicked();

   void onSearchResultChanged(QString res);

   void onStatusChanged(enum FileSearcher::SEARCH_STATUS status);

private:
   Ui::MainWindow *ui;
   FileSearcher *  search;
   QString lastFolderChoice;

   void setSearchDisabled(bool disabled);

};
#endif // MAINWINDOW_H
