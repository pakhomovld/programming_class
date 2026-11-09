# Programming Class

A notebook-style repository for programming lessons in Python, Go, and C.
I implement exercises in one language and translate them into another to practice
different ways of thinking and learn from the errors along the way.

## Structure

Exercises are grouped by **topic, then language**. Each Go exercise has its own
directory with a `main.go`, so examples can be built and run independently.

```text
arrays/           # Arrays and dynamic arrays
  c/
  python/
games/            # Snake and tic-tac-toe / game AI
  c/
  python/
linked_lists/     # Linked lists and list sorting
  c/
recursion/        # Recursion exercises
  go/<exercise>/main.go
  python/
sorting/          # Sorting algorithms
  go/<exercise>/main.go
  python/
strings/          # String operations and validation
  c/
  python/
```

## Exercise index

### Arrays

| Exercise | Implementations |
| --- | --- |
| Check whether an array is sorted | [C](arrays/c/check_sorted.c) |
| Dynamic array | [Python](arrays/python/dynamic_array.py) |
| Longest monotonic subarray | [Python](arrays/python/longest_monotonic_subarray.py) |
| Remove an element in place | [Python](arrays/python/remove_element.py) |
| Summary ranges | [Python](arrays/python/summary_ranges.py) |

### Linked lists

| Exercise | Implementations |
| --- | --- |
| Linked list operations and quicksort | [C](linked_lists/c/linked_list.c) |

### Recursion

| Exercise | Implementations |
| --- | --- |
| Addition, multiplication, and array maximum | [Python](recursion/python/addition_of_two.py) |
| Factorial | [Python](recursion/python/factorial.py), [Go](recursion/go/factorial/main.go) |
| Tower of Hanoi | [Python](recursion/python/hanoi.py) |
| Recursive filtering and string partitions | [Python](recursion/python/less_recursive.py) |
| Array multiplication exercise | [Python](recursion/python/multiplication_array.py) |
| Permutations | [Python](recursion/python/permutations.py), [Go](recursion/go/permutations/main.go) |
| String unpacking | [Python](recursion/python/unpack_string.py) |

### Sorting

| Exercise | Implementations |
| --- | --- |
| Bubble sort and gnome sort | [Python](sorting/python/bubble_sort.py), [Go](sorting/go/bubble_sort/main.go) |
| Merge sort | [Go](sorting/go/merge_sort/main.go) |
| Quicksort | [Python](sorting/python/quick_sort.py) |
| Selection sort | [Python](sorting/python/selection_sort.py), [Go](sorting/go/selection_sort/main.go) |

### Strings

| Exercise | Implementations |
| --- | --- |
| String utilities: length, concatenation, case conversion, padding, and more | [C](strings/c/string_utils.c) |
| String compression III | [Python](strings/python/string_compression_3.py) |
| Palindrome validation | [Python](strings/python/valid_palindrome.py) |
| Palindrome validation with one deletion | [Python](strings/python/valid_palindrome_2.py) |
| Parentheses validation | [Python](strings/python/valid_parentheses.py) |

### Games

| Exercise | Implementations |
| --- | --- |
| Snake in the terminal | [C](games/c/snake.c) |
| Tic-tac-toe, game states, and minimax | [Python](games/python/tic_tac_toe.py) |

## Run an example

Run these commands from the repository root.

**Python** — requires Python 3; exercises use the standard library:

```sh
python3 sorting/python/selection_sort.py
```

**Go** — use the version required by [go.mod](go.mod) or newer:

```sh
go run ./sorting/go/selection_sort
go run ./recursion/go/factorial
```

Build all Go examples without producing binaries in the source directories:

```sh
go build ./...
```

**C** — requires a C compiler. Put compiled programs in `build/`, which Git ignores:

```sh
mkdir -p build
cc -std=c11 -Wall -Wextra linked_lists/c/linked_list.c -o build/linked_list
./build/linked_list
```

Snake also requires the ncurses headers and library and runs in a terminal:

```sh
mkdir -p build
cc -std=c11 -Wall -Wextra games/c/snake.c -o build/snake -lncurses
./build/snake
```

## Adding exercises

- Put Python and C files in `<topic>/python/` and `<topic>/c/`.
- Put each Go program in `<topic>/go/<exercise>/main.go`.
- Use descriptive `snake_case` names and add a link to the exercise index.
- Keep lesson notes with their exercise and compiled output in `build/`.

## Work in progress

This repository includes unfinished exercises and lesson notes; an entry in the
index does not imply a completed solution. In particular,
[addition_of_two.py](recursion/python/addition_of_two.py) contains an uncommented
recursion walkthrough, and [valid_palindrome_2.py](strings/python/valid_palindrome_2.py)
has a missing colon. Both currently have syntax errors.
