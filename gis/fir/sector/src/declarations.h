#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "gis"
#define PGSQL_TABLENAME "fir.vw_sector"

enum Columns {
    sector_pid,
    sector_sector,
    sector_fullname,
    sector_label,
    sector_compound,
    sector_geog,
    sector_node_pid,
    ColumnsNumber
};

#endif // DECLARATIONS_H

