#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_month"

enum Columns {
    month_pid,
    month_department,
    month_monthyear,
    month_vol,
    ColumnsNumber
};

#endif // DECLARATIONS_H
