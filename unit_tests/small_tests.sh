#!/bin/bash

# to test for errors:
# ./unit_tests/small_tests.sh | grep KO
ARG="0 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG

ARG="0 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG

ARG="0 1 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 3 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 3 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 4 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 1 4 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 1 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 1 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 3 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 3 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 4 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 2 4 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 1 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 1 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 2 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 2 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 4 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 3 4 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 4 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 4 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 4 2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 4 2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 4 3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="0 4 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 2 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 3 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 3 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 4 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 0 4 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 0 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 0 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3 0 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 3 4 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 4 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 2 4 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 0 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 0 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2 0 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 2 4 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 4 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 3 4 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 0 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 0 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 2 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 2 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 3 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="1 4 3 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 1 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 1 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 3 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 3 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 4 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 0 4 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 0 3 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 0 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3 0 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 3 4 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 4 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 1 4 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 0 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 0 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 0 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 1 4 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 4 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 3 4 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 0 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 0 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 1 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 1 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 3 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="2 4 3 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 1 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 1 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 2 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 2 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 4 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 0 4 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 0 2 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 0 4 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 2 0 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 2 4 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 4 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 1 4 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 0 1 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 0 4 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1 0 4"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 1 4 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 4 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 2 4 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 0 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 0 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 1 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 1 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 2 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="3 4 2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 0 1 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 0 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 0 2 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 0 2 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 0 3 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 0 3 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 0 2 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 0 3 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 2 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 2 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 3 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 1 3 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 0 1 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 0 3 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 1 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 1 3 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 3 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 2 3 1 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 0 1 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 0 2 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 1 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 1 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 2 0 1"; ./push_swap $ARG | ./checker_Mac $ARG
ARG="4 3 2 1 0"; ./push_swap $ARG | ./checker_Mac $ARG

echo "3 values"
./push_swap 0 1 2 | wc -l
./push_swap 0 2 1 | wc -l
./push_swap 1 0 2 | wc -l
./push_swap 1 2 0 | wc -l
./push_swap 2 0 1 | wc -l
./push_swap 2 1 0 | wc -l

echo "4 values"
./push_swap 0 1 2 3 | wc -l
./push_swap 0 1 3 2 | wc -l
./push_swap 0 2 1 3 | wc -l
./push_swap 0 2 3 1 | wc -l
./push_swap 0 3 1 2 | wc -l
./push_swap 0 3 2 1 | wc -l
./push_swap 1 0 2 3 | wc -l
./push_swap 1 0 3 2 | wc -l
./push_swap 1 2 0 3 | wc -l
./push_swap 1 2 3 0 | wc -l
./push_swap 1 3 0 2 | wc -l
./push_swap 1 3 2 0 | wc -l
./push_swap 2 0 1 3 | wc -l
./push_swap 2 0 3 1 | wc -l
./push_swap 2 1 0 3 | wc -l
./push_swap 2 1 3 0 | wc -l
./push_swap 2 3 0 1 | wc -l
./push_swap 2 3 1 0 | wc -l
./push_swap 3 0 1 2 | wc -l
./push_swap 3 0 2 1 | wc -l
./push_swap 3 1 0 2 | wc -l
./push_swap 3 1 2 0 | wc -l
./push_swap 3 2 0 1 | wc -l
./push_swap 3 2 1 0 | wc -l

echo "5 values"
./push_swap 0 1 2 3 4 | wc -l
./push_swap 0 1 2 4 3 | wc -l
./push_swap 0 1 3 2 4 | wc -l
./push_swap 0 1 3 4 2 | wc -l
./push_swap 0 1 4 2 3 | wc -l
./push_swap 0 1 4 3 2 | wc -l
./push_swap 0 2 1 3 4 | wc -l
./push_swap 0 2 1 4 3 | wc -l
./push_swap 0 2 3 1 4 | wc -l
./push_swap 0 2 3 4 1 | wc -l
./push_swap 0 2 4 1 3 | wc -l
./push_swap 0 2 4 3 1 | wc -l
./push_swap 0 3 1 2 4 | wc -l
./push_swap 0 3 1 4 2 | wc -l
./push_swap 0 3 2 1 4 | wc -l
./push_swap 0 3 2 4 1 | wc -l
./push_swap 0 3 4 1 2 | wc -l
./push_swap 0 3 4 2 1 | wc -l
./push_swap 0 4 1 2 3 | wc -l
./push_swap 0 4 1 3 2 | wc -l
./push_swap 0 4 2 1 3 | wc -l
./push_swap 0 4 2 3 1 | wc -l
./push_swap 0 4 3 1 2 | wc -l
./push_swap 0 4 3 2 1 | wc -l
./push_swap 1 0 2 3 4 | wc -l
./push_swap 1 0 2 4 3 | wc -l
./push_swap 1 0 3 2 4 | wc -l
./push_swap 1 0 3 4 2 | wc -l
./push_swap 1 0 4 2 3 | wc -l
./push_swap 1 0 4 3 2 | wc -l
./push_swap 1 2 0 3 4 | wc -l
./push_swap 1 2 0 4 3 | wc -l
./push_swap 1 2 3 0 4 | wc -l
./push_swap 1 2 3 4 0 | wc -l
./push_swap 1 2 4 0 3 | wc -l
./push_swap 1 2 4 3 0 | wc -l
./push_swap 1 3 0 2 4 | wc -l
./push_swap 1 3 0 4 2 | wc -l
./push_swap 1 3 2 0 4 | wc -l
./push_swap 1 3 2 4 0 | wc -l
./push_swap 1 3 4 0 2 | wc -l
./push_swap 1 3 4 2 0 | wc -l
./push_swap 1 4 0 2 3 | wc -l
./push_swap 1 4 0 3 2 | wc -l
./push_swap 1 4 2 0 3 | wc -l
./push_swap 1 4 2 3 0 | wc -l
./push_swap 1 4 3 0 2 | wc -l
./push_swap 1 4 3 2 0 | wc -l
./push_swap 2 0 1 3 4 | wc -l
./push_swap 2 0 1 4 3 | wc -l
./push_swap 2 0 3 1 4 | wc -l
./push_swap 2 0 3 4 1 | wc -l
./push_swap 2 0 4 1 3 | wc -l
./push_swap 2 0 4 3 1 | wc -l
./push_swap 2 1 0 3 4 | wc -l
./push_swap 2 1 0 4 3 | wc -l
./push_swap 2 1 3 0 4 | wc -l
./push_swap 2 1 3 4 0 | wc -l
./push_swap 2 1 4 0 3 | wc -l
./push_swap 2 1 4 3 0 | wc -l
./push_swap 2 3 0 1 4 | wc -l
./push_swap 2 3 0 4 1 | wc -l
./push_swap 2 3 1 0 4 | wc -l
./push_swap 2 3 1 4 0 | wc -l
./push_swap 2 3 4 0 1 | wc -l
./push_swap 2 3 4 1 0 | wc -l
./push_swap 2 4 0 1 3 | wc -l
./push_swap 2 4 0 3 1 | wc -l
./push_swap 2 4 1 0 3 | wc -l
./push_swap 2 4 1 3 0 | wc -l
./push_swap 2 4 3 0 1 | wc -l
./push_swap 2 4 3 1 0 | wc -l
./push_swap 3 0 1 2 4 | wc -l
./push_swap 3 0 1 4 2 | wc -l
./push_swap 3 0 2 1 4 | wc -l
./push_swap 3 0 2 4 1 | wc -l
./push_swap 3 0 4 1 2 | wc -l
./push_swap 3 0 4 2 1 | wc -l
./push_swap 3 1 0 2 4 | wc -l
./push_swap 3 1 0 4 2 | wc -l
./push_swap 3 1 2 0 4 | wc -l
./push_swap 3 1 2 4 0 | wc -l
./push_swap 3 1 4 0 2 | wc -l
./push_swap 3 1 4 2 0 | wc -l
./push_swap 3 2 0 1 4 | wc -l
./push_swap 3 2 0 4 1 | wc -l
./push_swap 3 2 1 0 4 | wc -l
./push_swap 3 2 1 4 0 | wc -l
./push_swap 3 2 4 0 1 | wc -l
./push_swap 3 2 4 1 0 | wc -l
./push_swap 3 4 0 1 2 | wc -l
./push_swap 3 4 0 2 1 | wc -l
./push_swap 3 4 1 0 2 | wc -l
./push_swap 3 4 1 2 0 | wc -l
./push_swap 3 4 2 0 1 | wc -l
./push_swap 3 4 2 1 0 | wc -l
./push_swap 4 0 1 2 3 | wc -l
./push_swap 4 0 1 3 2 | wc -l
./push_swap 4 0 2 1 3 | wc -l
./push_swap 4 0 2 3 1 | wc -l
./push_swap 4 0 3 1 2 | wc -l
./push_swap 4 0 3 2 1 | wc -l
./push_swap 4 1 0 2 3 | wc -l
./push_swap 4 1 0 3 2 | wc -l
./push_swap 4 1 2 0 3 | wc -l
./push_swap 4 1 2 3 0 | wc -l
./push_swap 4 1 3 0 2 | wc -l
./push_swap 4 1 3 2 0 | wc -l
./push_swap 4 2 0 1 3 | wc -l
./push_swap 4 2 0 3 1 | wc -l
./push_swap 4 2 1 0 3 | wc -l
./push_swap 4 2 1 3 0 | wc -l
./push_swap 4 2 3 0 1 | wc -l
./push_swap 4 2 3 1 0 | wc -l
./push_swap 4 3 0 1 2 | wc -l
./push_swap 4 3 0 2 1 | wc -l
./push_swap 4 3 1 0 2 | wc -l
./push_swap 4 3 1 2 0 | wc -l
./push_swap 4 3 2 0 1 | wc -l
./push_swap 4 3 2 1 0 | wc -l
