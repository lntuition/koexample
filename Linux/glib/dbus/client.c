#include <gio/gio.h>
#include <glib.h>
#include "dbus-stub.h"

int main() {
    ComGlibDbus *proxy = com_glib_dbus_proxy_new_for_bus_sync(
        G_BUS_TYPE_SESSION, G_DBUS_PROXY_FLAGS_NONE,
        "com.glib.dbus", "/com/glib/dbus", NULL, NULL);

    gchar *out = NULL;
    com_glib_dbus_call_func_sync(proxy, "parameter", &out, NULL, NULL);
    g_print("%s\n", out);
    g_object_unref(proxy);

    return EXIT_SUCCESS;
}