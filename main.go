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

func main() {
	//print(factorial(5))
	print(recursive_factorial(10000))
	//print(accum_recursive_factorial(50, 1))
}
