#include "Dog.h"
#include "SerializedObject.h"
std::list<Dog*>Dog::sAllDogs;
 Dog* Dog::NewDog()
{
     Dog* newDog = new Dog;
     Dog::sAllDogs.push_back(newDog);
     newDog->mObjectID = Dog::sAllDogs.size();
     return newDog;
}

void Dog::DeleteAll()
{
    std::list<Dog*>::iterator iter;
    for (auto iter = Dog::sAllDogs.begin(); iter != Dog::sAllDogs.end(); ++iter)
        {
           Dog::sAllDogs.erase(iter);
       }
}

SerializedObject* Dog::Serialize()
{
    int mSize = sizeof(*this);
    SerializedObject* SO = new SerializedObject;
    SO->mClassID = SID;
    SO->mFullSize = sizeof(*this);
    SO->mBufferSize= (sizeof(int)*3);
    SO->mBuffer = new char[mSize];
    SO->mBuffer[0] = mAge & 0xff;
    SO->mBuffer[1]= (mAge>>8) & 0xff;
    SO->mBuffer[2] = (mAge>>16) & 0xff;
    SO->mBuffer[3] = (mAge>>7) & 0xff;
    SO->mBuffer[0] = (mObjectID) & 0xff;
    SO->mBuffer[1] = (mObjectID>>8) & 0xff;
    SO->mBuffer[2] = (mObjectID>>16) & 0xff;
    SO->mBuffer[3] = (mObjectID>>7) & 0xff;
    return SO;
}

Dog* Dog::CreateFromSO( SerializedObject* tSO )
{
    return nullptr;

}

