package main

import "fmt"

// merge объединяет два отсортированных массива в один отсортированный
func merge(left, right []int) []int {
	result := make([]int, 0, len(left)+len(right))
	i, j := 0, 0

	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	// добавляем оставшиеся элементы из left или right
	result = append(result, left[i:]...)
	result = append(result, right[j:]...)

	return result
}

// qsort рекурсивно сортирует массив с помощью разбиения и слияния
func qsort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}
	mid := len(arr) / 2

	left := qsort(arr[:mid])
	right := qsort(arr[mid:])

	return merge(left, right)
}

func main() {
	arr := []int{8, 3, 7, 6, 4, 2, 9, 5}
	sorted := qsort(arr)
	fmt.Println(sorted) // [2 3 4 5 6 7 8 9]
}
