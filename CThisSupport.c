#include "CThisSupport.h"

#ifdef THIS_PTHREAD_SUPPORT

static struct thisStack
{
	void* thisContext;
	pthread_t tid;
	struct thisStack* next;
}thisStackHead = {NULL, 0, NULL};

void ThisSuppost(void)
{
	thisStackHead.tid = pthread_self();
}

void setThis(void* t)
{
	struct thisStack* temp = &thisStackHead;
	
	while(temp)
	{
		if(temp->tid == pthread_self())
		{
			temp->thisContext = t;
			return ;
		}
		
		if(temp->next == NULL)
		{
			struct thisStack* newNode = (struct thisStack*) malloc(sizeof(struct thisStack));
			newNode->thisContext = t;
			newNode->tid = pthread_self();
			newNode->next = NULL;
			temp->next = newNode;
			return ;
		}
		temp = temp->next;
	}
}

void* getThis(void)
{
	struct thisStack* temp = &thisStackHead;
	while(temp)
	{
		if(temp->tid == pthread_self())
		{
			return temp->thisContext;
		}
		temp = temp->next;
	}
	assert(0 && "Cannot Found this");
	return NULL;
}
#else
void* _this;
#endif
