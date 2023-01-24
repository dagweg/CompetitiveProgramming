class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];

        int last = prefixSum[n-1];

        for(int i = 0; i < n; i++){
            if(i == 0 && last - prefixSum[i] == 0 || \
               i != 0 && last - prefixSum[i] == prefixSum[i-1])
                return i;
        }
        return -1;
    }
};
