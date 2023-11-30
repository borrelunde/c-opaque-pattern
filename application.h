#pragma once

#include "person.h"

struct application {
    struct person *person;
};

int application_init(struct application *self);
int application_deinit(struct application *self);
int application_run(struct application *self);