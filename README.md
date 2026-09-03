_This project has been created as part of the 42 curriculum by jsingh, mszkudla._

# Push_swap

## Description

**Push_swap** is an algorithmic project from the 42 curriculum.

The goal of the project is to sort a sequence of integers using two stacks,
`A` and `B`, while generating a sequence of instructions from a restricted
set of stack operations.

At the beginning of the program:

- Stack `A` contains all input integers.
- Stack `B` is empty.

The objective is to finish with Stack `A` sorted in ascending order while
using valid Push_swap operations.

This version of Push_swap implements multiple sorting strategies with
different theoretical complexity classes:

- **Simple:** O(n²)
- **Medium:** O(n√n)
- **Complex:** O(n log n)
- **Adaptive:** automatically selects a strategy according to the disorder
  of the original input.

The project also includes an optional benchmark mode that reports information
about the selected strategy and generated operations.

---

## Features

- Integer argument parsing
- Quoted and unquoted input support
- Duplicate detection
- Integer overflow and underflow detection
- Invalid input detection
- Two-stack implementation using linked lists
- All 11 Push_swap operations
- Operation counting
- Input disorder calculation
- Value normalization using indexes
- Three sorting algorithms
- Adaptive strategy selection
- Benchmark mode
- Error handling
- Memory cleanup

---

## Instructions

### Compilation

Clone the repository and compile the project:

```bash
git clone <repository-url>
cd 42_pushSwap
make
```

The compilation creates:

```text
push_swap
```

Other available Makefile rules are:

```bash
make
make clean
make fclean
make re
```

### Basic Usage

Run the program followed by a sequence of integers:

```bash
./push_swap 4 67 3 87 23
```

The program prints the operations required to sort Stack `A`.

Arguments may also be supplied as a quoted string:

```bash
./push_swap "4 67 3 87 23"
```

Mixed argument groups are also supported:

```bash
./push_swap 5 "8 -3" 10
```

---

## Strategy Flags

### Simple

```bash
./push_swap --simple 5 4 3 2 1
```

Forces the **O(n²)** sorting strategy.

### Medium

```bash
./push_swap --medium 5 4 3 2 1
```

Forces the **O(n√n)** chunk-based strategy.

### Complex

```bash
./push_swap --complex 5 4 3 2 1
```

Forces the **O(n log n)** radix-based strategy.

### Adaptive

```bash
./push_swap --adaptive 5 4 3 2 1
```

Selects a strategy according to the disorder of the original input.

Adaptive is the default strategy, therefore:

```bash
./push_swap 5 4 3 2 1
```

is equivalent to requesting adaptive strategy selection.

---

## Allowed Operations

The program can generate the following 11 operations:

| Operation | Description                            |
| --------- | -------------------------------------- |
| `sa`      | Swap the first two elements of Stack A |
| `sb`      | Swap the first two elements of Stack B |
| `ss`      | Execute `sa` and `sb` simultaneously   |
| `pa`      | Push the first element of B onto A     |
| `pb`      | Push the first element of A onto B     |
| `ra`      | Rotate Stack A upwards                 |
| `rb`      | Rotate Stack B upwards                 |
| `rr`      | Execute `ra` and `rb` simultaneously   |
| `rra`     | Reverse rotate Stack A                 |
| `rrb`     | Reverse rotate Stack B                 |
| `rrr`     | Execute `rra` and `rrb` simultaneously |

---

# Algorithms

The project implements three sorting strategies representing different
complexity classes.

## Simple Strategy: Minimum Extraction

**Complexity class:** O(n²)

The Simple strategy uses a minimum-extraction approach similar to selection
sort.

For each iteration:

1. Search Stack `A` for its minimum element.
2. Determine the position of that element.
3. Choose the shorter rotation direction.
4. Use `ra` if the minimum is closer to the top.
5. Use `rra` if the minimum is closer to the bottom.
6. Push the minimum from A to B using `pb`.
7. Repeat until A is empty.
8. Push all elements from B back to A using `pa`.

Using the shorter rotation direction reduces the generated operation count
while keeping the algorithm in the O(n²) complexity class.

### Why this algorithm?

Minimum extraction is simple to understand and provides a clear baseline
against which the more advanced strategies can be compared.

It also directly demonstrates the cost of repeatedly searching for an
element in a linked stack.

---

## Medium Strategy: Chunk-Based Sorting

**Complexity class:** O(n√n)

The Medium strategy uses chunk-based sorting.

Before sorting, every value is assigned a normalized index according to its
position in sorted order.

For example:

```text
Values:   50  -3  20   8
Indexes:   3   0   2   1
```

The algorithm then:

1. Calculates a chunk size approximately equal to √n.
2. Divides the index range into chunks.
3. Scans Stack A for elements belonging to the active chunk.
4. Pushes matching elements to Stack B.
5. Continues until all elements have been transferred.
6. Finds the maximum indexed element in Stack B.
7. Uses `rb` or `rrb`, depending on which direction is shorter.
8. Pushes the maximum back to Stack A using `pa`.
9. Repeats until B is empty.

### Why this algorithm?

Chunking provides a useful middle ground between the simple quadratic
strategy and radix sorting.

Instead of treating the entire input identically, it groups normalized
values into ranges of approximately √n elements.

This reduces unnecessary stack traversal and produces substantially fewer
operations than the Simple strategy on larger inputs.

---

## Complex Strategy: LSD Binary Radix Sort

**Complexity class:** O(n log n)

The Complex strategy uses an adaptation of **LSD binary radix sort**.

Because Push_swap accepts arbitrary signed integers, the original values are
first converted into normalized indexes ranging from:

```text
0 ... n - 1
```

For example:

```text
Values:   50  -3  20   8
Indexes:   3   0   2   1
```

The algorithm processes these indexes one binary bit at a time, starting
with the least significant bit.

For every element:

```text
current bit = 0  ->  pb
current bit = 1  ->  ra
```

After every bit pass, all elements in Stack B are returned to Stack A using
`pa`.

The process repeats for each significant bit required to represent the
largest index.

### Why this algorithm?

Binary radix sort maps naturally to Push_swap operations.

The two stacks can represent the two possible states of a binary digit,
while `pb`, `pa`, and `ra` allow elements to be partitioned without requiring
random access.

It also scales significantly better than the Simple strategy as the number
of elements increases.

---

# Adaptive Strategy

Adaptive mode analyzes the input before sorting and chooses one of the three
algorithms.

The disorder value must be calculated **before any sorting operation is
performed**.

The selection rules are:

```text
Disorder < 20%
    -> Simple

20% <= Disorder < 50%
    -> Medium

Disorder >= 50%
    -> Complex
```

This allows relatively ordered inputs to use a simpler strategy while more
disordered inputs can use algorithms designed to scale better.

---

## Disorder Calculation

Disorder measures how far the original input is from sorted order.

It is calculated using inversions.

For every pair of elements `(i, j)` where:

```text
i < j
```

the pair is considered an inversion when:

```text
A[i] > A[j]
```

The total number of possible pairs is:

```text
n * (n - 1) / 2
```

The disorder ratio is:

```text
number of inversions / total number of pairs
```

A completely sorted stack therefore has a disorder close to `0`, while a
reverse-sorted stack approaches `1`.

---

# Benchmark Mode

Benchmark mode can be enabled using:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Sorting operations remain on **stdout**, while benchmark information is
written to **stderr**.

The benchmark reports:

- Original disorder percentage
- Strategy used
- Theoretical complexity
- Total number of operations
- Number of times each Push_swap operation was executed

The following operations are counted individually:

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

This separation allows the operation stream to continue being piped into a
checker while benchmark information is stored separately.

Example:

```bash
./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
```

Benchmark information can then be inspected with:

```bash
cat bench.txt
```

---

# Performance

The project subject defines the following performance targets for random
inputs:

|  Input Size |    Pass |   Good | Excellent |
| ----------: | ------: | -----: | --------: |
| 100 numbers |  < 2000 | < 1500 |     < 700 |
| 500 numbers | < 12000 | < 8000 |    < 5500 |

Performance varies depending on the selected strategy and the disorder of
the input.

The Simple strategy exists primarily as the required O(n²) baseline, while
Medium and Complex are designed to provide better scaling for larger inputs.

---

# Error Handling

Invalid input causes the program to print:

```text
Error
```

to stderr.

Examples of invalid input include:

```bash
./push_swap 1 2 2
./push_swap 1 abc 3
./push_swap 1 2.5 3
./push_swap 2147483648
./push_swap -2147483649
./push_swap --unknown 3 2 1
```

The program accepts values within the signed 32-bit integer range:

```text
-2147483648 ... 2147483647
```

Calling the program without numbers produces no output:

```bash
./push_swap
```

---

# Project Structure

```text
.
├── Makefile
├── main.c
├── push_swap.h
│
├── analysis/
│   ├── assign_index.c
│   ├── disorder.c
│   └── is_sorted.c
│
├── benchmark/
│   ├── operation_count.c
│   └── report.c
│
├── operations/
│   ├── push.c
│   ├── reverse_rotate.c
│   ├── rotate.c
│   └── swap.c
│
├── parsing/
│   ├── ft_split.c
│   ├── ft_utils_1.c
│   ├── parse_args.c
│   ├── parse_flags.c
│   ├── parse_free.c
│   ├── parse_utils.c
│   └── validate.c
│
├── sorting/
│   ├── adaptive.c
│   ├── complex.c
│   ├── medium.c
│   └── simple.c
│
├── stack/
│   ├── stack_free.c
│   ├── stack_init.c
│   └── stack_utils.c
│
└── ft_printf/
```

---

# Technical Choices

## Singly Linked Lists

Stacks A and B are implemented using singly linked lists.

Each node stores:

```c
value
index
next
```

Each stack stores:

```c
top
bottom
size
```

Keeping both `top` and `bottom` pointers makes operations such as rotation
more convenient while preserving a relatively simple data structure.

## Index Normalization

The Medium and Complex strategies work with indexes rather than directly
with the original integer values.

The smallest value receives index `0`, the next smallest receives index `1`,
and so on.

This preserves ordering while converting arbitrary signed integers into a
compact range suitable for chunking and binary radix sorting.

---

# Resources

## References

Resources used while studying the concepts required for this project include:

- The official **Push_swap subject** provided by 42.
- 42 documentation and project evaluation requirements.
- C language documentation and manual pages.
- `write(2)` documentation.
- General references on linked lists, stacks, algorithmic complexity,
  selection sort, chunk-based sorting, and radix sort.

Useful manual pages:

```bash
man 2 write
man malloc
man free
```

## AI Usage

AI tools were used as a learning and development aid during this project.

AI assistance was used for:

- explaining linked-list and stack manipulation concepts;
- discussing the implementation of Push_swap operations;
- explaining algorithmic complexity;
- comparing possible sorting strategies;
- understanding minimum-extraction sorting;
- understanding chunk-based sorting;
- understanding binary radix sorting and bitwise operations;
- reasoning about disorder and inversion counting;
- reviewing argument-parsing edge cases;
- interpreting compiler and linker errors;
- reviewing operation-counting logic;
- designing testing and benchmarking commands;
- discussing project organization;
- reviewing README requirements.

AI-generated suggestions were reviewed, adapted, implemented, and tested as
part of the development process. The author remains responsible for
understanding and being able to explain the submitted implementation.
