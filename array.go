package main

import (
	"fmt"
	"time"
)

func array_check_sorted(arr []int) bool {
	for i := 0; i < len(arr)-1; i++ {
		if arr[i] > arr[i+1] {
			return false
		}
	}
	return true

}

func bubble_sort(arr []int) []int {
	start := time.Now()
	for !array_check_sorted(arr) {
		for i := 0; i < len(arr)-1; i++ {
			if arr[i] > arr[i+1] {
				left := arr[i]
				arr[i] = arr[i+1]
				arr[i+1] = left
			}

		}
	}
	elapsed := time.Since(start)
	fmt.Printf("it took %s\n", elapsed)
	return arr
}

func array_max(arr []int) int {
	max := arr[0]
	for i := 0; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
		}
	}
	return max
}

func modified_bubble_sort(arr []int) []int {
	start := time.Now()
	for !array_check_sorted(arr) {
		for i := 0; i < len(arr)-1; i++ {
			if arr[i] > arr[i+1] {
				left := arr[i]
				arr[i] = arr[i+1]
				arr[i+1] = left
				if i > 0 {
					i--
				}
			}

		}
	}
	elapsed := time.Since(start)
	fmt.Printf("it took %s\n", elapsed)
	return arr
}

func main() {
	var arr = []int{
		34, 7, 23, 32, 5, 62, 78, 21, 43, 56,
		9, 81, 17, 39, 44, 3, 58, 29, 11, 65,
		2, 76, 15, 50, 90, 27, 60, 18, 73, 8,
		24, 49, 33, 40, 19, 6, 77, 13, 48, 55,
		31, 84, 20, 53, 12, 70, 36, 16, 85, 4,
		28, 59, 22, 66, 37, 10, 79, 25, 54, 41,
		14, 61, 26, 74, 30, 51, 1, 38, 83, 35,
		71, 44, 68, 9, 72, 42, 67, 80, 47, 69,
		75, 55, 10, 82, 44, 6, 16, 53, 35, 19,
		32, 62, 7, 21, 57, 29, 4, 68, 15, 25,
	}
	//arr := []int{2, 1, 5, 3, 9, 7, 10, 12, 4, 13, 11}
	//	fmt.Println(array_check_sorted(arr))
	fmt.Println(bubble_sort(arr))
	//	fmt.Println(array_max(arr))
	fmt.Println(modified_bubble_sort(arr))
}
