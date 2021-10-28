#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../searchfolderLibrary/searchfolderlibrary.h"
#include <QMainWindow>

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
    void on_filters_textChanged(const QString &arg1);

    void on_btnSearch_clicked();

    void on_btnCancel_clicked();

    void on_startDirectory_textChanged(const QString &arg1);

    void on_btnBrowse_clicked();

private:
    Ui::MainWindow *ui;
    SearchfolderLibrary *  search;
    QString dossierChoisi;
};
#endif // MAINWINDOW_H
