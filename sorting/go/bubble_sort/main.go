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

func simplified_bubble_sort(arr []int) []int {
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

func gnome_sort(arr []int) []int {
	start := time.Now()
	i := 0
	for i < len(arr)-1 {
		fmt.Println(arr)
		fmt.Println(arr[i], arr[i+1])
		if arr[i] > arr[i+1] {
			left := arr[i]
			arr[i] = arr[i+1]
			arr[i+1] = left
			if i > 0 {
				i--
			}
		} else {
			i++
		}
	}
	elapsed := time.Since(start)
	fmt.Printf("it took %s\n", elapsed)
	return arr
}

func bubble_sort_original(arr []int) []int {
	start := time.Now()
	for true {
		sorted := true
		for i := 0; i < len(arr)-1; i++ {
			fmt.Println(arr)
			fmt.Println(arr[i], arr[i+1])
			if arr[i] > arr[i+1] {
				left := arr[i]
				arr[i] = arr[i+1]
				arr[i+1] = left
				sorted = false
			}
		}
		if sorted {
			break
		}
	}
	elapsed := time.Since(start)
	fmt.Printf("it took %s\n", elapsed)
	return arr
}

func bubble_sort(arr []int) []int {
	n := len(arr)
	for {
		swapped := false
		for i := 1; i < n; i++ {
			if arr[i-1] > arr[i] {
				arr[i-1], arr[i] = arr[i], arr[i-1]
				swapped = true
			}
		}
		if !swapped {
			break
		}
	}
	return arr
}

func main() {
	var arr = []int{
		34, 7, 23, 32, 5, 62, 78, 21, 43, 56}
	//arr := []int{2, 1, 5, 3, 9, 7, 10, 12, 4, 13, 11}
	//fmt.Println(array_check_sorted(arr))
	//fmt.Println(simplified_bubble_sort(arr))
	//fmt.Println(array_max(arr))
	//fmt.Println(gnome_sort(arr))
	//fmt.Println(bubble_sort_original(arr))
	//fmt.Println(selection_sort(arr))
	fmt.Println(bubble_sort(arr))
}
