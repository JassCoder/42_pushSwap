*This project has been created as part of the 42 curriculum by jsingh, mszkudla.*

# Push_swap

## Description

**Push_swap** is an algorithmic project from the 42 curriculum.

The goal is to sort a sequence of unique signed integers using two stacks, `A` and `B`, and only the allowed Push_swap operations. Stack `A` starts with the input values and Stack `B` starts empty. The program must finish with Stack `A` sorted in ascending order while generating a valid sequence of operations.

This implementation supports four strategies:

- **Simple**: `O(n²)`
- **Medium**: `O(n√n)`
- **Complex**: `O(n log n)`
- **Adaptive**: chooses one of the three strategies from the initial disorder value

Adaptive mode is the default.

The project also implements argument and flag parsing, integer validation, duplicate detection, linked-list stacks, all 11 operations, disorder calculation, index normalization, benchmark mode, operation counting, a bonus checker, and local correctness/performance tests.

## Instructions

### Compilation

```bash
make
```

This creates `push_swap`.

Available mandatory rules:

```bash
make
make clean
make fclean
make re
```

Compile the bonus checker with:

```bash
make bonus
```

This creates `checker`.

### Basic usage

```bash
./push_swap 4 67 3 87 23
```

Quoted and mixed argument groups are supported:

```bash
./push_swap "4 67 3 87 23"
./push_swap 5 "8 -3" 10
```

If the input is already sorted, no operations are printed. If no arguments are provided, the program prints nothing.

Invalid input prints `Error` followed by a newline to `stderr`.

### Strategy flags

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Without a strategy flag, Adaptive is used.

### Benchmark mode

```bash
./push_swap --bench --adaptive 5 4 3 2 1
```

Sorting instructions stay on `stdout`. Benchmark information is written to `stderr`.

Example:

```bash
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG 2>bench.txt | ./checker $ARG
cat bench.txt
```

The benchmark reports:

- initial disorder percentage;
- selected strategy;
- theoretical complexity;
- total operation count;
- counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

## Allowed Operations

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of A |
| `sb` | Swap the first two elements of B |
| `ss` | Execute `sa` and `sb` |
| `pa` | Push the first element of B onto A |
| `pb` | Push the first element of A onto B |
| `ra` | Rotate A |
| `rb` | Rotate B |
| `rr` | Execute `ra` and `rb` |
| `rra` | Reverse rotate A |
| `rrb` | Reverse rotate B |
| `rrr` | Execute `rra` and `rrb` |

## Algorithms

### Small-input optimization

Inputs of up to five elements use dedicated small sorting logic to reduce operation count while preserving the selected strategy's asymptotic class.

### Simple Strategy

**Complexity: `O(n²)`**

The Simple strategy uses minimum extraction:

1. find the minimum value in A;
2. determine its position;
3. rotate with `ra` or `rra`, choosing the shorter direction;
4. push the minimum to B with `pb`;
5. repeat until A is empty;
6. push all values back to A with `pa`.

The repeated search for the next minimum gives the strategy its quadratic behavior.

### Medium Strategy

**Complexity target: `O(n√n)`**

The Medium strategy uses normalized indexes and chunk-based partitioning.

Each value receives an index based on its sorted position. The algorithm uses a chunk size close to `√n`, pushes values from the active chunk to B, then reconstructs A by repeatedly moving the maximum indexed value from B back to A.

### Complex Strategy

**Complexity: `O(n log n)`**

The Complex strategy uses LSD binary radix sorting on normalized indexes from `0` to `n - 1`.

For each bit:

```text
bit = 0 -> pb
bit = 1 -> ra
```

The implementation also processes B using the next significant bit. Since the number of required bits is proportional to `log n` and each pass is linear, the generated operation model is `O(n log n)`.

### Adaptive Strategy

Adaptive mode calculates disorder **before any sorting operation**.

```text
disorder < 0.20
    -> Simple

0.20 <= disorder < 0.50
    -> Medium

disorder >= 0.50
    -> Complex
```

These thresholds follow the required disorder regimes.

## Disorder Calculation

Disorder is based on inversions.

For every pair `(i, j)` where `i < j`, an inversion exists when `A[i] > A[j]`.

```text
total_pairs = n * (n - 1) / 2
disorder = inversions / total_pairs
```

A sorted input has disorder `0.00%`. A reverse-sorted input has disorder `100.00%`.

## Data Structures

The project uses singly linked lists.

Each node stores:

```c
int             value;
int             index;
struct s_node   *next;
```

Each stack stores:

```c
t_node  *top;
t_node  *bottom;
int     size;
```

## Project Structure

```text
.
├── Makefile
├── README.md
├── main.c
├── push_swap.h
├── full_project_check.sh
├── mandatory_check.sh
├── local_checker.sh
├── stress_test.sh
├── medium_complexity.sh
│
├── analysis/
│   ├── assign_index.c
│   ├── disorder.c
│   └── is_sorted.c
│
├── benchmark/
│   ├── operation_count.c
│   ├── report.c
│   └── report_utils.c
│
├── bonus/
│   ├── checker_bonus.c
│   ├── checker_execute_bonus.c
│   ├── checker_push_bonus.c
│   ├── checker_read_bonus.c
│   ├── checker_reverse_bonus.c
│   ├── checker_rotate_bonus.c
│   ├── checker_swap_bonus.c
│   └── push_swap_bonus.h
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
│   ├── simple.c
│   └── small.c
│
└── stack/
    ├── stack_free.c
    ├── stack_init.c
    └── stack_utils.c
```

## Performance Targets

| Input | Pass | Good | Excellent |
|---:|---:|---:|---:|
| 100 numbers | `< 2000` | `< 1500` | `< 700` |
| 500 numbers | `< 12000` | `< 8000` | `< 5500` |

## Contributions

This project was developed by exactly two learners. Responsibilities were divided during implementation, but both learners reviewed the integrated project and are responsible for understanding and defending the complete codebase.

### jsingh

Primary responsibilities:

- `main.c` and overall program flow;
- argument parsing;
- flag parsing;
- input validation and error checking;
- duplicate and integer-range validation;
- Complex `O(n log n)` radix strategy;
- Adaptive strategy and disorder-based strategy selection;
- benchmark setup and benchmark data structures;
- operation-count integration added to the operation layer;
- benchmark counting logic;
- integration between parsing, analysis, sorting and benchmark flow;
- automated correctness and performance testing.

Main related areas:

```text
main.c
parsing/
sorting/complex.c
sorting/adaptive.c
analysis/disorder.c
analysis/assign_index.c
benchmark/operation_count.c
```

### mszkudla

Primary responsibilities:

- stack initialization and stack functionality;
- linked-list stack utilities and cleanup;
- implementation of the Push_swap operations;
- Simple `O(n²)` strategy;
- Medium `O(n√n)` chunk strategy;
- small-input sorting functionality;
- benchmark printing when `--bench` is requested;
- benchmark report formatting and output helpers.

Main related areas:

```text
stack/
operations/
sorting/simple.c
sorting/medium.c
sorting/small.c
benchmark/report.c
benchmark/report_utils.c
```

### Shared responsibilities

The remaining scope was handled collaboratively:

- `is_sorted` and final analysis integration;
- bonus checker integration and verification;
- Makefile integration;
- strategy interoperability;
- stdout/stderr verification;
- Norminette fixes;
- Valgrind and memory testing;
- random correctness testing;
- performance testing;
- README and defense preparation;
- reviewing each other's code so both learners can explain the entire project.

The contribution split describes primary implementation ownership only. Both learners are responsible for the full project during the defense.

## Testing

The repository contains local scripts for compilation, correctness, strategy, checker, benchmark, performance, Norminette, and Valgrind checks.

Typical usage:

```bash
./full_project_check.sh
```

Random correctness example:

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '
' ' ')
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
```

## Resources

### References

Resources used during the project include:

- the official 42 **Push_swap** subject;
- the Push_swap peer-evaluation requirements;
- C manual pages and standard C references;
- `write(2)`, `malloc`, and `free` documentation;
- linked-list and stack references;
- algorithmic complexity references;
- minimum-extraction / selection-sort references;
- chunk-based sorting references;
- binary radix sort and bitwise-operation references.

Useful manual pages:

```bash
man 2 write
man malloc
man free
```

### AI Usage

AI tools were used as a learning, debugging, review and testing aid.

AI assistance was used for:

- explaining linked-list and stack behavior;
- visualizing pointer changes in operations;
- reviewing parsing and validation edge cases;
- explaining integer range and duplicate validation;
- explaining complexity notation;
- discussing Simple, Medium and Complex strategies;
- explaining chunk-based sorting;
- explaining binary radix sorting and bit operations;
- reasoning about disorder and inversions;
- reviewing benchmark counting and stdout/stderr separation;
- reviewing Makefile and Norminette issues;
- designing test cases and local test scripts;
- reviewing operation counts and evaluation requirements;
- reviewing README structure and defense preparation.

AI-generated suggestions were reviewed, adapted, tested and integrated by the learners. Both learners remain responsible for understanding and defending the submitted implementation.