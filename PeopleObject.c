#include "PeopleObject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void People_init(People* people)
{
    people->getName = People_getName;
    people->getAge = People_getAge;
    people->getHeight = People_getHeight;

    people->setName = People_setName;
    people->setAge = People_setAge;
    people->setHeight = People_setHeight;

    people->toString = People_toString;
    people->release = People_release;
    people->extra = NULL;
}

People*  new_People(void)
{
    New_Item(People, ret);
    if(ret == NULL)
    {
        return NULL;
    }

    People_init(ret);
    return ret;
}

People*  new_People_P(const char* name, unsigned short  age, unsigned short height)
{
    People* ret = new_People();

    if(ret == NULL)
    {
        return NULL;
    }

    strncpy(ret->name, name, PEOPLE_NAME_MAX_LEN);
    ret->age = age;
    ret->height = height;
    return ret;
}

void delete_People(People* people)
{
    ObjRef(people)->release();
    free(people);
}




const char* People_getName(void)
{
    THIS(People);
    return this->name;
}

unsigned short People_getAge(void)
{
    THIS(People);
    return this->age;
}

unsigned short People_getHeight(void)
{
    THIS(People);
    return this->height;
}

void People_setName(const char* name)
{
    THIS(People);
    strncpy(this->name, name, PEOPLE_NAME_MAX_LEN);
}


void People_setAge(unsigned short age)
{
    THIS(People);
    this->age = age;
}

void People_setHeight(unsigned short height)
{
    THIS(People);
    this->height = height;
}

const char* People_toString(void)
{
    THIS(People);
    if(this->extra == NULL)
    {
        Set_New_Array(char, this->extra, 128);
    }

    if(this->extra == NULL)
    {
        return NULL;
    }

    char* cache = this->extra;
    memset(cache, 0, strlen(cache));
    sprintf(cache, "People{\n\tname: %s\n\tage: %d\n\theight: %d\n}\n", this->name, this->age, this->height);
    return (const char*)cache;
}

void People_release(void)
{
    THIS(People);
    if(this->extra != NULL)
    {
        free(this->extra);
        this->extra = NULL;
    }
}