TARGET = notify notify2 ass1

all:$(TARGET)

notify:notify.c
	gcc -o notify notify.c -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include/ -I/usr/include/gtk-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -lnotify

notify2:notify2.c
	gcc `pkg-config --cflags gtk+-2.0` `pkg-config --cflags glib-2.0` notify2.c -lnotify -o notify2

ass1:ass1.c
	arm-none-linux-gnueabi-gcc -Os -o ass1 ass1.c

clean:
	rm -rf $(TARGET)

