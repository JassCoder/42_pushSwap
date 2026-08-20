# Push_swap — 8 Crucial Stages

For this exact **Push_swap subject**, the mandatory project can be divided into **8 crucial stages**.

```text
1. ARGUMENTS / FLAGS
        ↓
2. VALIDATION + STACK CREATION
        ↓
3. 11 STACK OPERATIONS
        ↓
4. DISORDER CALCULATION
        ↓
5. SORTING STRATEGIES
        ↓
6. ADAPTIVE STRATEGY
        ↓
7. BENCHMARK / OPERATION TRACKING
        ↓
8. TESTING + NORM + README
```

---

## 1. Parsing + Flags

The program must understand inputs such as:

```bash
./push_swap --simple 5 8 -3 10
./push_swap --bench --adaptive "5 8 -3 10"
```

Supported strategy flags:

```text
--simple
--medium
--complex
--adaptive
```

Additional flag:

```text
--bench
```

The parser needs to distinguish **flags** from **numbers**.

### Main Goal

```text
argv
 │
 ├── flags ──────→ configuration
 │
 └── numbers ────→ validation
```

---

## 2. Validation + Build Stack A

This is the foundation of the project.

```text
argv
 ↓
split strings
 ↓
validate integer syntax
 ↓
ft_atol
 ↓
INT_MIN <= value <= INT_MAX
 ↓
duplicate check
 ↓
append_node()
 ↓
Stack A
```

### Things to Validate

The parser must reject:

- Non-integer values
- Integer overflow
- Integer underflow
- Duplicate numbers
- Invalid flags
- Invalid or empty number arguments

Examples:

```bash
./push_swap 1 2 hello 4
```

```text
Error
```

```bash
./push_swap 1 2 2 4
```

```text
Error
```

```bash
./push_swap 2147483648
```

```text
Error
```

Valid negative numbers are allowed:

```bash
./push_swap -5 10 -20 3
```

Errors must print:

```text
Error\n
```

to **stderr**.

---

## 3. Implement the 11 Stack Operations

Push_swap sorting algorithms cannot directly rearrange the linked list however they want.

They must sort using the allowed Push_swap operations.

### Swap

```text
sa
sb
ss
```

- `sa` — swap first two elements of Stack A
- `sb` — swap first two elements of Stack B
- `ss` — perform `sa` and `sb`

### Push

```text
pa
pb
```

- `pa` — move top of B → A
- `pb` — move top of A → B

### Rotate

```text
ra
rb
rr
```

- `ra` — first element of A becomes last
- `rb` — first element of B becomes last
- `rr` — perform `ra` and `rb`

### Reverse Rotate

```text
rra
rrb
rrr
```

- `rra` — last element of A becomes first
- `rrb` — last element of B becomes first
- `rrr` — perform `rra` and `rrb`

Overview:

```text
SWAP          PUSH        ROTATE       REVERSE
sa            pa          ra           rra
sb            pb          rb           rrb
ss                        rr           rrr
```

Each operation must:

1. Modify the correct stack(s).
2. Preserve linked-list integrity.
3. Print the correct operation followed by `\n`.

---

## 4. Disorder Calculation

This Push_swap version requires a **disorder metric**.

Disorder represents how far Stack A is from being sorted.

```text
0.0 = completely sorted
1.0 = completely reversed
```

Example:

```text
A = [1, 2, 3, 4]

disorder = 0.0
```

While:

```text
A = [4, 3, 2, 1]

disorder = 1.0
```

### Idea

Compare every possible pair:

```text
for each i
    for each j after i

        if a[i] > a[j]
            mistakes++
```

Also count:

```text
total_pairs++
```

Finally:

```text
disorder = mistakes / total_pairs
```

Conceptually:

```text
          mistakes
disorder = ───────────
          total_pairs
```

The disorder must be calculated **before performing sorting moves**.

---

## 5. Three Required Sorting Strategies

The project requires three explicit algorithm complexity classes.

### Simple

```text
--simple

O(n²)
```

Possible approaches:

- Selection sort adaptation
- Insertion sort adaptation
- Bubble sort adaptation
- Min/max extraction

Example idea:

```text
find smallest
      ↓
move smallest to top
      ↓
pb
      ↓
repeat
      ↓
pa everything back
```

---

### Medium

```text
--medium

O(n√n)
```

A practical choice is **chunk sorting**.

Concept:

```text
Sorted indexes

0 1 2 3 4 5 6 7 8 9 10 ...
└─────┘
chunk 1

      └─────┘
      chunk 2

            └─────┘
            chunk 3
```

Instead of handling the entire stack simultaneously, process ranges/chunks.

---

### Complex

```text
--complex

O(n log n)
```

Possible algorithms include:

- Radix sort
- Merge sort adaptation
- Quick sort adaptation
- Heap sort adaptation

A practical choice is:

```text
Radix Sort
```

Usually the values are normalized into indexes first:

```text
Original:

42   -10   100   5

        ↓

Indexes:

2      0     3   1
```

Then the indexes can be processed bit-by-bit using Stack A and Stack B.

---

## 6. Adaptive Strategy

The fourth strategy is:

```text
--adaptive
```

This strategy chooses an internal algorithm based on the **disorder** calculated earlier.

```text
                   disorder
                       │
          ┌────────────┼────────────┐
          ↓            ↓            ↓
        < 0.2       0.2 - 0.5      >= 0.5
          │            │            │
          ↓            ↓            ↓
       SIMPLE        MEDIUM        COMPLEX
        O(n²)        O(n√n)       O(n log n)
```

Conceptually:

```c
if (disorder < 0.2)
    simple_sort();
else if (disorder < 0.5)
    medium_sort();
else
    complex_sort();
```

`--adaptive` is also the **default strategy** when the user doesn't provide a strategy selector.

Therefore:

```bash
./push_swap 5 3 8 1
```

behaves as adaptive strategy selection.

---

## 7. Benchmark / Operation Tracking

The optional:

```bash
--bench
```

enables benchmark information.

Example:

```bash
./push_swap --bench --adaptive 5 3 8 1
```

The program must track:

```text
disorder
strategy
complexity
total operations
```

It must also count each operation:

```text
sa
sb
ss

pa
pb

ra
rb
rr

rra
rrb
rrr
```

A useful structure could conceptually contain:

```text
total_ops

sa_count
sb_count
ss_count

pa_count
pb_count

ra_count
rb_count
rr_count

rra_count
rrb_count
rrr_count
```

Important output separation:

```text
stdout
   │
   └── Push_swap operations

stderr
   │
   └── benchmark information
```

Normal sorting output must therefore remain clean enough to pipe into a checker.

---

## 8. Testing + Norm + README

Once the implementation works, the project still needs final validation.

```text
Correct sorting
      +
Error handling
      +
No memory leaks
      +
No crashes
      +
Norminette
      +
Correct Makefile
      +
README
      +
Performance requirements
```

### Performance Targets

For **100 random numbers**:

```text
< 2000 operations → pass
< 1500 operations → good
< 700 operations  → excellent
```

For **500 random numbers**:

```text
< 12000 operations → pass
< 8000 operations  → good
< 5500 operations  → excellent
```

Testing should cover things such as:

```bash
./push_swap
./push_swap 1
./push_swap 1 2 3
./push_swap 3 2 1
./push_swap -1 -5 10 20
./push_swap "5 2 8 1"
./push_swap 1 2 2
./push_swap hello
./push_swap 2147483648
./push_swap -2147483649
```

Also test every strategy:

```bash
./push_swap --simple ...
./push_swap --medium ...
./push_swap --complex ...
./push_swap --adaptive ...
./push_swap --bench ...
```

---

# Complete Push_swap Pipeline

```text
main()
 │
 ↓
parse flags
 │
 ↓
parse arguments
 │
 ↓
validate numbers
 │
 ↓
create Stack A
 │
 ↓
calculate disorder
 │
 ↓
select strategy
 │
 ├── --simple ─────→ Simple Sort
 │
 ├── --medium ─────→ Chunk Sort
 │
 ├── --complex ────→ Radix Sort
 │
 └── --adaptive
         │
         ↓
     check disorder
         │
    ┌────┼────┐
    ↓    ↓    ↓
 Simple Medium Complex
    │    │    │
    └────┴────┘
         │
         ↓
 execute operations
         │
         ↓
   Stack A sorted
         │
         ↓
 benchmark if --bench
         │
         ↓
 free all memory
         │
         ↓
        exit
```

---

# Current Project Status

```text
1. Parsing / flags          ███████░░░
2. Validation / Stack A     ██████░░░░
3. 11 operations            ██████████
4. Disorder                 ░░░░░░░░░░
5. Sorting algorithms       ██░░░░░░░░
6. Adaptive                 ░░░░░░░░░░
7. Benchmark                ░░░░░░░░░░
8. Final testing            ░░░░░░░░░░
```

---

# Immediate Development Order

Do **not** jump directly into Radix yet.

Finish the project in this order:

```text
parse_args()
      ↓
flag validation
      ↓
number validation
      ↓
ft_atol()
      ↓
INT range checking
      ↓
duplicate checking
      ↓
append_node()
      ↓
Stack A complete
      ↓
edge-case testing
      ↓
compute_disorder()
      ↓
simple algorithm
      ↓
medium algorithm
      ↓
complex algorithm
      ↓
adaptive algorithm
      ↓
benchmark
      ↓
full testing
```

## Current Priority

```text
┌─────────────────────────────────┐
│          CURRENT TARGET         │
│                                 │
│  parse_args()                   │
│       ↓                         │
│  validation                     │
│       ↓                         │
│  Stack A                        │
│       ↓                         │
│  edge-case tests                │
└─────────────────────────────────┘
```

Finish **Stages 1 and 2 completely before moving deeper into sorting algorithms**.