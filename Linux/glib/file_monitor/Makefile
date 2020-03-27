.PHONY: all

FLAGS=$(shell pkg-config --libs --cflags gio-2.0 glib-2.0)
all: monitor
monitor: monitor.o
	gcc -o $@ $^ $(FLAGS)
monitor.o: monitor.c
	gcc -o $@ $^ -c $(FLAGS)

clean:
	rm -f *.o monitor