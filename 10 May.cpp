class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = N;
        vector<int> trusted(n+1,0);
        
        for(auto vec : trust)
        {
            trusted[vec[0]]--;
            trusted[vec[1]]++;
        }
        
        // As judge doesnt trust anyone so he must not face any minus above
        for(int i = 1;i<=n;i++)
        {
            if(trusted[i]==n-1) return i;
        }
        
        return -1;
    }
};
