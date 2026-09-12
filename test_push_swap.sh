#!/bin/bash

PS="./push_swap"
CHECKER="./checker_linux"

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

section()
{
	echo
	echo "===== $1 ====="
}

check_sorted()
{
	ARG="$1"
	COUNT=$($PS $ARG | wc -l)
	RESULT=$($PS $ARG | $CHECKER $ARG)

	if [ "$RESULT" = "OK" ]; then
		pass "$2 -> $COUNT operations"
	else
		fail "$2 -> checker returned $RESULT"
	fi
}

check_error()
{
	NAME="$1"
	shift

	OUT=$($PS "$@" 2>&1 >/dev/null)

	if [ "$OUT" = "Error" ]; then
		pass "$NAME"
	else
		fail "$NAME"
	fi
}

section "1. BUILD"

make fclean >/dev/null 2>&1
make >/dev/null 2>&1

if [ $? -eq 0 ] && [ -x "$PS" ]; then
	pass "make"
else
	fail "make"
	exit 1
fi

if [ ! -x "$CHECKER" ]; then
	echo -e "${yellow}[INFO] checker_linux not found.${reset}"
	echo "Place the official checker_linux beside this script:"
	echo "chmod +x checker_linux"
	exit 1
fi

section "2. NO ARGUMENTS"

OUTPUT=$($PS)

if [ -z "$OUTPUT" ]; then
	pass "no arguments -> no output"
else
	fail "no arguments produced output"
fi

section "3. ERROR MANAGEMENT"

check_error "duplicate" 1 2 2
check_error "non-numeric" 1 abc 3
check_error "decimal" 1 2.5 3
check_error "INT_MAX overflow" 2147483648
check_error "INT_MIN overflow" -2147483649
check_error "plus only" "+"
check_error "minus only" "-"
check_error "unknown flag" --hello 3 2 1
check_error "empty argument" ""

section "4. ALREADY SORTED"

for ARG in \
	"42" \
	"2 3" \
	"0 1 2 3" \
	"0 1 2 3 4 5 6 7 8 9"
do
	COUNT=$($PS $ARG | wc -l)

	if [ "$COUNT" -eq 0 ]; then
		pass "sorted: $ARG -> 0 operations"
	else
		fail "sorted: $ARG -> $COUNT operations"
	fi
done

section "5. THREE ELEMENTS"

check_sorted "2 1 0" "2 1 0"
check_sorted "0 2 1" "0 2 1"
check_sorted "1 0 2" "1 0 2"
check_sorted "2 0 1" "2 0 1"
check_sorted "1 2 0" "1 2 0"
check_sorted "0 1 2" "0 1 2"

section "6. FIVE ELEMENTS"

check_sorted "1 5 2 4 3" "1 5 2 4 3"
check_sorted "5 1 4 2 3" "5 1 4 2 3"
check_sorted "3 5 1 4 2" "3 5 1 4 2"

section "7. STRATEGIES"

ARG="5 4 3 2 1"

for STRATEGY in --simple --medium --complex --adaptive
do
	RESULT=$($PS $STRATEGY $ARG | $CHECKER $ARG)

	if [ "$RESULT" = "OK" ]; then
		pass "$STRATEGY"
	else
		fail "$STRATEGY"
	fi
done

RESULT=$($PS $ARG | $CHECKER $ARG)

if [ "$RESULT" = "OK" ]; then
	pass "default adaptive"
else
	fail "default adaptive"
fi

section "8. BENCHMARK"

ARG="5 4 3 2 1"

OPS=$($PS --bench --adaptive $ARG 2>bench.txt)
RESULT=$(printf "%s\n" "$OPS" | $CHECKER $ARG)

if [ "$RESULT" = "OK" ]; then
	pass "benchmark keeps valid operations on stdout"
else
	fail "benchmark operation stream"
fi

for FIELD in \
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
	if grep -q "$FIELD" bench.txt; then
		pass "benchmark contains $FIELD"
	else
		fail "benchmark missing $FIELD"
	fi
done

rm -f bench.txt

section "9. RANDOM 100"

for RUN in 1 2 3 4 5
do
	ARG=$(shuf -i 0-10000 -n 100 | tr '\n' ' ')
	COUNT=$($PS $ARG | wc -l)
	RESULT=$($PS $ARG | $CHECKER $ARG)

	if [ "$RESULT" != "OK" ]; then
		fail "100 numbers run $RUN -> sorting failed"
	elif [ "$COUNT" -lt 700 ]; then
		pass "100 run $RUN EXCELLENT -> $COUNT"
	elif [ "$COUNT" -lt 1500 ]; then
		pass "100 run $RUN GOOD -> $COUNT"
	elif [ "$COUNT" -lt 2000 ]; then
		pass "100 run $RUN PASS -> $COUNT"
	else
		fail "100 run $RUN -> $COUNT operations"
	fi
done

section "10. RANDOM 500"

for RUN in 1 2 3
do
	ARG=$(shuf -i 0-20000 -n 500 | tr '\n' ' ')
	COUNT=$($PS $ARG | wc -l)
	RESULT=$($PS $ARG | $CHECKER $ARG)

	if [ "$RESULT" != "OK" ]; then
		fail "500 numbers run $RUN -> sorting failed"
	elif [ "$COUNT" -lt 5500 ]; then
		pass "500 run $RUN EXCELLENT -> $COUNT"
	elif [ "$COUNT" -lt 8000 ]; then
		pass "500 run $RUN GOOD -> $COUNT"
	elif [ "$COUNT" -lt 12000 ]; then
		pass "500 run $RUN PASS -> $COUNT"
	else
		fail "500 run $RUN -> $COUNT operations"
	fi
done

section "11. NORMINETTE"

if command -v norminette >/dev/null 2>&1; then
	if norminette . 2>/dev/null | grep -q "Error!"; then
		fail "Norminette"
	else
		pass "Norminette"
	fi
else
	echo -e "${yellow}[SKIP] norminette not installed${reset}"
fi

section "12. BONUS"

make bonus >/dev/null 2>&1

if [ -x "./checker" ]; then
	pass "make bonus creates checker"

	printf "sa\n" | ./checker 2 1 >/tmp/checker_result

	if grep -q "^OK$" /tmp/checker_result; then
		pass "bonus checker valid operation"
	else
		fail "bonus checker valid operation"
	fi

	rm -f /tmp/checker_result
else
	fail "bonus checker missing"
fi

section "FINAL RESULT"

echo
echo "PASS: $PASS"
echo "FAIL: $FAIL"

if [ "$FAIL" -eq 0 ]; then
	echo -e "${green}ALL TESTS PASSED${reset}"
	exit 0
else
	echo -e "${red}PROJECT HAS FAILURES${reset}"
	exit 1
fi