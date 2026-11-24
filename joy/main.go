package main

import (
	"fmt"
	"os"
)

type Node struct {
	Val  any
	Next *Node
}

func convert(a []any) *Node {
	var b *Node

	for i := len(a) - 1; i >= 0; i-- {
		b = &Node{
			Val:  a[i],
			Next: b,
		}
	}
	return b
}

func print_list(head *Node) {
	for head != nil {
		fmt.Print(head.Val, " ")
		head = head.Next
	}
	println()
}

func print_array(a []int) {
	for i := 0; i < len(a); i++ {
		fmt.Print(a[i], " ")
	}
}

func take_2_elements(stack []int) (int, int, []int) {
	if len(stack) < 2 {
		fmt.Println("Меньше 2 элементов на стеке")
		os.Exit(1)
	}
	return stack[len(stack)-2], stack[len(stack)-1], stack[:len(stack)-2]
}

func take_1_element(stack []int) (int, []int) {
	if len(stack) < 1 {
		fmt.Println("Меньше 1 элемента на стеке")
		os.Exit(1)
	}
	return stack[len(stack)-1], stack[:len(stack)-1]
}

func evalPNR(head *Node) []int {
	var stack []int
	var a int
	var b int
	var res int

	for curr := head; curr != nil; curr = curr.Next {
		switch v := curr.Val.(type) {
		case int:
			stack = append(stack, v)
		case string:
			switch v {
			case "+":
				a, b, stack = take_2_elements(stack)
				res = a + b
				stack = append(stack, res)
			case "-":
				a, b, stack = take_2_elements(stack)
				res = a - b
				stack = append(stack, res)
			case "*":
				a, b, stack = take_2_elements(stack)
				res = a * b
				stack = append(stack, res)
			case "/":
				a, b, stack = take_2_elements(stack)
				if b == 0 {
					fmt.Println("Нельзя делить на 0")
					os.Exit(1)
				}
				res = a / b
				stack = append(stack, res)
			case "neg":
				a, stack = take_1_element(stack)
				res = -a
				stack = append(stack, res)
			case "swap":
				a, b, stack = take_2_elements(stack)
				stack = append(stack, b, a)
			}
		}

	}
	return stack

}

func main() {
	// var x any
	// var y any
	// var z any

	a := []any{1, 2, "+", 3, "+", 6, "/", 5, 5, "*", "-", "neg", 5, "swap"}

	// x = "hello"
	// y = 123
	// z = nil
	c := convert(a)
	print_list(c)
	// switch v := z.(type) {
	// case int:
	// 	print(v + 1)
	// case string:
	// 	print(v + "hello")
	// case nil:
	// 	print(v)
	// default:
	// }
	print_array(evalPNR(c))

}

// 1 + 2
// 1 2 + - обратная Польская запись

// 1 2 + 3 -

// (3 + 2) * 4
// 3 2 + 4 *

// 4 * (3 + 2)
// 4 3 2 + *

// (3 + 2) * (1 + 4)
// 3 2 + 1 4 + *

// HW: дописать функции конвертации и печати этого списка
// посмотреть на вики - алгоритм вычисления обратной польской записи (stack, slice/list без разницы)
// написать функцию которая берет список и возвращает число(вычислитель обратной польской записи)

// Clojure диалект LISP
// SKIM - среда DR racket для работы с книгой Structure and Interpretation of Computer Programs(SICP) -> https://web.mit.edu/6.001/6.037/sicp.pdf)

// HW: реализовать свой split(), для считывания с клавиатуры выражения, которое надо сконвертировать в список
// split должен нормально реагировать когда есть лишние пробелы(trim), включая лишний пробел на конце строки
// -> функция конвертации строки в список

// программа должна печатать шаги которые она делает, при каждом действии выводить стек и остаток программы, который еще не вычислен
