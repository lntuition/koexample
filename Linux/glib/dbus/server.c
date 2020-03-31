#include <gio/gio.h>
#include <glib.h>
#include "dbus-stub.h"

static gboolean handle_func(ComGlibDbus *skeleton, GDBusMethodInvocation *invocation, const gchar *in, gpointer user_data) {
    gchar *out = g_strdup_printf("%s", in);
    com_glib_dbus_complete_func(skeleton, invocation, out);
    g_print("%s\n", out);
    g_free(out);

    return TRUE;
}

static void on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data) {
    ComGlibDbus *skeleton = com_glib_dbus_skeleton_new();
    g_signal_connect(skeleton, "handle-func", G_CALLBACK(handle_func), NULL);
    g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton), connection, "/com/glib/dbus", NULL);
}

int main() {
    GMainLoop *loop = g_main_loop_new(NULL, FALSE);

    guint id = g_bus_own_name(G_BUS_TYPE_SESSION, "com.glib.dbus", G_BUS_NAME_OWNER_FLAGS_NONE, NULL,
                              on_name_acquired, NULL, NULL, NULL);

    g_main_loop_run(loop);

    return EXIT_SUCCESS;
}