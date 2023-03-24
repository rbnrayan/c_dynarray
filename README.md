# C_DYNARRAY

## Get started

Example:

```c
#include "dynarray.h"

GENERATE_DYNARRAY(int);

int main(void)
{
	struct dynarray_int *da = new_dynarray_int(5);
	
	for (int i = 0; i < 10; i++) {
		append_dynarray_int(int_dynarray, i);
	}
	
	print_dynarray(int_dynarray, "%d");
	
	pop_dynarray_int(int_dynarray);
	print_dynarray(int_dynarray, "%d");

	free_dynarray(int_dynarray);
	
	return 0;
}
```

## Documentation

### Generate the struct and all the related functions

```c
GENERATE_DYNARRAY(<TYPE>);

// translate to:

DELCARE_DYNARRAY(<TYPE>);  // declare the struct and all the functions
DEFINE_DYNARRAY(<TYPE>);   // define the body of all the related functions
```

### Get a new dynarray

To get a new dynnaray you first need to generate it for the wanted type. [See above](#Generate the struct and all the related functions)

```c
struct dynarray_<TYPE> *da = new_dynarray_<TYPE>(<CAPACITY>);
```

Don't forget to free the dynarray when you don't need it anymore.

```c
free_dynarray(da);
```

### Available functions

```c
// append a new item to the da (realloc if necessary)
append_dynarray_<TYPE>(da, <TYPE_VALUE>);

// pop the last item of the da
pop_dynarray_<TYPE>(da);

// shift the first item of the da
shift_dynarray_<TYPE>(da);

// free the da
free_dynarray(da);
```
