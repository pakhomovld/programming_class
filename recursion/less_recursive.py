nums = [8,5,2,3,9]

num = 6

def less(num: int, nums: [int]) -> [int]:
    if len(nums) < 1:
        return []
    if nums[0] < num:
        return [nums[0]] + less(num, nums[1:])
    else:
        return less(num, nums[1:])
    



#print(less(num, nums))



# less(4, [1,2,3,4,5]) = [1] + less(4, [2,3,4,5]) 
# [1,2,3] = [2,3] = [1] + [2,3]

# less(4, [8,5,2,3,9]) = less(4, [5,2,3,9])
# [2,3] = [2,3]




# a|b|c|d
# a|bcd
# ab|cd
# abc|d
# a|b|cd 
# ab|c|d 
# a|bc|d


# bcd
# b|cd 
# bc|d 
# b|c|d 

# ab|cd 
# a|b|cd 

# abc|d 
# a|bc|d 

# ab|c|d 
# a|b|c|d


# a = 'abcd' 

# def cuts(a: str) -> [str]:
#     if len(a) < 1:
#         return [""]
#     elif len(a) == 1:
#         return a
#     arr = cuts(a[1:])
#     result = []
#     for i in range(len(arr)):
#         result.append(a[0] + '|' + arr[i])
#         result.append(a[0] + arr[i])
#     return result

# print(cuts(a))




a = 'abcd' 

def cuts(a: str) -> [str]:
    if len(a) <= 1:
        return [a]
    arr = cuts(a[1:])
    return [a[0] + '|' + i for i in arr] + [a[0] + i for i in arr] # list comprehension (охват списка)


print(cuts(a))