#include "picture.h"

Picture::Picture(const QString& filePath) :
    Picture(QUrl::fromLocalFile(filePath))
{
}
Picture::Picture(const QUrl& fileUrl) :
    mId(-1),
    mAlbumId(-1),
    mFileUrl(fileUrl)
{
}
int Picture::getId() const{
    return mId;
}
void Picture::setId(int id){
    this->mId=id;
}
int Picture::getAlbumId() const{
    return mAlbumId;
}
void Picture::setAlbumId(int albumId){
    this->mAlbumId=albumId;
}


QUrl Picture::getFileUrl() const
{
    return mFileUrl;
}
void Picture::setFileUrl(const QUrl& fileUrl)
{
    mFileUrl = fileUrl;
}
