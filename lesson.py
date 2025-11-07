# arr = [ 1 5 4 3 6 ]
# arr = [ 6 3 4 5 1 ]
# index   0 1 2 3 4 

def array_check_sorted(arr):
    for i in range(len(arr) -1):
        if arr[i] > arr[i+1]:
            return False
    return True

print(array_check_sorted([5, 2, 3, 4, 1]))
            
def bubble_sort(arr):
    while array_check_sorted(arr) != True:
        for i in range(len(arr) -1):
            if arr[i] > arr[i+1]:
                left = arr[i]
                arr[i] = arr[i+1]
                arr[i+1] = left
    return arr

print(bubble_sort([8, 4, 3, 5, 9, 7]))

