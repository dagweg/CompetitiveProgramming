class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [nums[0]]
        postfix = [nums[n-1]]

        # O(n-1)
        for i in range(1,n):
            prefix.append(prefix[i-1] * nums[i])
            if n - i - 1 >= 0:
                postfix.insert(0, postfix[0] * nums[n-i-1])
        
        ret = []
        # O(n)
        for i in range(n):
            if i-1 < 0:
                ret.append(postfix[i+1])
            elif i+1 > n-1:
                ret.append(prefix[i-1])
            else:
                ret.append(prefix[i-1] * postfix[i+1])
            
        return ret

