CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lpthread
EXEC=createUDP.out

all: $(EXEC)

$(EXEC): main.o client.o server.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c client.h server.h network.h
	$(CC) $(CFLAGS) -o $@ -c main.c

client.o: client.c client.h network.h
	$(CC) $(CFLAGS) -o $@ -c client.c

server.o: server.c server.h network.h
	$(CC) $(CFLAGS) -o $@ -c server.c

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
