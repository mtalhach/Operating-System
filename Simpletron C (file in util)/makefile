simpletron: simple.o libsimple.a
	gcc -o simple.exe simple.o -L. -lsimple
	
simple.o: simple.c simple.h
	gcc -c simple.c
	

util.o: util.c
	gcc -c util.c
	
libsimple.a: simple.o util.o
	ar cr libsimple.a simple.o util.o


clean:
	rm simple.exe libsimple.a simple.o util.o

