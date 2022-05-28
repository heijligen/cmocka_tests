#include <stdlib.h>
#include <stdio.h>
#include "code.h"

void foo(void)
{
	void *ptr = malloc(42);
	printf("foo %p\n", ptr);
	
	/* comment out this free to test for the memory leak */
	//free(ptr);
}
