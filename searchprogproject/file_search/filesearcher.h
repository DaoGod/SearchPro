#ifndef FILESEARCHER_H
#define FILESEARCHER_H

#include <QString>
#include <QStringList>
#include <QObject>
#include <QElapsedTimer>


#include "file_search_global.h"

class FILE_SEARCH_EXPORT FileSearcher : public QObject
{
    Q_OBJECT
  public:
    enum SEARCH_STATUS {STOPPED, STARTED,  RUNNING, FINISHED };
  private :
    QString             _startDirectory;
    QString             _filters;
    QStringList         _results;
    QElapsedTimer       *_timeElapsed;

    int                 _maxProgress;

    bool                _isAvailable;
    SEARCH_STATUS        _searchStatus;

    void setSearchStatus(SEARCH_STATUS newSearchStatus);
  public:
    FileSearcher();


    void        start();
    void        stop();
    int         maxProgress() const;
    QStringList results() const;
    void        setFilters(const QString &filters);
    void        setStartDirectory(const QString &startDirectory);

    bool        isAvailable() const;
    void        folderChoice(const QString &folder);

    SEARCH_STATUS searchStatus() const;


    const QElapsedTimer &timeElapsed() const;

    const QString &startDirectory() const;

signals:
    void resultsChanged(QString newResult);
    void statusChanged(enum SEARCH_STATUS status);



};

#endif // FILESEARCHER_H
