#include "album.h"

Album::Album(const QString& name) :
    mId(-1),
    mName(name)
{
}
int Album::getId() const{
    return mId;
}
void Album::setId(int id){
    this->mId=id;
}
QString Album::getName() const{
    return mName;
}
void Album::setName (const QString& name){
    this->mName=name;
}
