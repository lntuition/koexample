#include <glib.h>

gboolean clock_callback(gpointer user_data) {
    GDateTime *now = g_date_time_new_now_utc();
    if (!now)
        return FALSE;

    g_print("%s.%d\n",
            g_date_time_format(now, "%Y/%m/%d, %H:%M:%S"),
            g_date_time_get_microsecond(now));
    g_date_time_unref(now);

    return TRUE;
}

int main(int argc, char *argv[]) {
    GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    if (!loop)
        return EXIT_FAILURE;

    g_timeout_add_seconds(1, clock_callback, NULL);
    g_main_loop_run(loop);

clean:
    g_main_loop_unref(loop);

    return EXIT_SUCCESS;
}