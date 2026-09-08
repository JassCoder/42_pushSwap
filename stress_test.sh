#!/bin/bash

for strategy in simple medium complex adaptive
do
	echo "Testing $strategy"

	for i in $(seq 1 100)
	do
		ARG=$(seq -10000 10000 | shuf -n 100 | tr '\n' ' ')

		if [ -z "$ARG" ]; then
			echo "ERROR: failed to generate arguments"
			exit 1
		fi

		RESULT=$(./push_swap --$strategy $ARG | ./local_checker.sh $ARG)

		if [ "$RESULT" != "OK" ]; then
			echo "FAIL --$strategy test $i"
			echo "Checker: $RESULT"
			echo "Arguments:"
			echo "$ARG"
			exit 1
		fi
	done

	echo "PASS --$strategy"
done

echo "ALL RANDOM TESTS PASSED"