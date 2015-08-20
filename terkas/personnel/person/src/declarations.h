#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "personnel.vw_person"


enum Columns {
    person_surname,
    person_name,
    person_middlename,
    person_innernum,
    person_shiftnum,
    person_sectors,
    person_phonemobile,
    person_birthday
};


#endif // DECLARATIONS_H
