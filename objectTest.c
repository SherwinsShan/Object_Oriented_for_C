#include <stdio.h>
#include <pthread.h>

#include "testInterface.h"

testInterface test1 = testInterface_INITIALIZED("Object1");
testInterface test2 = testInterface_INITIALIZED("Object2");

void *thread(void *args)
{
	testInterface* obj = &test2;
	Obj(test2).fun1();
	while(1)
	{
		ObjRef(obj)->fun2(2);
		ObjRef(obj)->fun3("sub thread");
		ObjRef(obj)->fun4(200);
		usleep(300 * 1000);
	}
}


int main(void)
{
	ThisSuppost();//多线程下必须调用，且在进行对象处理前调用
	
	pthread_t id;
	if(pthread_create(&id, NULL, thread, NULL) != 0)
	{
		printf("create error\n");
		return ;
	}

	testInterface* obj = &test1;
	Obj(test1).fun1();//实体式调用
	while(1)
	{
		//引用式调用
		ObjRef(obj)->fun1();
		ObjRef(obj)->fun2(1);
		ObjRef(obj)->fun3("main thread");
		ObjRef(obj)->fun4(100);
		usleep(300 * 1000);
	}
	return 0;
}