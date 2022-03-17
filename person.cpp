#include "Person.h"
#include "SerializedObject.h"

Person* Person::NewPerson()
{
    Person* newPerson = new Person;
    //sAllPeople.push_back(newPerson);
    return newPerson;
}

void Person::DeleteAll()
{
    std::list<Person*>::iterator iter;
    for (auto iter = sAllPeople.begin(); iter != sAllPeople.end(); ++iter)
        {
            sAllPeople.erase(iter);
        }
}

SerializedObject* Person::Serialize()
{
    SerializedObject* SO = new SerializedObject;
    SO->mClassID = SID;
    int mSize = sizeof(*this);
    SO->mFullSize = sizeof(*this);
    SO->mBufferSize= mSize +3;
    
    SO->mBuffer = new char[mSize];
    SO->mBuffer[0] = mAge<<29;
    SO->mBuffer[0]= mAge<<19;
    SO->mBuffer[0] = mAge<<10;
    return SO;
}



Person* Person::CreateFromSO( SerializedObject* tSO )
{
    return nullptr;
}

Person* Person::FindPersonFromID( int tID )
{
    return nullptr;
    
}
