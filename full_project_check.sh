#!/bin/bash

PS="./push_swap"
CHECKER="./checker"

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

title()
{
	echo
	echo -e "${yellow}===== $1 =====${reset}"
}

# --------------------------------------------------
title "1. BUILD MANDATORY"
# --------------------------------------------------

make fclean >/dev/null 2>&1

if make >/dev/null 2>&1; then
	pass "make"
else
	fail "make"
	exit 1
fi

if [ -x "$PS" ]; then
	pass "push_swap executable exists"
else
	fail "push_swap executable missing"
fi

# --------------------------------------------------
title "2. BUILD BONUS"
# --------------------------------------------------

if make bonus >/dev/null 2>&1; then
	pass "make bonus"
else
	fail "make bonus"
fi

if [ -x "$CHECKER" ]; then
	pass "checker executable exists"
else
	fail "checker executable missing"
fi

# --------------------------------------------------
title "3. MANDATORY BASIC BEHAVIOR"
# --------------------------------------------------

OUTPUT=$($PS 2>&1)

if [ -z "$OUTPUT" ]; then
	pass "push_swap no args -> no output"
else
	fail "push_swap no args produced output"
fi

OUTPUT=$($PS 1 2 3 4 5)

if [ -z "$OUTPUT" ]; then
	pass "already sorted -> no operations"
else
	fail "already sorted produced operations"
fi

# --------------------------------------------------
title "4. MANDATORY INVALID INPUT"
# --------------------------------------------------

invalid=(
	"1 2 2"
	"1 abc 3"
	"1 2.5 3"
	"2147483648"
	"-2147483649"
	"--banana 3 2 1"
	"+"
	"-"
	"999999999999999999999999999999999"
)

for test in "${invalid[@]}"; do
	$PS $test >/dev/null 2>error.tmp

	if grep -qx "Error" error.tmp; then
		pass "push_swap rejected: $test"
	else
		fail "push_swap failed to reject: $test"
	fi
done

rm -f error.tmp

# --------------------------------------------------
title "5. STRATEGY CORRECTNESS THROUGH BONUS CHECKER"
# --------------------------------------------------

if [ -x "$CHECKER" ]; then

	for strategy in simple medium complex adaptive; do

		ARG="4 67 3 87 23"

		RESULT=$($PS --$strategy $ARG | $CHECKER $ARG)

		if [ "$RESULT" = "OK" ]; then
			pass "$strategy sorts correctly"
		else
			fail "$strategy checker result: $RESULT"
		fi

	done

fi

# --------------------------------------------------
title "6. RANDOM CORRECTNESS"
# --------------------------------------------------

if [ -x "$CHECKER" ]; then

	for strategy in simple medium complex adaptive; do

		ok=1

		for i in $(seq 1 20); do

			ARG=$(seq -10000 10000 | shuf -n 100 | tr '\n' ' ')

			RESULT=$($PS --$strategy $ARG | $CHECKER $ARG)

			if [ "$RESULT" != "OK" ]; then
				ok=0
				break
			fi

		done

		if [ $ok -eq 1 ]; then
			pass "$strategy passed 20 random x100"
		else
			fail "$strategy failed random correctness"
		fi

	done

fi

# --------------------------------------------------
title "7. CHECKER BASIC BEHAVIOR"
# --------------------------------------------------

if [ -x "$CHECKER" ]; then

	OUTPUT=$($CHECKER 2>&1)

	if [ -z "$OUTPUT" ]; then
		pass "checker no args -> no output"
	else
		fail "checker no args produced output"
	fi

	RESULT=$(printf "" | $CHECKER 1 2 3)

	if [ "$RESULT" = "OK" ]; then
		pass "checker sorted input -> OK"
	else
		fail "checker sorted input result: $RESULT"
	fi

	RESULT=$(printf "" | $CHECKER 3 2 1)

	if [ "$RESULT" = "KO" ]; then
		pass "checker unsorted input -> KO"
	else
		fail "checker unsorted input result: $RESULT"
	fi

fi

# --------------------------------------------------
title "8. CHECKER INVALID OPERATIONS"
# --------------------------------------------------

if [ -x "$CHECKER" ]; then

	printf "banana\n" | $CHECKER 3 2 1 \
		>out.tmp 2>err.tmp

	if grep -qx "Error" err.tmp; then
		pass "checker rejects invalid instruction"
	else
		fail "checker invalid instruction handling"
	fi

	rm -f out.tmp err.tmp

fi

# --------------------------------------------------
title "9. CHECKER INVALID ARGUMENTS"
# --------------------------------------------------

checker_invalid=(
	"1 2 2"
	"1 abc 3"
	"2147483648"
	"-2147483649"
	"+"
	"-"
)

for test in "${checker_invalid[@]}"; do

	$CHECKER $test </dev/null >/dev/null 2>error.tmp

	if grep -qx "Error" error.tmp; then
		pass "checker rejected: $test"
	else
		fail "checker failed to reject: $test"
	fi

done

rm -f error.tmp

# --------------------------------------------------
title "10. CHECKER FLAG REJECTION"
# --------------------------------------------------

$CHECKER --simple 3 2 1 </dev/null \
	>/dev/null 2>error.tmp

if grep -qx "Error" error.tmp; then
	pass "checker rejects --simple"
else
	fail "checker incorrectly accepts --simple"
fi

$CHECKER --bench 3 2 1 </dev/null \
	>/dev/null 2>error.tmp

if grep -qx "Error" error.tmp; then
	pass "checker rejects --bench"
else
	fail "checker incorrectly accepts --bench"
fi

rm -f error.tmp

# --------------------------------------------------
title "11. CHECKER OPERATION COVERAGE"
# --------------------------------------------------

ops=(
	"sa"
	"sb"
	"ss"
	"pa"
	"pb"
	"ra"
	"rb"
	"rr"
	"rra"
	"rrb"
	"rrr"
)

for op in "${ops[@]}"; do

	printf "%s\n" "$op" | $CHECKER 2 1 \
		>/dev/null 2>error.tmp

	if [ ! -s error.tmp ]; then
		pass "checker accepts operation: $op"
	else
		fail "checker rejected valid operation: $op"
	fi

done

rm -f error.tmp

# --------------------------------------------------
title "12. BENCHMARK"
# --------------------------------------------------

$PS --bench --adaptive 5 4 3 2 1 \
	>operations.tmp 2>benchmark.tmp

for field in \
	"Disorder:" \
	"Strategy:" \
	"Complexity:" \
	"Total operations:" \
	"sa:" \
	"sb:" \
	"ss:" \
	"pa:" \
	"pb:" \
	"ra:" \
	"rb:" \
	"rr:" \
	"rra:" \
	"rrb:" \
	"rrr:"
do
	if grep -q "$field" benchmark.tmp; then
		pass "benchmark contains $field"
	else
		fail "benchmark missing $field"
	fi
done

if grep -q "Disorder:" operations.tmp; then
	fail "benchmark leaked into stdout"
else
	pass "benchmark stays on stderr"
fi

rm -f operations.tmp benchmark.tmp

# --------------------------------------------------
title "13. PERFORMANCE"
# --------------------------------------------------

ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
COUNT=$($PS $ARG | wc -l)

echo "100 elements: $COUNT operations"

if [ "$COUNT" -lt 2000 ]; then
	pass "100-element threshold"
else
	fail "100-element count = $COUNT"
fi

ARG=$(shuf -i 0-99999 -n 500 | tr '\n' ' ')
COUNT=$($PS $ARG | wc -l)

echo "500 elements: $COUNT operations"

if [ "$COUNT" -lt 12000 ]; then
	pass "500-element threshold"
else
	fail "500-element count = $COUNT"
fi

# --------------------------------------------------
title "14. NORMINETTE"
# --------------------------------------------------

if command -v norminette >/dev/null; then

	if norminette . 2>/dev/null | grep -q "Error"; then
		fail "Norminette errors exist"
	else
		pass "Norminette"
	fi

else
	echo "norminette not installed - skipped"
fi

# --------------------------------------------------
title "15. VALGRIND PUSH_SWAP"
# --------------------------------------------------

if command -v valgrind >/dev/null; then

	valgrind --leak-check=full \
		--error-exitcode=42 \
		$PS --adaptive 5 8 -3 10 \
		>/dev/null 2>valgrind.tmp

	if [ $? -eq 42 ]; then
		fail "push_swap Valgrind"
	else
		pass "push_swap Valgrind"
	fi

	rm -f valgrind.tmp

fi

# --------------------------------------------------
title "16. VALGRIND CHECKER"
# --------------------------------------------------

if command -v valgrind >/dev/null && [ -x "$CHECKER" ]; then

	printf "sa\nrra\n" | \
	valgrind --leak-check=full \
		--error-exitcode=42 \
		$CHECKER 3 2 1 \
		>/dev/null 2>valgrind.tmp

	if [ $? -eq 42 ]; then
		fail "checker Valgrind"
	else
		pass "checker Valgrind"
	fi

	rm -f valgrind.tmp

fi

# --------------------------------------------------
title "RESULT"
# --------------------------------------------------

echo
echo "PASS: $PASS"
echo "FAIL: $FAIL"

if [ $FAIL -eq 0 ]; then
	echo -e "${green}FULL PROJECT TEST SUITE PASSED${reset}"
else
	echo -e "${red}PROJECT STILL HAS FAILURES${reset}"
fi