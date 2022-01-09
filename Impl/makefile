CC=gcc
myprog:main.o Session.o
	$(CC) -o myprog main.o Session.o 
main.o:main.c
	$(CC) -c main.c
Session.o:Session.c
	$(CC) -c Session.c


.PHONY: clean

