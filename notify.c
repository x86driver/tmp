#include<libnotify/notify.h>
#include<gdk-pixbuf/gdk-pixbuf.h>

int main() {
	NotifyNotification *not;
	GdkPixbuf *pixbuf;
	//GdkPixbufLoader *loader;

	notify_init('test');
	//loader = gdk_pixbuf_loader_new_with_type('png', NULL);
	//gdk_pixbuf_loader_write(loader, 'icon.png'
	pixbuf = gdk_pixbuf_new_from_file('logo.png', NULL);
	not = notify_notification_new('測試訊息', '這是一個測試訊息', NULL, NULL);
	notify_notification_set_timeout(not, 10000);
	notify_notification_set_icon_from_pixbuf(not, pixbuf);
	notify_notification_set_hint_int32 (not, 'x', 1000);
	notify_notification_set_hint_int32 (not, 'y', 50);
	notify_notification_show(not, NULL);

	return 0;
}

