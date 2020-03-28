.PHONY: all

FLAGS=$(shell pkg-config --libs --cflags glib-2.0)
all: clock
clock: clock.o
	gcc -o $@ $^ $(FLAGS)
clock.o: clock.c
	gcc -o $@ $^ -c $(FLAGS)

clean:
	rm -f *.o clock