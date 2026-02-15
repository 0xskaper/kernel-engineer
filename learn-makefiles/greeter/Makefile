.PHONY: clean
greet: main.o greet.o
	gcc -o greet main.o greet.o

main.o: main.c greet.h
	gcc -c main.c

greet.o: greet.c greet.h
	gcc -c greet.c

clean:
	rm -rf greet main.o greet.o
