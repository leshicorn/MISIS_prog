#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct queue
{
    void* data;
    size_t elem_size;
    size_t capacity;
    size_t used;
    size_t tail;
    size_t front;
};

struct queue*   queue_new(size_t elem_size);
int             queue_push(struct queue* q, const void* elem);
int             queue_pop(struct queue* q, void* elem);
int             queue_empty(struct queue const* q);
struct  queue*  queue_delete(struct queue* q);
void            queue_print(struct queue const* q, void (*pf) (void const* data));