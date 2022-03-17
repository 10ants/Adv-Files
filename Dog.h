#pragma once
#include <list>


class SerializedObject;

class Dog
{
public:
	static const int SID = 1;
    static Dog* NewDog();
    static void DeleteAll();
    static Dog* CreateFromSO( SerializedObject* tSO );
    static Dog* FindDogFromID( int tID );

	int mAge = 0;

    SerializedObject* Serialize(); // Only we know how to smoosh ourselves.  Everyone knows what an SO is

private:
	int mObjectID = 0; // Which Dog object am I?
	Dog()
    {
        mObjectID =2;
        mAge =24;
    }// Can't make a person without going through our factory
	static std::list<Dog*> sAllDogs;

};

