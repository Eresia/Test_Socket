CC=ldc2
binFolder=bin
CFLAGS=-od $(binFolder)
LDFLAGS=
SRC= $(wildcard *.d)
OBJ= $(SRC:%.d=$(binFolder)/%.o)
EXEC=testTCP_IPV6.out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -of $(EXEC) $^ $(LDFLAGS)

$(binFolder)/%.o: %.d
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(binFolder)

mrproper: clean
	rm -f $(EXEC)
