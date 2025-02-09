#ifndef ALBUMDAO_H
#define ALBUMDAO_H


#include "album.h"

class QSqlDatabase;
class Album;

class AlbumDao
{
public:
    AlbumDao(QSqlDatabase& database);
    void init() const;
    void addAlbum(Album& album) const;
private:
    QSqlDatabase& mDatabase;
};


#endif // ALBUMDAO_H
