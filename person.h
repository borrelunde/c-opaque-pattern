#pragma once

#include <stdint.h>

struct person;

// Person constructor and destructor.
int person_init(struct person *self);
int person_deinit(struct person *self);

size_t person_size(void);

// Functions for dynamic memory allocation.
struct person *person_new();
void person_free(struct person **self);

// Functions that operate on the opaque person object.
void person_set_name(struct person *self, const char *name);
const char *person_get_name(struct person *self);
void person_set_age(struct person *self, uint8_t age);
uint8_t person_get_age(struct person *self);