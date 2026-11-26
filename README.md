# Programming Class

A notebook-style repository for programming lessons in Python, Go, and C.
I implement exercises in one language and translate them into another to practice
different ways of thinking and learn from the errors along the way.

These are lesson notes, experiments, and drafts. Most examples use inputs defined
in the source file; there is no single application entry point.

## Quick start

Run commands from the repository root. You only need the tools for the language
you want to use:

- **Python 3** — examples use the standard library; no packages to install.
- **Go 1.25.2 or newer** — the minimum version is declared in [go.mod](go.mod).
- **C compiler** — examples below use `cc` with C11; Snake also needs ncurses.

```sh
python3 sorting/python/selection_sort.py
go run ./sorting/go/selection_sort
go run ./joy
```

## Structure

Exercises are grouped by **topic, then language**. Each Go program has its own
directory with a `main.go`, so examples can be built and run independently.
The larger Go lesson projects, Game of Life and Joy, have top-level directories.

```text
arrays/           # Arrays and dynamic arrays
  c/
  python/
games/            # Snake and tic-tac-toe / game AI
  c/
  python/
game_of_life/     # Conway's Game of Life in Go
joy/              # Stack-based expression evaluator in Go
linked_lists/     # Linked lists and list sorting
  c/
  go/
recursion/        # Recursion exercises
  go/<exercise>/main.go
  python/
sorting/          # Sorting algorithms
  go/<exercise>/main.go
  python/
strings/          # String operations and validation
  c/
  python/
go.mod            # Shared Go module for all Go examples
build/            # Local compiled output (ignored by Git)
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
| Linked list operations and quicksort | [C](linked_lists/c/linked_list.c), [Go](linked_lists/go/main.go) |
| Recursive list operations: length, concatenation, deletion, search, and deduplication | [Go](linked_lists/go/main.go) |

### Recursion

| Exercise | Implementations |
| --- | --- |
| Addition, multiplication, and array maximum | [Python](recursion/python/addition_of_two.py) |
| Factorial | [Python](recursion/python/factorial.py), [Go](recursion/go/factorial/main.go) |
| Iterative and recursive factorial / Fibonacci, including memoization | [Go](recursion/go/fibonacci/main.go) |
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
| Conway's Game of Life | [Go](game_of_life/main.go) |

### Joy

[joy/main.go](joy/main.go) is a small stack-based evaluator for expressions in
reverse Polish notation. It stores the program as a linked list and supports
integer arithmetic (`+`, `-`, `*`, `/`), negation (`neg`), and swapping the top
two stack values (`swap`). For example, `3 2 + 4 *` leaves `20` on the stack.

The current demo uses a hardcoded `[]any` expression and prints the program and
its resulting stack. Keyboard input and step-by-step evaluation are still lesson
tasks.

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
go run ./recursion/go/fibonacci
go run ./linked_lists/go
go run ./joy
go run ./game_of_life
```

Game of Life prints 60 generations of a glider on a 15×15 board, with a 200 ms
delay between generations. It finishes after about 12 seconds; use `Ctrl+C` to
stop early. Initial states and sample inputs are defined in each `main()`.

Build all Go examples and run static checks without producing binaries in the
source directories:

```sh
go build ./...
go vet ./...
```

To keep a runnable binary, choose a path under `build/` explicitly:

```sh
mkdir -p build
go build -o build/joy ./joy
./build/joy
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

Snake uses `w`, `a`, `s`, and `d` for movement and waits for keyboard input.
Run it in an interactive terminal; use `Ctrl+C` to stop.

## Adding exercises

- Put Python and C files in `<topic>/python/` and `<topic>/c/`.
- Put each Go program in `<topic>/go/<exercise>/main.go`.
- Keep related exercises in an existing lesson project when they share a program.
- Use descriptive `snake_case` names and add a link to the exercise index.
- Keep lesson notes with their exercise and compiled output in `build/`.

## License

[MIT](LICENSE).
