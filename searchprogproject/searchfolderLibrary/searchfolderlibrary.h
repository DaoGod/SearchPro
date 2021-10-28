#ifndef SEARCHFOLDERLIBRARY_H
#define SEARCHFOLDERLIBRARY_H


#include <QString>
#include <QStringList>

#include "searchfolderLibrary_global.h"

class SEARCHFOLDERLIBRARY_EXPORT SearchfolderLibrary
{
private:
        QString     m_startDirectory;
        QString     m_filters;
        QStringList m_results;
        int         _currentProgress;
        int         _maxProgress;
        bool        _isAvaiable;


      public:
        SearchfolderLibrary();
        void        start();
        void        stop();
        int         maxProgress() const;
        int         currentProgress() const;
        QStringList results() const;
        void        setFilters(const QString &filters);
        void        setStartDirectory(const QString &startDirectory);
        bool        isAvaiable() const;
        QString     folderChoice(const QString &_folder);
};

#endif // SEARCHFOLDERLIBRARY_H
