#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_month"

enum Columns {

    month_pid,            // 0
    month_monthyear,      // 1
    month_department_pid, // 2
    month_department,     // 3
    month_vol,            // 4

    ColumnsNumber
};

#endif // DECLARATIONS_H
