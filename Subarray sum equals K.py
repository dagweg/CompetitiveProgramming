class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:        
        cnt = 0
        s = 0
        d = {0: 1}
        for num in nums:
            s += num
            cnt += d.get(s - k, 0)
            d[s] = d.get(s, 0) + 1
        return cnt
