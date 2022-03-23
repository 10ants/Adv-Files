#include "Person.h"
#include "SerializedObject.h"
std::list<Person*>Person::sAllPeople;

Person* Person::NewPerson()
{
    Person* newPerson = new Person;
    Person::sAllPeople.push_back(newPerson);
    newPerson->mObjectID = Person::sAllPeople.size();
    return newPerson;
}

void Person::DeleteAll()
{
    std::list<Person*>::iterator iter;
    for (auto iter = Person::sAllPeople.begin(); iter != Person::sAllPeople.end(); ++iter)
        {
            Person::sAllPeople.erase(iter);
        }
}

SerializedObject* Person::Serialize()
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

Person* Person::CreateFromSO( SerializedObject* tSO )
{
    return nullptr;
}

