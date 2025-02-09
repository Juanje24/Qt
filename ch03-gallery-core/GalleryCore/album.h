#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

class Album
{
public:
    explicit Album(const QString& name = "");

    int getId() const;
    void setId(int id);
    QString getName() const;
    void setName (const QString& name);

private:
    int mId;
    QString mName;

};

#endif // ALBUM_H
