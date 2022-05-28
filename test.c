#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>

#include "code.h"


void *__wrap_malloc(size_t size) { return test_malloc(size); }
void *__wrap_calloc(size_t nmemb, size_t size) { return test_calloc(nmemb, size); }
void *__wrap_realloc(void *ptr, size_t size) { return test_realloc(ptr, size); }
void  __wrap_free(void *ptr) { test_free(ptr); }

static void null_test_success(void **state)
{
	(void) state; /* unused */
	printf("run test\n");
	foo();
	printf("end test\n");
}

int main(void)
{
	const struct CMUnitTest tests[] = {
        	cmocka_unit_test(null_test_success),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
