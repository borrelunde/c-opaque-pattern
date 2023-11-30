#include "application.h"

#include <malloc.h>
#include <stdio.h>

int application_init(struct application *self) {
    // Allocating on the stack would not suffice for this application
    // because the person object goes out of scope when this function
    // ends.
    // self->person = alloca(person_size());
    // Instead, allocate the person on the heap, but remember to free
    // it!
    self->person = person_new();
    person_init(self->person);
    return 0;
}

int application_deinit(struct application *self) {
    person_deinit(self->person);
    person_free(&self->person);
    return 0;
}

int application_run(struct application *self) {
    person_set_name(self->person, "Aristotle");
    person_set_age(self->person, 62);
    printf("%s is %u years old.",
           person_get_name(self->person),
           person_get_age(self->person));
    return 0;
}