class Solution {
public:

    string rev(int n,string s){

        for(int i=0; i<n/2; i++){
            swap(s[i],s[n-i-1]);
        }
        return s;
    }
    
    int longestPalindromeSubseq(string s) {

        int n=s.size();
        string s2= rev(n,s);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
};
