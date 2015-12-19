#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#define MYSQL
#define MYSQL_DATABASE "aviation"
#define MYSQL_TABLENAME "AD"

enum Fields {
    AD_id,
    AD_indxICAO,
    AD_indxIATA,
    AD_milIndx4ru,
    AD_milIndx2ru,
    AD_city,
    AD_cityRu,
    AD_AD,
    AD_ADru,
    AD_milCSru,
    AD_milFRQ,
    AD_LAT,
    AD_LON,
    AD_VAR,
    AD_ELEV,
    AD_TZ,
    AD_milBorder,
    AD_milBorderFLs,
    AD_milEnterExitPointRu,
    AD_milTerkasInfoReceiver,
    AD_note,
    AD_noteRu,
    FieldsNumber
};

enum Columns {
    col_id,
    col_indxICAO,
    col_indxICAOru,
    col_indxIATA,
    col_indxIATAru,
    col_milIndx4ru,
    col_milIndx2ru,
    col_city,
    col_cityRu,
    col_AD,
    col_ADru,
    col_milCSru,
    col_milFRQ,
    col_LAT,
    col_LON,
    col_VAR,
    col_ELEV,
    col_TZ,
    col_milBorder,
    col_milBorderFLs,
    col_milEnterExitPointRu,
    col_milTerkasInfoReceiver,
    col_note,
    col_noteRu,
    ColumnsNumber
};


#endif // DECLARATIONS_H
