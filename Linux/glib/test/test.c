#include <glib.h>

static void success(void) {
    g_assert(TRUE);
}

int main(int argc, char *argv[]) {
    g_test_init(&argc, &argv, NULL);
    g_test_add_func("/success", success);
    return g_test_run();
}