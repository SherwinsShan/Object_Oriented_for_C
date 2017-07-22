#ifndef _CTHISSUPPORT_H
#define _CTHISSUPPORT_H


#ifdef THIS_PTHREAD_SUPPORT


#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> 
#include <assert.h>

void    ThisRelease(void);
void    setThis(void* t);
void*   getThis(void);



#define _this		getThis()
#define Obj(x)		(setThis(&(x)),x)
#define ObjRef(x)	(setThis((x)),x)

#else

extern void* _this;

#define ThisRelease()
#define Obj(x)			(_this=&(x),x)
#define ObjRef(x)		(_this=(x),x)


#endif


#define New_Item(type,name)     type* name = (type*)malloc(sizeof(type))
#define New_Array(type,name,n)  type* name = (type*)malloc(sizeof(type)*(n))

#define THIS(type)	 type *const this = (type *const) _this


#endif
