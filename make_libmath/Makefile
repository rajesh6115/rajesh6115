mymath:
	gcc -c -I./include/ src/mymath.c -fPIC
	gcc -o libmymath.so mymath.o -shared

example: mymath
	gcc -c -I./include/ example/main.c
	gcc -o mymathex -L./ main.o -lmymath

all: example
	echo 'building done'

clean:
	rm -rf *.o
	rm -rf libmymath.so
	rm -rf mymathex
