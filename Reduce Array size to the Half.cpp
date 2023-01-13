class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> counts;
        for(const int& i : arr){
            if(counts.find(i) == counts.end())
                counts[i] = 0;
            counts[i]++;
        }
        ///sort based on occurrence 1,2,2,3,3,3,4,4,4
        sort(arr.begin(), arr.end(), [&counts](const int &a, const int &b){return counts[a] < counts[b];});
        
        int n = arr.size(), size = n, ret =0;
        while(size > n/2){
            size -= counts[arr[size-1]];
            ret++;
        }
        return ret;

        
    }
};
