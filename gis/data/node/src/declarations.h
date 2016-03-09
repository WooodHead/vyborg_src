#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "gis"
#define PGSQL_TABLENAME "data.vw_node"

enum Columns
{
    node_pid,
    node_geog,
    node_noteru,
    ColumnsNumber
};

#endif // DECLARATIONS_H
