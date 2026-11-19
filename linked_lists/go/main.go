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

	current := a
	for current.Ptr != nil {
		current = current.Ptr
	}
	current.Ptr = b
	return a
}

func quick_sort(a *list) *list {
	if a == nil {
		return a
	}
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

func len_of_list(a *list) int {
	if a == nil {
		return 0
	}
	return len_of_list(a.Ptr) + 1
}

func last_num_of_list(a *list) int {
	if a.Ptr == nil {
		return a.Num
	}
	return last_num_of_list(a.Ptr)
}

func is_sorted(a *list) bool {
	if a == nil || a.Ptr == nil {
		return true
	} else if a.Num > a.Ptr.Num {
		return false
	}

	return is_sorted(a.Ptr)
}

func delete_last_of_list(a *list) *list {
	if a.Ptr == nil {
		return nil
	}

	return &list{
		Num: a.Num,
		Ptr: delete_last_of_list(a.Ptr),
	}
}

func concat_recursion(a *list, b *list) *list {
	if a == nil {
		return b
	}

	return &list{
		Num: a.Num,
		Ptr: concat_recursion(a.Ptr, b),
	}
}

func delete_by_index(a *list, index int) *list {
	if a == nil {
		return nil
	}
	if index == 0 {
		return a.Ptr
	}
	return &list{
		Num: a.Num,
		Ptr: delete_by_index(a.Ptr, index-1),
	}
}

func delete_by_num(a *list, value int) *list {
	if a == nil {
		return nil
	}
	if a.Num == value {
		return delete_by_num(a.Ptr, value)
	}
	return &list{
		Num: a.Num,
		Ptr: delete_by_num(a.Ptr, value),
	}
}

func contains(a *list, value int) bool {
	if a == nil {
		return false
	}
	if a.Num == value {
		return true
	}
	return contains(a.Ptr, value)
}

func del_repeats(a *list) *list {
	if a == nil {
		return nil
	}
	if contains(a.Ptr, a.Num) {
		return del_repeats(a.Ptr)
	}
	return &list{
		Num: a.Num,
		Ptr: del_repeats(a.Ptr),
	}
}

func main() {

	arr1 := []int{1, 2, 2, 3, 4, 4, 4, 4}

	// a := list{}
	b := list{}
	// c := list{}

	// a.Num = 1
	// a.Ptr = &b

	b.Num = 4
	b.Ptr = nil

	// c.Num = 3
	// c.Ptr = nil

	// println(a.Num)
	// println(a.Ptr.Num)
	// println(a.Ptr.Ptr.Num)
	// print_list(&a)
	a := make_list_from_array(arr1)
	print_list(a)
	println()
	// a = quick_sort(a)
	// print_list(a)
	// print(len_of_list(a))
	// println()
	// print(last_num_of_list(a))
	// println()
	// print(is_sorted(a))
	// a = concat_recursion(a, &b)
	// print_list(a)
	// // a = delete_last_of_list(a)
	// // print_list(a)
	// println()
	// a = delete_by_index(a, 5)
	// print_list(a)
	// a = delete_by_num(a, 4)
	// print_list(a)
	// print(contains(a, 4))
	// println()
	// print(contains(a, 2))
	a = del_repeats(a)
	print_list(a)

}

// HW: написать функцию сортировки quick sort(как в питоне) - используя списки - done
// для этого нужна функция конкатенации списков - done

// HW: конкатенация списков с помощью рекурсии - done
// удаление элемента из списка по его номеру - done

// HW: написать функцию которая берет список и число и удаляет все элементы равные этому числу - done
// написать функцию которая из списка удаляет повторения - здесь нужна будет функция которая проверяет что в списке есть элемент с таким значением
