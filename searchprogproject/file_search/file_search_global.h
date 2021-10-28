#ifndef FILE_SEARCH_GLOBAL_H
#define FILE_SEARCH_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FILE_SEARCH_LIBRARY)
#  define FILE_SEARCH_EXPORT Q_DECL_EXPORT
#else
#  define FILE_SEARCH_EXPORT Q_DECL_IMPORT
#endif

#endif // FILE_SEARCH_GLOBAL_H
