#include "MSList.h"

MSList::MSList() : mObjects(nullptr), mSize(0), mCapacity(0) {}

MSList::~MSList() {
    if (mObjects != nullptr) {
        delete[] mObjects;
    }
}

void MSList::push_back(MObject* object) {
    if (mSize >= mCapacity) {
        int newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
        MObject** newArray = new MObject * [newCapacity];

        for (int i = 0; i < mSize; ++i) {
            newArray[i] = mObjects[i];
        }

        if (mObjects != nullptr) {
            delete[] mObjects;
        }

        mObjects = newArray;
        mCapacity = newCapacity;
    }

    mObjects[mSize++] = object;
}

MObject* MSList::at(int index) const {
    if (index < 0 || index >= mSize) {
        return nullptr;
    }

    return mObjects[index];
}

int MSList::size() const {
    return mSize;
}