#ifndef MVCEXAMPLE1LIB_GLOBAL_H
#define MVCEXAMPLE1LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MVCEXAMPLE1LIB_LIBRARY)
#  define MVCEXAMPLE1LIB_EXPORT Q_DECL_EXPORT
#else
#  define MVCEXAMPLE1LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // MVCEXAMPLE1LIB_GLOBAL_H
