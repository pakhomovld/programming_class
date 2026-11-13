package main

import (
	"fmt"
	"time"
)

func create_matrix(rows, cols int) [][]int {
	matrix := make([][]int, rows)
	for i := range matrix {
		matrix[i] = make([]int, cols)
	}
	return matrix
}

func print_matrix(arr [][]int) {
	//fmt.Print("\033[H\033[2J")

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr[i]); j++ {
			if arr[i][j] == 1 {
				fmt.Print("■ ")
			} else {
				fmt.Print(". ")
			}
		}
		fmt.Println()
	}
}

func check_matrix_member(arr [][]int, life_i int, life_j int) int {
	if life_i >= 0 && life_j >= 0 && life_i < len(arr) && life_j < len(arr[0]) {
		return arr[life_i][life_j]
	}
	return 0
}

func points_around(arr [][]int, life_i int, life_j int) int {

	return check_matrix_member(arr, life_i-1, life_j-1) +
		check_matrix_member(arr, life_i-1, life_j) +
		check_matrix_member(arr, life_i-1, life_j+1) +
		check_matrix_member(arr, life_i, life_j-1) +
		check_matrix_member(arr, life_i, life_j+1) +
		check_matrix_member(arr, life_i+1, life_j-1) +
		check_matrix_member(arr, life_i+1, life_j) +
		check_matrix_member(arr, life_i+1, life_j+1)

}

func live_or_die(arr [][]int, life_i int, life_j int) int {
	res := points_around(arr, life_i, life_j)

	if res == 3 || (arr[life_i][life_j] == 1 && res == 2) {
		return 1
	}
	return 0
}

func next_generation(arr [][]int) [][]int {
	rows := len(arr)
	cols := len(arr[0])
	new_arr := create_matrix(rows, cols)

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			new_arr[i][j] = live_or_die(arr, i, j)
		}
	}

	return new_arr
}

func main() {
	arr := create_matrix(15, 15)

	// Ставим фигуру "Планер" (Glider) в левый верхний угол
	arr[0][1] = 1
	arr[1][2] = 1
	arr[2][0] = 1
	arr[2][1] = 1
	arr[2][2] = 1

	for i := 0; i < 60; i++ {
		print_matrix(arr)
		arr = next_generation(arr)
		time.Sleep(200 * time.Millisecond)
	}

}

// HW: функция которая применяет правила игры, принимает на вход точку, матрицу и возвращает 1 или 0(будет эта точка жить или нет)
// HW: функция - брать матрицу и применять новую матрицу от предыдущей функции - строить новое поле
