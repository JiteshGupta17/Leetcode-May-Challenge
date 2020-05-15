class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
    
        int n = A.size();
        vector<int> dp(n);
        
        int cur_sum = A[0];
        int max_sum = A[0];
        
        int ans = max_sum;
        int prefix_sum = A[0];
        dp[0] = A[0];
        
        for(int i = 1;i<n;i++)
        {
            // Kadane's
            cur_sum = max(cur_sum + A[i],A[i]);
            max_sum = max(max_sum,cur_sum);
            
            ans = max(ans,max_sum);
            
            // Prefix_sum
            prefix_sum += A[i];
            dp[i] = max(dp[i-1],prefix_sum);
            
        }
        
        int suffix_sum;
        for(int i = n-1;i>=1;i--)
        {
            // Suffix_sum
            if(i==n-1)
            {
                suffix_sum = A[i];
                ans = max(ans,suffix_sum + dp[i-1]);
            }
            else{
                
                int cur_max = max(suffix_sum,suffix_sum + A[i]);
                suffix_sum += A[i];
                
                ans = max(ans,cur_max + dp[i-1]);
            }
        }
        
        return ans;
        
    }
};
