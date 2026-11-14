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

func concat(a *list, b *list) *list {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}

	current := a
	for current.Ptr != nil {
		current = current.Ptr
	}
	current.Ptr = b
	return a
}

func quick_sort(a *list) *list {
	if a == nil || a.Ptr == nil {
		return a
	} else {
		var list_before *list = nil
		var list_after *list = nil
		var ptr *list = nil
		var first *list = a
		a = a.Ptr

		for a != nil {
			if a.Num < first.Num {
				ptr = a.Ptr
				a.Ptr = list_before
				list_before = a
				a = ptr
			} else {
				ptr = a.Ptr
				a.Ptr = list_after
				list_after = a
				a = ptr
			}
		}
		first.Ptr = quick_sort(list_after)
		return concat(quick_sort(list_before), first)
	}
}

func main() {

	arr1 := []int{3, 1, 2}

	// a := list{}
	// b := list{}
	// c := list{}

	// a.Num = 1
	// a.Ptr = &b

	// b.Num = 4
	// b.Ptr = nil

	// c.Num = 3
	// c.Ptr = nil

	// println(a.Num)
	// println(a.Ptr.Num)
	// println(a.Ptr.Ptr.Num)
	// print_list(&a)
	a := make_list_from_array(arr1)
	print_list(a)
	println()
	a = quick_sort(a)
	print_list(a)
}

// HW: написать функцию сортировки quick sort(как в питоне) - используя списки - done
// для этого нужна функция конкатенации списков - done
