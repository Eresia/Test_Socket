CC=ldc2
binFolder=bin
CFLAGS=-od $(binFolder)
LDFLAGS=
EXEC=createUDP.out

all: $(EXEC)

$(EXEC): $(binFolder)/main.o $(binFolder)/client.o $(binFolder)/server.o
	$(CC) -of $(EXEC) $^ $(LDFLAGS)

$(binFolder)/main.o: main.d
	$(CC) $(CFLAGS) -c main.d

$(binFolder)/client.o: client.d
	$(CC) $(CFLAGS) -c client.d

$(binFolder)/server.o: server.d
	$(CC) $(CFLAGS) -c server.d

clean:
	rm -rf $(binFolder)

mrproper: clean
	rm -f $(EXEC)
