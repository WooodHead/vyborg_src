#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "statistics.vw_month_ct"

enum Columns {

    month_ct_year, // 0
    month_ct_jan,  // 1
    month_ct_feb,  // 2
    month_ct_mar,  // 3
    month_ct_apr,  // 4
    month_ct_may,  // 5
    month_ct_jun,  // 6
    month_ct_jul,  // 7
    month_ct_aug,  // 8
    month_ct_sep,  // 9
    month_ct_oct,  // 10
    month_ct_nov,  // 11
    month_ct_dec,  // 12

    ColumnsNumber
};

#endif // DECLARATIONS_H
