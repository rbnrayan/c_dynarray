#ifndef DYNARRAY
#define DYNARRAY

#include <stdlib.h>

#define DECLARE_DYNARRAY_STRUCT(TYPE) \
    struct dynarray_##TYPE         \
    {                              \
        TYPE *items;               \
        size_t capacity;           \
        size_t count;              \
    }

#define DECLARE_NEW_DYNARRAY(TYPE) \
    struct dynarray_##TYPE *new_dynarray_##TYPE(size_t capacity)

#define DEFINE_NEW_DYNARRAY(TYPE) \
    struct dynarray_##TYPE *new_dynarray_##TYPE(size_t capacity)              \
    {                                                                         \
        struct dynarray_##TYPE *dyn_array =                                   \
            (struct dynarray_##TYPE *)malloc(sizeof(struct dynarray_##TYPE)); \
                                                                              \
        if (dyn_array == NULL)                                                \
            return NULL;                                                      \
                                                                              \
        dyn_array->items = malloc(sizeof(TYPE) * capacity);                   \
                                                                              \
        dyn_array->capacity = capacity;                                       \
        dyn_array->count = 0;                                                 \
                                                                              \
        return dyn_array;                                                     \
    }

#define free_dynarray(da) \
    do {                 \
        free(da->items); \
        free(da);        \
    } while (0)

#define print_dynarray(da, joker) \
    do {                                         \
        if (da->count == 0 || da->items == NULL) \
        {                                        \
            printf("No items.\n");               \
            break;                               \
        }                                        \
                                                 \
        size_t i;                                \
        printf("{ ");                            \
        for (i = 0; i < da->count; i++)          \
        {                                        \
            printf(joker ", ", da->items[i]);    \
        }                                        \
        printf("}\n");                           \
    } while (0)

#define DECLARE_APPEND_DYNARRAY(TYPE) \
    void append_dynarray_##TYPE(struct dynarray_##TYPE *dyn_array, TYPE value)

#define DEFINE_APPEND_DYNARRAY(TYPE) \
    void append_dynarray_##TYPE(struct dynarray_##TYPE *dyn_array, TYPE value)            \
    {                                                                                     \
        if (dyn_array == NULL || dyn_array->items == NULL)                                \
        {                                                                                 \
            printf("Can't append to NULL.\n");                                            \
            exit(1);                                                                      \
        }                                                                                 \
                                                                                          \
        if (dyn_array->count+1 <= dyn_array->capacity)                                    \
        {                                                                                 \
            dyn_array->items[dyn_array->count++] = value;                                 \
            return;                                                                       \
        }                                                                                 \
                                                                                          \
        dyn_array->capacity += 1;                                                         \
        dyn_array->items = realloc(dyn_array->items, dyn_array->capacity * sizeof(TYPE)); \
                                                                                          \
        if (dyn_array->items == NULL)                                                     \
        {                                                                                 \
            printf("Failed to realloc items.\n");                                         \
            free(dyn_array);                                                              \
            exit(1);                                                                      \
        }                                                                                 \
                                                                                          \
        dyn_array->items[dyn_array->count++] = value;                                     \
    }

#define DECLARE_POP_DYNARRAY(TYPE) \
    TYPE pop_dynarray_##TYPE(struct dynarray_##TYPE *da)

#define DEFINE_POP_DYNARRAY(TYPE) \
    TYPE pop_dynarray_##TYPE(struct dynarray_##TYPE *da) \
    { \
        if (da->count == 0 || da->items == NULL) \
        { \
            printf("Tried to pop from empty array.\n"); \
            free(da); \
            exit(1); \
        } \
        TYPE value = da->items[--da->count]; \
        return value; \
    }

#define DECLARE_SHIFT_DYNARRAY(TYPE) \
    TYPE shift_dynarray_##TYPE(struct dynarray_##TYPE *da)

#define DEFINE_SHIFT_DYNARRAY(TYPE) \
    TYPE shift_dynarray_##TYPE(struct dynarray_##TYPE *da) \
    { \
        if (da->count == 0 || da->items == NULL) \
        { \
            printf("Tried to shift from empty array.\n"); \
            free(da); \
            exit(1); \
        } \
        \
        size_t i; \
        TYPE value = da->items[0]; \
        for (i = 0; i < da->count-1; i++) \
        { \
            da->items[i] = da->items[i+1]; \
        } \
        da->count -= 1; \
        return value; \
    }

#define DECLARE_DYNARRAY(TYPE) \
    DECLARE_DYNARRAY_STRUCT(TYPE); \
    DECLARE_NEW_DYNARRAY(TYPE);    \
    DECLARE_APPEND_DYNARRAY(TYPE); \
    DECLARE_POP_DYNARRAY(TYPE);    \
    DECLARE_SHIFT_DYNARRAY(TYPE)

#define DEFINE_DYNARRAY(TYPE) \
    DEFINE_NEW_DYNARRAY(TYPE)    \
    DEFINE_APPEND_DYNARRAY(TYPE) \
    DEFINE_POP_DYNARRAY(TYPE)    \
    DEFINE_SHIFT_DYNARRAY(TYPE)

#define GENERATE_DYNARRAY(TYPE) \
    DECLARE_DYNARRAY(TYPE); \
    DEFINE_DYNARRAY(TYPE)

#endif
