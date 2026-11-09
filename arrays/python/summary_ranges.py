# nums = []           # [] → []
# nums = [1]          # [1] → ["1"]
# nums = [1,2,3]      # [1,2,3] → ["1->3"]
nums = [1,3,4,5,7]  # [1,3,4,5,7] → ["1","3->5","7"]


def summaryRanges(nums: List[int]) -> List[str]:
    if not nums:
        return []
    
    result = []
    start = nums[0]

    for i in range(len(nums)):
        if i == len(nums) - 1 or nums[i + 1] != nums[i] + 1:
            if start == nums[i]:
                result.append(str(start))
            else:
                result.append(f"{start}->{nums[i]}")
            start = nums[i + 1] if i < len(nums) - 1 else start
    
    return result

print(summaryRanges(nums))