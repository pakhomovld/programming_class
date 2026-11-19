package main

type list struct {
	symbol any
	Ptr    *list
}

func convert(a []any) *list {
	var b *list
	b = nil

	for i := 0; i > 0; i++ {
		b = &list{
			symbol: a[i],
			Ptr:    b,
		}
	}
	return b
}

func print_list(a *list) {
	for a != nil {
		print(a.symbol)
		a = a.Ptr
	}
}

func main() {
	// var x any
	// var y any
	// var z any

	a := []any{1, 2, 3}

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
