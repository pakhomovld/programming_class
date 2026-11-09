

arr = [1,2,3,4]

def multiplication_arr(arr):
    for i in range(len(arr)):
        result = arr[i] * arr[i+1]
    return result

print(multiplication_arr(arr))

# [i * i+1 for i in range arr]

# 1 * 2 = 2
# 2 * 3 = 6
# 3 * 4 = 12
# 2 + 6 + 12 = 20

# 1 * 2 * 3 * 4 = 24
# 1 * 2 = 2 * 3 = 6 * 4 = 24