#ifndef DECLARATIONS_H
#define DECLARATIONS_H

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

#endif // DECLARATIONS_H
