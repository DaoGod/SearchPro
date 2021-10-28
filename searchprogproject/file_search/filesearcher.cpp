#include "filesearcher.h"

#include <QDebug>
#include <QDirIterator>

#include <QCoreApplication>
#include <QTimer>

FileSearcher::FileSearcher()
{
}


int FileSearcher::maxProgress() const {
    return _maxProgress;
}



QStringList FileSearcher::results() const {
    return _results;
}

void FileSearcher::setFilters(const QString &filters) {
    _filters = filters;
}

void FileSearcher::setStartDirectory(const QString &startDirectory) {
    _startDirectory = startDirectory;
}

bool FileSearcher::isAvailable() const {
    return _isAvailable;
}

void FileSearcher::folderChoice(const QString &folder)
{
    setStartDirectory(folder);

}

FileSearcher::SEARCH_STATUS FileSearcher::searchStatus() const
{
    return _searchStatus;
}

const QElapsedTimer &FileSearcher::timeElapsed() const
{
    return *_timeElapsed;
}

const QString &FileSearcher::startDirectory() const
{
    return _startDirectory;
}

void FileSearcher::setSearchStatus(FileSearcher::SEARCH_STATUS newSearchStatus)
{
    if (_searchStatus == newSearchStatus)
        return;
    _searchStatus = newSearchStatus;
    emit statusChanged(_searchStatus);
}

void FileSearcher::start() {
    _timeElapsed = new QElapsedTimer();
    _timeElapsed->start();
    _results.clear();


    setSearchStatus(SEARCH_STATUS::STARTED);

    QDirIterator it(_startDirectory, _filters.split(","), QDir::Files, QDirIterator::Subdirectories);

    QElapsedTimer *_processEventTimer = new QElapsedTimer();
    _processEventTimer->start();

    setSearchStatus(SEARCH_STATUS::RUNNING);

    while (it.hasNext() &&  _searchStatus ==  SEARCH_STATUS::RUNNING) {
        if(_processEventTimer->elapsed() > 500){
            QCoreApplication::processEvents();
            _processEventTimer->restart();
        }
        QString result =  it.next();
         emit resultsChanged(result);
        _results.append(result);
    }
    setSearchStatus(SEARCH_STATUS::FINISHED);

    stop();
}

void FileSearcher::stop() { 
    setSearchStatus(SEARCH_STATUS::STOPPED);
    _maxProgress = 0;
    _isAvailable = true;
}

