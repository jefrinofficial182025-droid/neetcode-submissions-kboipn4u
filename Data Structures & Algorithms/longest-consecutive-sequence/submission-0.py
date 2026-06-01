class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums : 
            return 0 
        nums = nums[:]
        longest_seq = 0 
        while nums: 
            k=min(nums)
            curr_seq_length = 1
            nums.remove(k)
            while k+1 in nums: 
                k+=1
                nums.remove(k)
                curr_seq_length+=1
            longest_seq = max(longest_seq, curr_seq_length)
        return longest_seq

            
        