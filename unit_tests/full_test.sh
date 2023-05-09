#!/bin/bash

nrs_to_sort=100

# reverse ordered numbers
reverse_inputs=`for (( j=0; j<$nrs_to_sort; j++ )); do echo "$j"; done | sort -rn`
ARG=$reverse_inputs; ../push_swap $ARG | ../checker_Mac $ARG

# random numbers
random_inputs=`for (( j=0; j<$nrs_to_sort; j++ )); do echo "$j"; done | sort -R`
ARG=$random_inputs; ../push_swap $ARG | ../checker_Mac $ARG

# ordered numbers
ordered_inputs=`for (( j=0; j<$nrs_to_sort; j++ )); do echo "$j"; done`
ARG=$ordered_inputs; ../push_swap $ARG | ../checker_Mac $ARG
