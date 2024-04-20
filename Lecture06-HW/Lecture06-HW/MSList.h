#ifndef MSLIST_H
#define MSLIST_H

#include "MObject.h"

class MSList {
private:
    MObject** mObjects;
    int mSize;
    int mCapacity;

public:
    MSList();
    ~MSList();

    void push_back(MObject* object);
    MObject* at(int index) const;
    int size() const;
};

#endif 