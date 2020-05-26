class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int max_len = 0;

        // sum, last_occurance of sum
        unordered_map<int, int> mp;

        mp[0] = -1;
        int cum_sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            cum_sum += nums[i] == 0 ? -1 : 1;

            if (mp.count(cum_sum))
            {
                max_len = max(max_len, i - mp[cum_sum]);
            }
            else mp[cum_sum] = i;
        }

        return max_len;
    }
};
