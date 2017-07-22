#include "PeopleObject.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <errno.h>
#include <string.h>
#include <semaphore.h>

sem_t sem_id;
sem_t sem_id2;

void *thread1(void *args)
{
	People sam = People_INITIALIZED("Sam", 22, 175);	
	int i = 15;
    printf("thread1\n");
    sem_wait(&sem_id);
	while(i-->0)
	{
        printf("Sam thread - name   : %s\n", ObjRef(&sam)->getName());
        printf("Sam thread - age    : %d\n", ObjRef(&sam)->getAge());
        printf("Sam thread - height : %d\n", ObjRef(&sam)->getHeight());
	}
    printf("Sam thread - toString :\n%s\n", ObjRef(&sam)->toString());
    Obj(sam).release();

	ThisRelease();
}

void *thread2(void *args)
{
    People* jack = new_People_P("Jack", 18, 163);	
	int i = 15;
    printf("thread2\n");
	sem_wait(&sem_id2);
    while(i-->0)
	{
        printf("Jack thread - name   : %s\n", ObjRef(jack)->getName());
        printf("Jack thread - age    : %d\n", ObjRef(jack)->getAge());
        printf("Jack thread - height : %d\n", ObjRef(jack)->getHeight());
	}
    printf("Jack thread - toString :\n%s\n", ObjRef(jack)->toString());

    delete_People(jack);
	ThisRelease();
}


int main(void)
{
    printf("%d\n", pthread_self());
    sem_init(&sem_id, 0, 0);
    sem_init(&sem_id2, 0, 0);
	pthread_t id;
    if(pthread_create(&id, NULL, thread1, NULL) != 0)
	{
		printf("create error\n");
		return 0;
	}
    printf("1\n");

	pthread_t id2;
	if(pthread_create(&id2, NULL, thread2, NULL) != 0)
	{
		printf("create error\n");
		return 0;
	}
    printf("2\n");



    People* sherwin = new_People();
    ObjRef(sherwin)->setName("sherwin");
    ObjRef(sherwin)->setAge(23);
    ObjRef(sherwin)->setHeight(175);

    int ageoff = 0;
	int i = 15;
    printf("3\n");
    sem_post(&sem_id);
    sem_post(&sem_id2);
	while(i-->0)
	{

        printf("sherwin thread - name   : %s\n", ObjRef(sherwin)->getName());
        ObjRef(sherwin)->setAge(ObjRef(sherwin)->getAge() + 1);
        printf("sherwin thread - age    : %d\n", ObjRef(sherwin)->getAge());
        printf("sherwin thread - height : %d\n", ObjRef(sherwin)->getHeight());
	}

    printf("sherwin thread - toString :\n%s\n", ObjRef(sherwin)->toString());
    delete_People(sherwin);
	pthread_join(id, NULL);
	pthread_join(id2, NULL);

    sem_destroy(&sem_id);
    sem_destroy(&sem_id2);
	return 0;
}