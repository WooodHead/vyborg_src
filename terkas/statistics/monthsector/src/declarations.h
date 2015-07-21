#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_monthsector"

enum {
    monthsector_date,
    monthsector_sector,
    monthsector_vol
};

#endif // DECLARATIONS_H
