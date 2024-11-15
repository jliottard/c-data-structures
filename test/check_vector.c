#include <check.h>
#include "../src/vector.h"
#include <stdlib.h>

START_TEST (test_vector_new) {
    struct Vector *vector = vector_create(1);
    ck_assert_int_eq(vector_size(vector), 0);
    vector_delete(vector);
} END_TEST

Suite *vector_suite(void) {
    Suite *suite;
    TCase *testcase_core;

    suite = suite_create("Vector");
    testcase_core = tcase_create("Core");

    tcase_add_test(testcase_core, test_vector_new);
    suite_add_tcase(suite, testcase_core);

    return suite;
}

int main(void) {
    int no_failed = 0;
    Suite *suite;
    SRunner *runner;

    suite = vector_suite();
    runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
