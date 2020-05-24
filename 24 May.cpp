class Solution {
public:
    
    TreeNode* helper(vector<int>&preorder,int st,int end)
    {
        if(st > end) return NULL;
        
        int idx = end+1;
        for(int i = st + 1; i <=end;i++)
        {
            if(preorder[i] > preorder[st])
            {
                idx = i;
                break;
            }
        }
        
        TreeNode* cur = new TreeNode(preorder[st]);
        cur->left = helper(preorder,st+1,idx-1);
        cur->right = helper(preorder,idx,end);
        
        return cur;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return helper(preorder,0,preorder.size()-1);
    }
};
