#ifndef _PEOPLEOBJECT_H
#define _PEOPLEOBJECT_H

#include "CThisSupport.h"


#define PEOPLE_NAME_MAX_LEN 16
typedef struct
{
    char name[16];
    unsigned short  age;
    unsigned short  height;
    
    const char* (*getName)(void);
    unsigned short (*getAge)(void);
    unsigned short (*getHeight)(void);


    void (*setName)(const char* name);
    void (*setAge)(unsigned short age);
    void (*setHeight)(unsigned short age);


    const char* (*toString)(void);
    void (*release)(void);
    void* extra;

}People;

const char* People_getName(void);
unsigned short People_getAge(void);
unsigned short People_getHeight(void);

void People_setName(const char* name);
void People_setAge(unsigned short age);
void People_setHeight(unsigned short age);

const char* People_toString(void);
void People_release(void);


People*     new_People_P(const char* name, unsigned short  age, unsigned short height);
People*     new_People(void);
void        delete_People(People* people);


#define People_INITIALIZED(a,b,c) {a, b ,c, People_getName, People_getAge, People_getHeight, People_setName, People_setAge,People_setHeight,People_toString, People_release, NULL}   



#endif

