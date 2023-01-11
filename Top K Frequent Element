class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> vec;
        vector<int> ret;

        for(const int& i : nums) mp[i]++;

        for(const auto& it: mp) vec.push_back(it);

        sort(vec.begin(), vec.end(), [](const auto& p,const auto& q){
            return p.second>q.second;
        });

        for(int i = 0; i < k; i++) ret.emplace_back(vec[i].first);

        return ret;
    }
};
