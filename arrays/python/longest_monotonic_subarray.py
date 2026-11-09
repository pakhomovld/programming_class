# nums = [1,4,3,3,2]
# nums = [3,2,1]






# [1,4,3,3,2]
# 1 4

# [3,2,1]
# 3 2 1


# как я думаю это решать

nums = [1,4,3,3,2]

def longestMonotonicSubarray(nums: [int]) -> [int]:
    left = 0
    newarr = []
    for right in range(1, len(nums)):
        if nums[left] == nums[right] + 1 or nums[left] == nums[right] - 1:
            newarr.append(nums[left] + nums[right])
            left += 1
    return newarr

print(longestMonotonicSubarray(nums))
        

