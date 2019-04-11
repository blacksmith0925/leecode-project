class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if nums == []:
            return 0
        p = len(nums)-1
        for i in range(len(nums)):
            while nums[i] == val:
                if p==i:
                    break
                nums[i] = nums[p]
                p -= 1
            if p==i:
                break

        if nums[p] == val:
            return p
        else:
            return p+1
