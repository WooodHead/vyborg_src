#ifndef CONVERT_H
#define CONVERT_H

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE


/*
 *   Translate latin into russian
 */
QString lat2rus(QString latStr);

/*
 *   Convert raw coord to readable
 */
QString coordRaw2readable(QString coordRaw);

#endif // CONVERT_H
