#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_quota"

enum {
    quota_abbr,
    quota_function,
    quota_val,
    quota_valmax
};

#endif // DECLARATIONS_H
