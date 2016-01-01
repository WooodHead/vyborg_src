#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define PGSQL
#define PGSQL_DATABASE "gis"
#define PGSQL_TABLENAME "ad.vw_ad"

enum Columns {
    ad_pid,
    ad_valid,
    ad_countryindx,
    ad_country,
    ad_city,
    ad_name,
    ad_nameeng,
    ad_indx,
    ad_indxru,
    ad_type,
    ad_intl,
    ad_staff,
    ad_reglament,
    ad_elevation,
    ad_magn,
    ad_email,
    ad_web,
    ad_note,
    ad_coord,
    ColumnsNumber
};


#endif // DECLARATIONS_H
