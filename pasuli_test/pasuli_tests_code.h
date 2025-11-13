#ifndef __PASULI_TESTS_CODE_INCLUDED__
#define __PASULI_TESTS_CODE_INCLUDED__
#include "pasuli_test.h"

typedef struct _PaSuLiTestPair {
  char *name;
  PaSuLiTestDesc **tests;
  int numTests;
} PaSuLiTestPair;

#define PASULI_TEST_PAIR(NAME, TESTS, NUMTESTS)                                \
  { NAME, TESTS, NUMTESTS }

void executePaSuLiTests();

#endif