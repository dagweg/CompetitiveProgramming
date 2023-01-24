class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        vector<int> prefixSum(n+1);
        prefixSum[0] = 0;
        prefixSum[1] = 1;

        for(int i = 2; i < n+1; i++){
            prefixSum[i] = prefixSum[i-1] + prefixSum[i-2];
        }

        return prefixSum[n];
    }
};
