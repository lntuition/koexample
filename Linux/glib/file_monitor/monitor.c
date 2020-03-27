#include <gio/gio.h>
#include <glib.h>

void file_monitor_cb(GFileMonitor *monitor, GFile *file, GFile *other, GFileMonitorEvent event, gpointer user_data) {
    char *path = NULL;

    path = g_file_get_path(file);
    switch (event) {
        case G_FILE_MONITOR_EVENT_DELETED:
            g_print("%s deleted\n", path);
            break;
        case G_FILE_MONITOR_EVENT_CREATED:
            g_print("%s created\n", path);
            break;
        default:
            g_print("%s event %d\n", path, event);
            break;
    }
    g_free(path);
}

int main(int argc, char *argv[]) {
    GMainLoop *loop = NULL;
    GFile *file = NULL;
    GFileMonitor *monitor = NULL;
    GError *error = NULL;

    if (argc != 2) {
        g_print("Usage : %s <file path>\n", argv[0]);
        goto clean;
    }

    loop = g_main_loop_new(NULL, FALSE);

    file = g_file_new_for_commandline_arg(argv[1]);
    monitor = g_file_monitor(file, G_FILE_MONITOR_WATCH_MOVES, NULL, &error);
    if (error) {
        g_error("Failed while monitor %s (%s)\n", argv[1], error->message);
        goto clean;
    }
    g_signal_connect(G_OBJECT(monitor), "changed", G_CALLBACK(file_monitor_cb), NULL);

    g_main_loop_run(loop);

clean:
    if (loop) g_main_loop_unref(loop);
    if (file) g_object_unref(file);
    if (monitor) g_object_unref(monitor);
    if (error) g_error_free(error);

    return 0;
}