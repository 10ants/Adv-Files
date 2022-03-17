#include "Dog.h"
#include "SerializedObject.h"

 Dog* Dog::NewDog()
{
     Dog* newDog = new Dog;
     sAllDogs.push_back(newDog);
     return newDog;
}

void Dog::DeleteAll()
{
    std::list<Dog*>::iterator iter;
    for (auto iter = sAllDogs.begin(); iter != sAllDogs.end(); ++iter)
        {
           sAllDogs.erase(iter);
       }
}

SerializedObject* Dog::Serialize()
{
    SerializedObject* SO = new SerializedObject;
    SO->mClassID = SID;
    int mSize = sizeof(*this);
    SO->mFullSize = sizeof(*this);
    SO->mBufferSize= mSize +3;

    SO->mBuffer = new char[mSize];
    SO->mBuffer[0] =mAge<<6;
    SO->mBuffer[0]= mAge<<3;
    SO->mBuffer[0]=mAge<<7;
    return SO;
    
}


Dog* Dog::CreateFromSO( SerializedObject* tSO )
{
    return nullptr;

}

Dog* Dog::FindDogFromID( int tID )
{
    return nullptr;
    
}
