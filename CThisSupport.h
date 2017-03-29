#ifndef _CTHISSUPPORT_H
#define _CTHISSUPPORT_H


#ifdef THIS_PTHREAD_SUPPORT
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> 
#include <assert.h>

void    ThisSuppost(void);
void    setThis(void* t);
void*   getThis(void);

#define _this		getThis()
#define Obj(x)		(setThis(&(x)),x)
#define ObjRef(x)	(setThis((x)),x)

#else

extern void* _this;
#define ThisSuppost();	
#define Obj(x)			(_this=&(x),x)
#define ObjRef(x)		(_this=(x),x)


#endif
#endif
