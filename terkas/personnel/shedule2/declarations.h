#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "shedule.vw_shedule2"

enum {
    shedule_personpid,
    shedule_activity,
    shedule_sector_pid,
    shedule_start,
    shedule_stop,
    ColumnCount
};

#endif // DECLARATIONS_H
