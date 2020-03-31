#include <gio/gio.h>
#include <glib.h>

void file_monitor_cb(GFileMonitor *monitor, GFile *file, GFile *other, GFileMonitorEvent event, gpointer user_data) {
    char *path = g_file_get_path(file);
    switch (event) {
        case G_FILE_MONITOR_EVENT_DELETED:
            g_print("%s deleted\n", path);
            break;
        case G_FILE_MONITOR_EVENT_CREATED:
            g_print("%s created\n", path);
            break;
        default:
            break;
    }
    g_free(path);
}

int main(int argc, char *argv[]) {
    int ret = EXIT_SUCCESS;

    GMainLoop *loop = g_main_loop_new(NULL, FALSE);

    GFile *file = g_file_new_for_commandline_arg("monitored");
    GFileMonitor *monitor = g_file_monitor(file, G_FILE_MONITOR_WATCH_MOVES, NULL, NULL);
    if (!monitor) {
        ret = EXIT_FAILURE;
        goto clean;
    }
    g_signal_connect(G_OBJECT(monitor), "changed", G_CALLBACK(file_monitor_cb), NULL);

    g_main_loop_run(loop);

clean:
    g_main_loop_unref(loop);
    g_object_unref(file);
    g_object_unref(monitor);

    return ret;
}
