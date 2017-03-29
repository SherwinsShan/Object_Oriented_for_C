TARGET=objectTest

SOURCE=objectTest.c CThisSupport.c testInterface.c

CFLAG=-lpthread -D THIS_PTHREAD_SUPPORT

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) -o $@ $^ $(CFLAG)

clean:
	rm -f $(TARGET)