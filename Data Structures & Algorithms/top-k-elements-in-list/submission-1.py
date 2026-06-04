class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        d = sorted(counter.items(), key = lambda x : x[1], reverse=True)
        ans=[]
        for i in range(k):
            ans.append(d[i][0])
        return ans