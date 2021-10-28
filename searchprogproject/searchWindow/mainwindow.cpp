#include "mainwindow.h"
#include "searchfolderlibrary.h"
#include "ui_mainwindow.h"
#include "../searchfolderLibrary/searchfolderlibrary.h"
#include <QDebug>
#include <QFileDialog>
#include <QString>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), search(new SearchfolderLibrary()) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
    delete search;
}


void MainWindow::on_startDirectory_textChanged(const QString &arg1) {
    qDebug() << __FUNCTION__ << __LINE__ << arg1;
    search->folderChoice(dossierChoisi);
    search->setStartDirectory(arg1);
}

void MainWindow::on_filters_textChanged(const QString &arg1) {
    search->setFilters(arg1);
}

void MainWindow::on_btnSearch_clicked() {
    search->start();
    ui->result->setText(search->results().value(20));

}

void MainWindow::on_btnCancel_clicked() {
}

void MainWindow::on_btnBrowse_clicked()
{
    dossierChoisi = QFileDialog::getExistingDirectory(this, "Titre", "C:/Users");
    ui->startDirectory->setText(dossierChoisi);
    search->folderChoice(dossierChoisi);
    //system("explorer.exe");
}

