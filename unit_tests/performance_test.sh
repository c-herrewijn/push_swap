#!/bin/bash

loops=200
nrs_to_sort=8

total=0;
for (( i=0; i<$loops; i++ ))
	do
		random_inputs=`for (( j=0; j<$nrs_to_sort; j++ )); do echo "$j"; done | sort -R`
		result=$(../push_swap $random_inputs | wc -l | tr -d ' ')
		total=$((total+result))
done

echo "nrs to sort: $nrs_to_sort, average $((total/loops))"
