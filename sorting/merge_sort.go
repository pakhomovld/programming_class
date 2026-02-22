package main

import "fmt"

func merge(left, right []int) []int {
	result := make([]int, 0, len(left)+len(right))
	i := 0
	j := 0

	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	result = append(result, left[i:]...)
	result = append(result, right[j:]...)

	return result
}

func qsort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}
	mid := len(arr) / 2

	return merge(qsort(arr[:mid]), qsort(arr[mid:]))
}

func main() {
	arr := []int{8, 3, 7, 6, 4, 2, 9, 5}
	sorted := qsort(arr)
	fmt.Println(sorted)
}
