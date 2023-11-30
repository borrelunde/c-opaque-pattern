#include "application.h"

int main(void) {
    struct application app;

    application_init(&app);
    application_run(&app);
    application_deinit(&app);
}