
// TopDown with memoization
class Solution {
public:
    int dp[501][501];

    int helper(int i, int j, vector<int>& A, vector<int>& B)
    {
        if (i == A.size() || j == B.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // Dont join this
        int ans = max(helper(i + 1, j, A, B),helper(i,j+1,A,B));

        // join if it can be joined
        int ans2 = (A[i] == B[j]) + helper(i + 1, j + 1, A, B);

        return dp[i][j] = max(ans, ans2);
    }

    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp, -1, sizeof dp);
        return helper(0, 0, A, B);
    }
};

//==========================================================================================================

// Bottom Up Dp
class Solution {
public:
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int n = A.size(), m = B.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                // Dont join this
                int ans1 = max(dp[i][j+1],dp[i+1][j]);

                // join if it can be joined
                int ans2 = (A[i]==B[j]) + dp[i+1][j+1];
                
                dp[i][j] = max(ans1,ans2);   
            }
        }

        return dp[0][0];
    }
};
