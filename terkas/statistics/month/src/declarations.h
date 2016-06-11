#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_month"

enum Columns {
    month_pid,        // 0
    month_monthyear,  // 1
    month_department, // 2
    month_vol,        // 3
    ColumnsNumber
};

#endif // DECLARATIONS_H
