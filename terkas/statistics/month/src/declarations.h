#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <QObject>
#include <QList>
#include <QStringList>

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_month"

enum {
    statistics_date,
    statistics_internal,
    statistics_external,
    statistics_transit,
    statistics_charter,
    statistics_maxday,
    statistics_foreigner,
    statistics_note
};

//               trUtf8("date"));
//               trUtf8("internal"));
//               trUtf8("external"));
//               , trUtf8("transit"));
//               , trUtf8("charter"));
//               , trUtf8("maxday"));
//               , trUtf8("foreigner"));

#endif // DECLARATIONS_H
