class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 1;
        int n = nums.size();
        int temp = 0;

        while(r < n){
            if(nums[l] == 0 && nums[r] == 0){
                r++;
                continue;
            }
            if(nums[l] == 0 && nums[r] != 0){
                temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
            }
            r++;
            l++;
        }
    }
};
