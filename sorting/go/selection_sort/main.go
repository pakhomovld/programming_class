package main

import "fmt"

// 1 5 8 2 9 3
// 1 2 8 5 9 3
// 1 2 3 5 9 8
// 1 2 3 5 8 9

func selection_sort(arr []int) []int {
	for j := 0; j < len(arr); j++ {
		min := j
		for i := j; i < len(arr); i++ {
			if arr[i] < arr[min] {
				min = i
			}
		}
		left := arr[j]
		arr[j] = arr[min]
		arr[min] = left
	}
	return arr
}

func main() {
	var arr = []int{
		34, 7, 23, 32, 5, 62, 78, 21, 43, 56}
	fmt.Println(selection_sort(arr))
}
