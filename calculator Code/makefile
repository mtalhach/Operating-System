mycal: main.o libmystaticlib.a
	gcc -o mycal main.o -L. -lmystaticlib

main.o: main.c myheader.h
	gcc -c main.c

add.o: add.c
	gcc -c add.c

div.o: div.c
	gcc -c div.c

mul.o: mul.c
	gcc -c mul.c

sub.o: sub.c
	gcc -c sub.c

libmystaticlib.a: add.o div.o mul.o sub.o
	ar cr libmystaticlib.a add.o div.o mul.o sub.o

clean:
	rm *.o libmystaticlib.a mycal
