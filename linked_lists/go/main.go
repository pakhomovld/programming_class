package main

type list struct {
	Num int
	Ptr *list
}

func print_list(a *list) {
	for a != nil {
		println(a.Num)
		a = a.Ptr
	}
}

func make_list_from_array(arr []int) *list {
	var floor *list = nil

	for i := len(arr) - 1; i >= 0; i-- {
		new_list := list{}
		new_list.Ptr = floor
		new_list.Num = arr[i]
		floor = &new_list
	}
	return floor
}

func main() {

	arr := []int{1, 2, 3}

	// a := list{}
	// b := list{}
	// c := list{}

	// a.Num = 1
	// a.Ptr = &b

	// b.Num = 2
	// b.Ptr = &c

	// c.Num = 3
	// c.Ptr = nil

	// println(a.Num)
	// println(a.Ptr.Num)
	// println(a.Ptr.Ptr.Num)
	// print_list(&a)
	print_list(make_list_from_array(arr))
}

// HW: написать функцию сортировки quick sort(как в питоне) - используя списки
// для этого нужна функция конкатенации списков
