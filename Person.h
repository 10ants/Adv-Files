#pragma once
#include <list>

class Dog;
class SerializedObject;

class Person
{
public:
	static const int SID = 2;
    static Person* NewPerson();
    static void DeleteAll();
    static Person* CreateFromSO( SerializedObject* tSO );
    static Person* FindPersonFromID( int tID );

	Person* mBestFriend = nullptr;// When serialized, it is their object id (both are ints)
	Dog* mBestDog = nullptr;
	int mAge = 0;

    SerializedObject* Serialize(); // Only we know how to smoosh ourselves.  Everyone knows what an SO is

private:
	int mObjectID = 0; // Which person object am I?
	Person() {} // Can't make a person without going through our factory

	static std::list<Person*> sAllPeople;
};


