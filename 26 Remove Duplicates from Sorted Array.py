class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        p = 0
        if nums == []:
            return 0
        for i in range(len(nums)):
            if nums[i]>nums[p]:
                nums[p+1] = nums[i]
                p += 1
        return p+1
        
                
