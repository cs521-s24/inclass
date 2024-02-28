#include <stdbool.h>
#include <stdio.h>

struct rarray;

// Set the verbose flag for the rarray so we can test it
void rarray_verbose(struct rarray *, bool);

// Allocate a new resizable array with given elem size
struct rarray *rarray_alloc(size_t);

// Free the array and all of its elements
void rarray_free(struct rarray *);

// Add a new element to the rarray, resizing as needed
void rarray_append(struct rarray *, void *);

// Remove an element from the rarray, resizing as needed
void rarray_remove(struct rarray *, void *);

// How many elements does the rarray have space for?
size_t rarray_capacity(struct rarray *);
// How many elements are occupied?
size_t rarray_size(struct rarray *);

// Sort in place, descending
void rarray_sort(struct rarray *);
