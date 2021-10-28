#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "../file_search/filesearcher.h"

#include <QDebug>
#include <QFileDialog>
#include <QScrollBar>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), search(new FileSearcher()) {
    ui->setupUi(this);
    QObject::connect(search, &FileSearcher::resultsChanged, this, &MainWindow::onSearchResultChanged);
    QObject::connect(search, &FileSearcher::statusChanged, this, &MainWindow::onStatusChanged);
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();

}

MainWindow::~MainWindow() {
    delete ui;
    delete search;
}


void MainWindow::on_startDirectory_textChanged(const QString &arg1) {
    search->setStartDirectory(arg1);
}

void MainWindow::on_filters_textChanged(const QString &arg1) {
    search->setFilters(arg1);
}

void MainWindow::on_btnSearch_clicked() {
    ui->progressBar->show();
    ui->result->clear();
    this->setSearchDisabled(true);
    search->start();

}

void MainWindow::on_btnCancel_clicked() {
    search->stop();
    ui->progressBar->hide();
    this->setSearchDisabled(false);
}

void MainWindow::onSearchResultChanged(QString res)
{
    ui->result->setText(res + "\n"+ ui->result->toPlainText() );
    ui->lblTotalResult->setText(
        "Found files : " + QString::number(search->results().count()) + "\n" +
        "Elapsed Time : " + QString::number(search->timeElapsed().elapsed())
    );
}

void MainWindow::onStatusChanged(FileSearcher::SEARCH_STATUS status)
{
    if(status == FileSearcher::STOPPED){
         ui->progressBar->hide();
    }


}

void MainWindow::setSearchDisabled(bool disabled)
{
    ui->btnSearch->setDisabled(disabled);
    ui->btnCancel->setDisabled(!disabled);
}

void MainWindow::on_btnBrowse_clicked()
{

    lastFolderChoice = QFileDialog::getExistingDirectory(this, "Titre", "C:/Users");
    ui->startDirectory->setText(lastFolderChoice);
    search->folderChoice(lastFolderChoice);
}

