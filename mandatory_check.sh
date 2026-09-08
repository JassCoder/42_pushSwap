#!/bin/bash

PS="./push_swap"
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
title "1. BUILD"
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
title "2. NO ARGUMENTS"
# --------------------------------------------------

OUTPUT=$($PS 2>&1)

if [ -z "$OUTPUT" ]; then
	pass "No arguments produce no output"
else
	fail "No arguments produced: $OUTPUT"
fi

# --------------------------------------------------
title "3. ALREADY SORTED"
# --------------------------------------------------

OUTPUT=$($PS 1 2 3 4 5)

if [ -z "$OUTPUT" ]; then
	pass "Already sorted input produces no operations"
else
	fail "Already sorted input produced operations"
fi

# --------------------------------------------------
title "4. VALID INPUTS"
# --------------------------------------------------

tests=(
	"3 2 1"
	"-5 0 8 20"
	"2147483647 0 -2147483648"
	"5 8 -3 10"
)

for test in "${tests[@]}"; do
	$PS $test >/dev/null 2>error.tmp
	if [ ! -s error.tmp ]; then
		pass "Valid input: $test"
	else
		fail "Valid input rejected: $test"
	fi
done

rm -f error.tmp

# --------------------------------------------------
title "5. INVALID INPUTS"
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
)

for test in "${invalid[@]}"; do
	$PS $test >/dev/null 2>error.tmp

	if grep -qx "Error" error.tmp; then
		pass "Rejected: $test"
	else
		fail "Did not correctly reject: $test"
	fi
done

rm -f error.tmp

# --------------------------------------------------
title "6. QUOTED INPUT"
# --------------------------------------------------

$PS "5 4 3 2 1" >/dev/null 2>error.tmp

if [ ! -s error.tmp ]; then
	pass "Quoted number group"
else
	fail "Quoted number group"
fi

$PS 5 "8 -3" 10 >/dev/null 2>error.tmp

if [ ! -s error.tmp ]; then
	pass "Mixed quoted/unquoted groups"
else
	fail "Mixed quoted/unquoted groups"
fi

rm -f error.tmp

# --------------------------------------------------
title "7. STRATEGY FLAGS"
# --------------------------------------------------

for strategy in simple medium complex adaptive; do
	$PS --$strategy 5 3 1 4 2 >/dev/null 2>error.tmp

	if [ ! -s error.tmp ]; then
		pass "--$strategy accepted"
	else
		fail "--$strategy failed"
	fi
done

rm -f error.tmp

# --------------------------------------------------
title "8. SMALL INPUT"
# --------------------------------------------------

for strategy in simple medium complex adaptive; do
	$PS --$strategy 2 1 >/dev/null
	if [ $? -eq 0 ]; then
		pass "$strategy handles 2 elements"
	else
		fail "$strategy failed on 2 elements"
	fi

	$PS --$strategy 3 1 2 >/dev/null
	if [ $? -eq 0 ]; then
		pass "$strategy handles 3 elements"
	else
		fail "$strategy failed on 3 elements"
	fi
done

# --------------------------------------------------
title "9. BENCHMARK STDERR"
# --------------------------------------------------

$PS --bench --complex 5 3 1 4 2 \
	>operations.tmp 2>benchmark.tmp

if grep -q "Disorder:" benchmark.tmp; then
	pass "Benchmark contains disorder"
else
	fail "Benchmark missing disorder"
fi

if grep -q "Strategy:" benchmark.tmp; then
	pass "Benchmark contains strategy"
else
	fail "Benchmark missing strategy"
fi

if grep -q "Complexity:" benchmark.tmp; then
	pass "Benchmark contains complexity"
else
	fail "Benchmark missing complexity"
fi

if grep -q "Total operations:" benchmark.tmp; then
	pass "Benchmark contains total operations"
else
	fail "Benchmark missing total operations"
fi

for op in sa sb ss pa pb ra rb rr rra rrb rrr; do
	if grep -q "$op:" benchmark.tmp; then
		pass "Benchmark reports $op"
	else
		fail "Benchmark missing $op"
	fi
done

if grep -q "Disorder:" operations.tmp; then
	fail "Benchmark leaked into stdout"
else
	pass "Benchmark stays out of stdout"
fi

rm -f operations.tmp benchmark.tmp

# --------------------------------------------------
title "10. OFFICIAL CHECKER"
# --------------------------------------------------

if [ -x "./checker_linux" ]; then

	for strategy in simple medium complex adaptive; do

		ARG="4 67 3 87 23"

		RESULT=$($PS --$strategy $ARG | ./checker_linux $ARG)

		if [ "$RESULT" = "OK" ]; then
			pass "$strategy checker test"
		else
			fail "$strategy checker result: $RESULT"
		fi
	done

else
	echo "checker_linux not found - skipping checker tests"
fi

# --------------------------------------------------
title "11. RANDOM CORRECTNESS"
# --------------------------------------------------

if [ -x "./checker_linux" ]; then

	for strategy in simple medium complex adaptive; do

		ok=1

		for i in $(seq 1 20); do

			ARG=$(shuf -i -10000-10000 -n 100 | tr '\n' ' ')

			RESULT=$($PS --$strategy $ARG | ./checker_linux $ARG)

			if [ "$RESULT" != "OK" ]; then
				ok=0
				break
			fi

		done

		if [ $ok -eq 1 ]; then
			pass "$strategy passed 20 random x100 tests"
		else
			fail "$strategy failed random correctness"
		fi

	done

fi

# --------------------------------------------------
title "12. PERFORMANCE"
# --------------------------------------------------

ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
COUNT=$($PS $ARG | wc -l)

echo "Adaptive 100 elements: $COUNT operations"

if [ "$COUNT" -lt 2000 ]; then
	pass "100-element PASS threshold (<2000)"
else
	fail "100-element count = $COUNT"
fi


ARG=$(shuf -i 0-99999 -n 500 | tr '\n' ' ')
COUNT=$($PS $ARG | wc -l)

echo "Adaptive 500 elements: $COUNT operations"

if [ "$COUNT" -lt 12000 ]; then
	pass "500-element PASS threshold (<12000)"
else
	fail "500-element count = $COUNT"
fi

# --------------------------------------------------
title "13. NORMINETTE"
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
title "14. VALGRIND"
# --------------------------------------------------

if command -v valgrind >/dev/null; then

	valgrind --leak-check=full \
		--error-exitcode=42 \
		$PS --adaptive 5 8 -3 10 \
		>/dev/null 2>valgrind.tmp

	if [ $? -eq 42 ]; then
		fail "Valgrind valid-input test"
	else
		pass "Valgrind valid-input test"
	fi

	valgrind --leak-check=full \
		--error-exitcode=42 \
		$PS 1 2 2 \
		>/dev/null 2>valgrind.tmp

	if [ $? -eq 42 ]; then
		fail "Valgrind error-path test"
	else
		pass "Valgrind error-path test"
	fi

	rm -f valgrind.tmp

else
	echo "valgrind not installed - skipped"
fi

# --------------------------------------------------
title "RESULT"
# --------------------------------------------------

echo
echo "PASS: $PASS"
echo "FAIL: $FAIL"

if [ $FAIL -eq 0 ]; then
	echo -e "${green}MANDATORY TEST SUITE PASSED${reset}"
else
	echo -e "${red}MANDATORY IS NOT READY YET${reset}"
fi