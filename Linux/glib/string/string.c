#include <glib.h>

int main(int argc, char *argv[]) {
    gchar **splited = g_strsplit("2013/01/02", "/", -1);
    guint len = g_strv_length(splited);
    for (guint i = 0; i < len; ++i) {
        g_print("%s\n", splited[i]);
    }
    return EXIT_SUCCESS;
}