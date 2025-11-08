# 1 5 8 2 9 3
# 1 2 8 5 9 3
# 1 2 3 5 9 8
# 1 2 3 5 8 9

def selection_sort(arr):
    for j in range(len(arr)):
        min = j
        for i in range(j, len(arr)):
            if arr[i] < arr[min]:
                min = i
        left = arr[j]
        arr[j] = arr[min]
        arr[min] = left

    return arr


print(selection_sort([3, 2, 9, 4, 5, 6]))