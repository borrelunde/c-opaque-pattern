#include "person.h"

#include <malloc.h>
#include <memory.h>
#include <string.h>

// The maximum number of characters the name can be.
#define NAME_MAX_LEN 32

struct person {
    char name[NAME_MAX_LEN];
    uint8_t age;
};

int person_init(struct person *self) {
    // It is important to use sizeof(*self) which returns the
    // size of the person object the self pointer points to.
    // Not sizeof(self) which would only be the size of the pointer.
    memset(self, 0, sizeof(*self));
    return 0;
}

int person_deinit(struct person *self) {
    return 0;
}

size_t person_size(void) {
    return sizeof(struct person);
}

struct person *person_new() {
    // Dynamically allocate a person instance.
    return malloc(person_size());
    // In a real application it is worth considering adding error
    // handling were the allocation to fail.
}

void person_free(struct person **self) {
    // Free the dynamically allocated instance.
    free(*self);
    // Set the passed pointer to NULL to prevent a dangling pointer.
    *self = NULL;
}

void person_set_name(struct person *self, const char *name) {
    strncpy(self->name, name, NAME_MAX_LEN);
    self->name[NAME_MAX_LEN - 1] = '\0';  // Ensure null-termination.
}

const char *person_get_name(struct person *self) {
    return self->name;
}

void person_set_age(struct person *self, uint8_t age) {
    self->age = age;
}

uint8_t person_get_age(struct person *self) {
    return self->age;
}