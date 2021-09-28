#Henrique e Leon

CFLAGS = -Wall -lm -lmatheval

all: ep01

ep01: ep01.c
	gcc ep01.c -o ep01 $(CFLAGS)

#purge: clean
#	-rm -f ep01
#clean:
#	-rm -f $(objects)