#!/bin/bash

TESTS=$(ls test*)

for test in $TESTS; do
  printf "./%s" "$test"
  ./"$test" || (printf " \u001b[41mFAILED\u001b[0m" ; exit)
  printf " \u001b[32mPASSED\u001b[0m\n"
done

echo "All tests run and passed!"
