class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j = -1;
        int prevMinKIndex = -1;
        int prevMaxKIndex = -1;

        for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < minK || nums[i] > maxK)
            j = i;
        if (nums[i] == minK)
            prevMinKIndex = i;
        if (nums[i] == maxK)
            prevMaxKIndex = i;
        ans += max(0, min(prevMinKIndex, prevMaxKIndex) - j);
        }

    return ans;
    }
};