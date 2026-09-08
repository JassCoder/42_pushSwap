#!/bin/bash

A=("$@")
B=()

sa()
{
	if [ "${#A[@]}" -ge 2 ]; then
		tmp="${A[0]}"
		A[0]="${A[1]}"
		A[1]="$tmp"
	fi
}

sb()
{
	if [ "${#B[@]}" -ge 2 ]; then
		tmp="${B[0]}"
		B[0]="${B[1]}"
		B[1]="$tmp"
	fi
}

pa()
{
	if [ "${#B[@]}" -gt 0 ]; then
		A=("${B[0]}" "${A[@]}")
		B=("${B[@]:1}")
	fi
}

pb()
{
	if [ "${#A[@]}" -gt 0 ]; then
		B=("${A[0]}" "${B[@]}")
		A=("${A[@]:1}")
	fi
}

ra()
{
	if [ "${#A[@]}" -gt 0 ]; then
		first="${A[0]}"
		A=("${A[@]:1}" "$first")
	fi
}

rb()
{
	if [ "${#B[@]}" -gt 0 ]; then
		first="${B[0]}"
		B=("${B[@]:1}" "$first")
	fi
}

rra()
{
	if [ "${#A[@]}" -gt 0 ]; then
		last="${A[$((${#A[@]} - 1))]}"
		A=("$last" "${A[@]:0:$((${#A[@]} - 1))}")
	fi
}

rrb()
{
	if [ "${#B[@]}" -gt 0 ]; then
		last="${B[$((${#B[@]} - 1))]}"
		B=("$last" "${B[@]:0:$((${#B[@]} - 1))}")
	fi
}

while IFS= read -r op
do
	case "$op" in
		sa) sa ;;
		sb) sb ;;
		ss) sa; sb ;;
		pa) pa ;;
		pb) pb ;;
		ra) ra ;;
		rb) rb ;;
		rr) ra; rb ;;
		rra) rra ;;
		rrb) rrb ;;
		rrr) rra; rrb ;;
		"") ;;
		*)
			echo "Error"
			exit 1
			;;
	esac
done

if [ "${#B[@]}" -ne 0 ]; then
	echo "KO"
	exit 0
fi

for ((i = 0; i < ${#A[@]} - 1; i++))
do
	if [ "${A[$i]}" -gt "${A[$((i + 1))]}" ]; then
		echo "KO"
		exit 0
	fi
done

echo "OK"