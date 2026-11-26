package main

func factorial(num int) int {
	result := 1
	for i := 2; i <= num; i++ {
		result = result * i
	}
	return result
}

func recursive_factorial(num int) int {
	if num == 0 {
		return 1
	}
	return recursive_factorial(num-1) * num
}

func accum_recursive_factorial(num int, res int) int {
	if num == 0 {
		return res
	}
	return accum_recursive_factorial(num-1, res*num)
}

func fibonacci(num int) int {
	prev := 1
	before_prev := 1

	for i := 2; i <= num; i++ {
		prev, before_prev = prev+before_prev, prev
	}
	return before_prev
}

func recursive_fibonacci_simple(num int) int {
	if num == 1 || num == 2 {
		return 1
	}
	return recursive_fibonacci_simple(num-1) + recursive_fibonacci_simple(num-2)
}

// memoization
// {}

var dict map[int]int

func recursive_fibonacci(num int) int {
	var val int
	var exists bool

	if num == 1 || num == 2 {
		return 1
	}

	val, exists = dict[num]
	if exists {
		return val
	}

	result := recursive_fibonacci(num-1) + recursive_fibonacci(num-2)
	dict[num] = result

	return result
}

// index: 1 2 3 4 5 6 7
// value: 1 1 2 3 5 8 13

// 1 1 2 3 5 8 13 21
// 1 2 3 4 5 6 7  8
func main() {
	//print(factorial(5))
	//print(recursive_factorial(10000))
	//print(accum_recursive_factorial(50, 1))
	//print(fibonacci(6))
	dict = make(map[int]int)
	for i := 2; i <= 60; i++ {
		print(recursive_fibonacci(i))
	}
}
