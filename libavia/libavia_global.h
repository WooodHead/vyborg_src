#ifndef LIBAVIA_GLOBAL_H
#define LIBAVIA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBAVIA_LIBRARY)
#  define LIBAVIASHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBAVIASHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBAVIA_GLOBAL_H
