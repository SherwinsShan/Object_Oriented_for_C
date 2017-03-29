#ifndef _TESTINTERFACE_H
#define _TESTINTERFACE_H
#include "CThisSupport.h"

typedef struct
{
	char name[16];
}Object;

typedef struct 
{
	Object	obj;
	void	(*fun1)(void);
	void	(*fun2)(int i);
	void	(*fun3)(const char* str);
	int		(*fun4)(int i);
}testInterface;

void testInterface_f1(void);
void testInterface_f2(int i);
void testInterface_f3(const char* str);
int  testInterface_f4(int i);

#define testInterface_INITIALIZED(x) {{x}, testInterface_f1, testInterface_f2, testInterface_f3, testInterface_f4}   


#endif