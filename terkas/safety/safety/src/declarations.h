#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "safety.vw_safety"

enum {
    safety_date,
    safety_shift,
    safety_location,
    safety_cause,
    safety_factor,
    safety_details,
    safety_sector_id,
    safety_acc,
    safety_classification,
    safety_type,
    safety_terkas,
    safety_alpha,
    safety_tcas1,
    safety_tcas2
};

#endif // DECLARATIONS_H

