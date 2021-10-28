#include "searchfolderlibrary.h"

#include <QDebug>
#include <QDirIterator>
#include <QElapsedTimer>


SearchfolderLibrary::SearchfolderLibrary() : _currentProgress(0), _maxProgress(0)
{
}

int SearchfolderLibrary::maxProgress() const {
    return _maxProgress;
}

int SearchfolderLibrary::currentProgress() const {
    return _currentProgress;
}

QStringList SearchfolderLibrary::results() const {
    return m_results;
}

void SearchfolderLibrary::setFilters(const QString &filters) {
    m_filters = filters;
}

void SearchfolderLibrary::setStartDirectory(const QString &startDirectory) {
    m_startDirectory = startDirectory;
}

bool SearchfolderLibrary::isAvaiable() const {
    return _isAvaiable;
}

QString SearchfolderLibrary::folderChoice(const QString &_folder)
{
    setStartDirectory(_folder);
    return _folder;
}

void SearchfolderLibrary::start() {

    QElapsedTimer myTimer;

    myTimer.start();

    qDebug() << __FUNCTION__ << __LINE__ << "Name of top directory: " << m_startDirectory << m_filters;
    QDirIterator it(m_startDirectory, m_filters.split(","), QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        // qDebug() << it.next();
        m_results << it.next();
        _currentProgress++;
    }
    if (m_results.size() == 15)
        qDebug() << "Result size is OK";
    else
        qDebug() << "Result size is KO, size is: " << m_results.size();
    qDebug() << __FUNCTION__ << __LINE__ << m_results;
    qDebug() << __FUNCTION__ << __LINE__ << m_results.size();



}

void SearchfolderLibrary::stop() {
}
