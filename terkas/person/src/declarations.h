#ifndef DECLARATIONS_H
#define DECLARATIONS_H

//#define MYSQL
//#define MYSQL_DATABASE "personnel"
//#define MYSQL_TABLENAME "person"

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "personnel.person"


enum Columns {
    person_id,
    person_surname,
    person_name,
    person_middleName,
    person_innerID,
    person_mobilePhone
};


#endif // DECLARATIONS_H
