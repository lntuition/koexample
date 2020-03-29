.PHONY: all

FLAGS=$(shell pkg-config --libs --cflags glib-2.0)
all: test
test: test.o
	gcc -o $@ $^ $(FLAGS)
test.o: test.c
	gcc -o $@ $^ -c $(FLAGS)

clean:
	rm -f *.o test