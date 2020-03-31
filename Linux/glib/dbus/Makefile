.PHONY: all

FLAGS=$(shell pkg-config --libs --cflags gio-2.0 gio-unix-2.0 glib-2.0)
all: stub server client
server: server.o dbus-stub.o
	gcc -o $@ $^ $(FLAGS)
client: client.o dbus-stub.o
	gcc -o $@ $^ $(FLAGS)
server.o: server.c
	gcc -o $@ $^ -c $(FLAGS)
client.o: client.c
	gcc -o $@ $^ -c $(FLAGS)
dbus-stub.o: dbus-stub.c
	gcc -o $@ $^ -c $(FLAGS)
stub:
	gdbus-codegen --generate-c-code dbus-stub com.glib.dbus.xml

clean:
	rm -f *.o dbus-stub.* server client

introspect:
	gdbus introspect -e -d com.glib.dbus -o /com/glib/dbus

call:
	gdbus call -e -d com.glib.dbus -o /com/glib/dbus -m com.glib.dbus.func parameter
send:
	dbus-send --session --dest=com.glib.dbus --type=method_call /com/glib/dbus com.glib.dbus.func string:'parameter'