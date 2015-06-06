#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define MYSQL
#define MYSQL_DATABASE "country"
#define MYSQL_TABLENAME "country"

#define IMAGE_DIR "/usr/share/vyborg/country/"


enum Columns {
    country_id,
    country_name,
    country_nameAbridged,
    country_nameRu,
    country_nameAbridgedRu,
    country_iso3166_num,
    country_iso3166_2,
    country_iso3166_3,
    country_note,
    country_noteRu,
    country_flag
};


#endif // DECLARATIONS_H
