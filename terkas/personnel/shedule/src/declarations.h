#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "personnel.vw_shedule"

enum {
    shedule_activity,
    shedule_name,
    shedule_middlename,
    shedule_surname,
    shedule_sector_pid,
    shedule_start,
    shedule_stop,
    ColumnCount
};

#endif // DECLARATIONS_H
