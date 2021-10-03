#Henrique e Leon

CFLAGS = -Wall -lm -lmatheval

objects = funcoes.o

all: ep01

ep01: ep01.c $(objects)
	gcc ep01.c -o ep01 $(objects) $(CFLAGS)

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c $(CFLAGS)

purge: clean
	-rm -f ep01
clean:
	-rm -f $(objects)
