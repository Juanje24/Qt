#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include "albumdao.h"

class QSqlDatabase;

const QString DATABASE_FILENAME="gallery.db";

class DatabaseManager
{
public:
    const AlbumDao albumDao;
    static DatabaseManager& instance();
    ~DatabaseManager();
protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);
private:
    QSqlDatabase* mDatabase;
};


#endif // DATABASEMANAGER_H
