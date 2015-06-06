#ifndef DECLARATIONS_H
#define DECLARATIONS_H

//#define SQLITE
//#define SQLITE_FILE "safety.sql"

#define MYSQL
#define MYSQL_DATABASE "terkas"
#define MYSQL_TABLENAME "safety"

enum {
    safety_id,
    safety_date,
    safety_ACC_id,
    safety_department_id,
    safety_shiftNum,
    safety_sector_id,
    safety_area,
    safety_safetyClassification_id,
    safety_safetyType_id,
    safety_sposTerkas_id,
    safety_sposAlpha_id,
    safety_TCAS1_id,
    safety_TCAS2_id,
    safety_cause,
    safety_factor,
    safety_details
};

#endif // DECLARATIONS_H
