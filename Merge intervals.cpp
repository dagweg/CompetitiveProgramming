class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> merged = {intervals[0]};

        int ptr = 0;
        int n = intervals.size();
        
        for(int i = 1; i < n; i++){
            if(merged[ptr][1] >= intervals[i][0]){
                merged[ptr][1] = max(intervals[i][1], merged[ptr][1]);
            }else{
                merged.push_back(intervals[i]);
                ptr++;
            }
        }

        return merged;

    }
};
