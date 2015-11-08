#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "terkas"
#define PGSQL_TABLENAME "person.vw_person"


enum Columns {
    person_pid,
    person_surname,
    person_name,
    person_middlename,
    person_tabnum,
    person_birthday,
    person_position,
    person_division,
    person_subdivision,
    person_shift,
    person_class,
    person_icaolevel,
    person_icaoleveldate,
    person_licencenum,
    person_licencevalid,
    person_mobilephone,
    person_stazh,
    person_postup,
    person_medicalvalid,
    person_sectorgroup,
    person_sectoradmittance,
    person_positionadmittance,
    person_kpkrp,
    person_kpksd,
    person_kpkdi,
    person_kpkfact,
    person_kpkplan,
    person_kpkompfact,
    person_kpkompplan,
    person_vyssh,
    person_srednee,
    person_kursy,
    person_obrazov,
    person_gosnagrady,
    person_otraslnagrady,
    person_fgupnagrady,
    person_filialnagrady,
    ColumnNumber
};


#endif // DECLARATIONS_H
