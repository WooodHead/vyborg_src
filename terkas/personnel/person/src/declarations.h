#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "personnel.person"


enum Columns {
    person_pid,
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
