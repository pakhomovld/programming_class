def array_check_sorted(arr):

    for i in range(len(arr) -1):
        if arr[i] > arr[i+1]:
            return False
    return True
            
        
print(array_check_sorted([1, 2, 3, 4, 5]))

# 1 4 3 5 7 9
            
def bubble_sort(arr):
    while array_check_sorted(arr) != True:
        for i in range(len(arr) -1):
            if arr[i] > arr[i+1]:
                left = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = left
    return arr

print(bubble_sort([8, 4, 3, 5, 9, 7]))


def array_max(arr):
    max = arr[0]
    for i in range(len(arr)):
        if arr[i] > max:
            max = arr[i]
    return max

print(array_max([1, 2, 7, 8, 9]))


def modified_bubble_sort(arr):
    while array_check_sorted(arr) != True:
        for i in range(len(arr) -1):
            if arr[i] > arr[i+1]:
                left = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = left
                if i > 0:
                    i-1
    return arr

print(bubble_sort([8, 4, 3, 5, 9, 7]))


