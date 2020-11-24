class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1;
        int len = nums.size();
        vector<int> result (len, 1);
        for(int i = 0; i < len; i++) {
            result[i] *= left;
            result[len-1-i] *= right;
            left *= nums[i];
            right *= nums[len-i-1];
        }
        return result;
    }
};