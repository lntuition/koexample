.PHONY: all

FLAGS=$(shell pkg-config --libs --cflags glib-2.0)
all: string
string: string.o
	gcc -o $@ $^ $(FLAGS)
string.o: string.c
	gcc -o $@ $^ -c $(FLAGS)

clean:
	rm -f *.o string