TARGET=Test

SOURCE=PeopleObjectTest.c CThisSupport.c PeopleObject.c

CFLAG=-lpthread -D THIS_PTHREAD_SUPPORT

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) -o $@ $^ $(CFLAG)

clean:
	rm -f $(TARGET)