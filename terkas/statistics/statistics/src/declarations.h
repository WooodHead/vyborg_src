#ifndef DECLARATIONS_H
#define DECLARATIONS_H

//#define MYSQL
//#define MYSQL_DATABASE "terkas"
//#define MYSQL_TABLENAME "statistics"

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.statistics"

enum {
    statistics_id,
    statistics_date,
    statistics_innerFlights,
    statistics_foreignFlights,
    statistics_transitFlights,
    statistics_charterFlights,
    statistics_maxInDayFlights,
    statistics_foreignAC,
    statistics_note
};

#endif // DECLARATIONS_H
