#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "safety.vw_safety"

enum {
    safety_pid,
    safety_date,
    safety_acc,
    safety_department,
    safety_shift,
    safety_sector_id,
    safety_location,
    safety_classification,
    safety_type,
    safety_cause,
    safety_factor,
    safety_details,
    safety_terkas,
    safety_alpha,
    safety_tcas1,
    safety_tcas2
};

#endif // DECLARATIONS_H
