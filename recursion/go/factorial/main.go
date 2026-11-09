package main

import "fmt"

func factorial(n int) int {
	counter := n
	answer := n

	for counter != 1 {
		counter = counter - 1
		answer = answer * counter
	}

	return answer
}

func fact(n int) int {
	if n == 1 {
		return 1
	} else {
		return fact(n-1) * n
	}
}

func main() {
	fmt.Println(factorial(5))
	fmt.Println(fact(5))
}
