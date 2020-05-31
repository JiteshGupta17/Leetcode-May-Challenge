class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
     
    int minCost_recur(string s,string t,int i,int j)
    {
        if(i==s.length())
        {
            return t.length()-j;
        }
    
        if(j==t.length())
        {
            return s.length()-i;
        }
    
        if(s[i]==t[j]) return minCost_recur(s,t,i+1,j+1);
    
        int ans = INT_MAX;
    
        ans = min(ans,minCost_recur(s,t,i+1,j+1)); // Replace
        ans = min(ans,minCost_recur(s,t,i+1,j)); // Add
        ans = min(ans,minCost_recur(s,t,i,j+1)); // Remove
    
        return ans + 1;
    }
    
    
    int minCost(string s,string t)
    {
        int n = s.length();
        int m = t.length();
    
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
        for(int i = n;i>=0;i--)
        {
            for(int j = m;j>=0;j--)
            {
                if(i==n)
                {
                    dp[i][j] = m-j;
                }
                else if(j==m)
                {
                    dp[i][j] = n-i;
                }
                else if(s[i]==t[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] =1 + min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
    
        return dp[0][0];
    }
    int minDistance(string &word1, string &word2) {
        // return minCost_recur(word1,word2,0,0);
        return minCost(word1,word2);
    }
};
