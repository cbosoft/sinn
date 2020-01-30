#!/bin/bash

TESTS=$(ls test*)

for test in $TESTS; do
  ./"$test" || exit 1
done

echo "All tests run and passed!"
