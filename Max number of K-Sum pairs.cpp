class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {    
        auto x_x = [](){ios::sync_with_stdio(0); cin.tie(0); return 0;}();

        unordered_map<int,int> mp;

        for(const int& i : nums) mp[i]++;

        int maxOps = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(k-nums[i] == nums[i] && mp[nums[i]] < 2)
            {
                continue;
            }	

            if(mp.count(k-nums[i]) && mp.count(nums[i]))
            {
                mp[k - nums[i]]--;
                mp[nums[i]]--;

                if(mp[nums[i]] <= 0)
                {	
                    mp.erase(nums[i]);
                }
                if(mp[k-nums[i]] <= 0)
                {
                    mp.erase(k - nums[i]);
                }

                maxOps++;
            }
        }
        return maxOps;
    }
};

