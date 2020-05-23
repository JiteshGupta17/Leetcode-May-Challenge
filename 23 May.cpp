// O(n) - 64ms beats 80%
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {

        vector<vector<int>> ans;
        if (A.empty() || B.empty()) return ans;

        int idx_a = 0;
        int idx_b = 0;

        while (true)
        {
            int left = max(A[idx_a][0], B[idx_b][0]);
            int right = min(A[idx_a][1], B[idx_b][1]);


            if (left <= right)
            {
                ans.push_back({left, right});
            }

            if (right == A[idx_a][1]) {
                if (idx_a + 1 < A.size()) idx_a++;
                else break;
            }
            else {
                if (idx_b + 1 < B.size()) idx_b++;
                else break;
            }
        }

        return ans;

    }
};
