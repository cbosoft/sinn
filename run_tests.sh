#!/bin/bash

TESTS=$(ls tests/*)
for test in $TESTS; do
  LD_LIBRARY_PATH="$(pwd)":$LD_LIBRARY_PATH ./"$test" || exit 1
done

echo "All tests run and passed!"
