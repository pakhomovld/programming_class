
def addition_of_two(a: int, b: int) -> int: # хвостовая рекурсия
    if a == 0:
        return b
    return addition_of_two(a - 1, b + 1)


#print(addition_of_two(5, 8))


def add(a: int, b: int) -> int: # не хвостовая рекурсия - когда никаких действия после вызова функции с ее результатом не производится
    if a == 0:
        return b
    return add(a - 1, b) + 1

# print(add(5, 8))

# add(3, 2) = add(2, 2) + 1 = add(1, 2) + 1 + 1 = add(0, 2) + 1 + 1 + 1 = 2 + 1 + 1 + 1 = 5

# 3 + 5 * 2 = 3 + 10

# Определить таким же образом умножение двух чисел
# Произведение двух чисел 

# def multiply(a: int, b: int) -> int:
#     if a == 0:
#         return a
#     return add(multiply(a - 1, b), b)

# print(multiply(2, 7))


def multiply_of_two(a: int, b: int) -> int:
    if a == 0:
        return b
    return multiply_of_two(a - 1, b + b)

#print(multiply_of_two(7, 7))


# nums = [10,5,22,3,11]

# def array_max(nums: [int]) -> int:
#     if len(nums) >= 2:
#         max = array_max(nums[1:])
#         if max > nums[0]:
#             return max
#         else:
#             return nums[0]
#     return nums[0]

# print(array_max(nums))



nums = [10,5,33,3,11]

def array_max(nums: [int]) -> int:
    if len(nums) >= 2:
        return max_two(nums[0], array_max(nums[1:]))
    return nums[0]
    

def max_two(a: int, b: int) -> int:
    if a > b:
        return a
    else:
        return b
    

print(array_max(nums))


array_max([10,5,7,3,11]) =
max_two(10, array_max([5,7,3,11])) = 
max_two(10, max_two(5, array_max([7,3,11]))) =
max_two(10, max_two(5, max_two(7, array_max([3,11])))) = 
max_two(10, max_two(5, max_two(7, max_two(3, array_max([11]))))) = 
max_two(10, max_two(5, max_two(7, max_two(3, 11)))) = 
max_two(10, max_two(5, max_two(7, 11))) = 
max_two(10, max_two(5, 11)) =
max_two(10, 11) = 11




# [5,7,3,11]

# 11 - база рекурсии

# 10

# 11 > 10 = 11



