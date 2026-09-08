#!/bin/bash

for n in 100 200 400 800 1600
do
	ARG=$(seq 1 $n | shuf | tr '\n' ' ')
	OPS=$(./push_swap --medium $ARG | wc -l)

	echo "$n elements -> $OPS operations"
done
