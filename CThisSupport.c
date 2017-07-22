#include "CThisSupport.h"

#ifdef THIS_PTHREAD_SUPPORT

static struct thisStack
{
	void* thisContext;
	pthread_t tid;
	struct thisStack* next;
}thisStackHead = {NULL, 0, NULL};

	
void setThis(void* t)
{
	struct thisStack* temp = &thisStackHead;
	
	while(temp)
	{
		if(temp->tid == pthread_self())
		{
			temp->thisContext = t;
			break ;
		}
		else if(temp->next == NULL)
		{
			New_Item(struct thisStack, newNode);
			newNode->thisContext = t;
			newNode->tid = pthread_self();
			newNode->next = NULL;
			temp->next = newNode;
			break ;
		}

		temp = temp->next;
	}
	
}

void* getThis(void)
{
	struct thisStack* temp = thisStackHead.next;
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

void ThisRelease(void)
{
	struct thisStack* temp = thisStackHead.next;

	if(temp == NULL)
		return;

	struct thisStack* tempNext = temp->next;

	while(tempNext)
	{
		if(tempNext->tid == pthread_self())
		{
			temp->next = tempNext->next;
			free(tempNext);
			break;
		}
		
		temp = temp->next;
		tempNext = temp->next;
	}
}

#else
void* _this;
#endif
