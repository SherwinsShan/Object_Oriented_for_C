#include <stdio.h>
#include "testInterface.h"

void testInterface_f1(void)
{
	testInterface* self = _this;
	printf("%s fun1\n",self->obj.name);
}
void testInterface_f2(int i)
{
	testInterface* self = _this;
	printf("%s fun2 : %d\n",self->obj.name, i);
}

void testInterface_f3(const char* str)
{
	if(str[0] == 'm')	//不添加 THIS_PTHREAD_SUPPORT宏，多线程测试，添加高延时可明显看到_this指针混乱
		sleep(1);
	testInterface* self = _this;
	printf("%s fun3: %s\n",self->obj.name, str);
}

int testInterface_f4(int i)
{
	testInterface* self = _this;
	printf("%s fun4 : %d\n",self->obj.name, i + 1);
	return i + 1;
}



