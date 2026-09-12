#!/bin/bash

PASS=0
FAIL=0

green="\033[32m"
red="\033[31m"
yellow="\033[33m"
reset="\033[0m"

pass()
{
	echo -e "${green}[PASS]${reset} $1"
	PASS=$((PASS + 1))
}

fail()
{
	echo -e "${red}[FAIL]${reset} $1"
	FAIL=$((FAIL + 1))
}

echo -e "${yellow}===== 42 HEADER CHECK =====${reset}"
echo

while IFS= read -r file
do
	name=$(basename "$file")

	# Count 42 header signature
	count=$(grep -c ":::      ::::::::   " "$file")

	if [ "$count" -eq 0 ]; then
		fail "$file -> MISSING HEADER"
		continue
	fi

	if [ "$count" -gt 1 ]; then
		fail "$file -> DOUBLE HEADER ($count)"
		continue
	fi

	# Check filename inside header
	if ! head -n 12 "$file" | grep -Fq "$name"; then
		fail "$file -> WRONG FILENAME IN HEADER"
		continue
	fi

	# Check header is at beginning of file
	if ! head -n 5 "$file" | grep -q ":::      ::::::::   "; then
		fail "$file -> HEADER NOT AT TOP"
		continue
	fi

	pass "$file"

done < <(find . -type f \( -name "*.c" -o -name "*.h" \) | sort)

echo
echo -e "${yellow}===== RESULT =====${reset}"
echo
echo "PASS: $PASS"
echo "FAIL: $FAIL"

if [ "$FAIL" -eq 0 ]; then
	echo -e "${green}ALL HEADERS PASSED${reset}"
else
	echo -e "${red}HEADER PROBLEMS FOUND${reset}"
fi