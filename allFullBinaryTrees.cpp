class Solution {
public:
    void dfs(int n,vector<vector<TreeNode*>>&dp){
        if(n==1){
            dp[n].push_back(new TreeNode(0));
            return;
        }
        dfs(n-2,dp);
        int left=1,right=n-2;
        while(left<=right){
            for(TreeNode* l: dp[left]){
                for(TreeNode* r: dp[right]){
                    TreeNode* root1=new TreeNode(0);
                    root1->left=l;
                    root1->right=r;
                    dp[n].push_back(root1);
                    if(left!=right){
                        TreeNode* root2=new TreeNode(0);
                        root2->left=r;
                        root2->right=l;
                        dp[n].push_back(root2);
                    }

                }
            }
            left+=2;right-=2;
        }
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n&1))return {};
        vector<vector<TreeNode*>>dp(n+1);
        dfs(n,dp);
        return dp[n];
    }
};
