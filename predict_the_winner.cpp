class Solution {
public:

    int maxdiff(int ind1, int ind2, vector<int> &nums){

        if(ind1==ind2) return nums[ind1];

        int take_left = nums[ind1]-maxdiff(ind1+1,ind2,nums);
        int take_right = nums[ind2]-maxdiff(ind1,ind2-1,nums);

        return max(take_left,take_right);
    }

    bool PredictTheWinner(vector<int>& nums) {

        int n=nums.size();
        return maxdiff(0,n-1,nums)>=0;    
    }
};

//dp approach
class Solution {
public:

    int maxdiff(int ind1, int ind2, vector<int> &nums,vector<vector<int>>& dp){

        if(ind1==ind2) return nums[ind1];
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];


        int take_left = nums[ind1]-maxdiff(ind1+1,ind2,nums,dp);
        int take_right = nums[ind2]-maxdiff(ind1,ind2-1,nums,dp);

        return dp[ind1][ind2]=max(take_left,take_right);
    }

    bool PredictTheWinner(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return maxdiff(0,n-1,nums,dp)>=0;    
    }
};
