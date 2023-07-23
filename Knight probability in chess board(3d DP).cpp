class Solution {
public:

    int dr[8]={2,2,-2,-2,1,1,-1,-1};
    int dc[8]={-1,1,1,-1,2,-2,2,-2};
    
    bool isValid(int n,int r,int c){
        return r>=0 && c>=0 && r<n && c<n;
    }

    double dfs(int n,int k, int r, int c,vector<vector<vector<double>>> &dp){

        if(k==0) return 1;
        if(dp[k][r][c]!=-1) return dp[k][r][c];
        double valid=0;
        for(int i=0; i<8; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if(isValid(n,nr,nc)){
                valid+=dfs(n,k-1,nr,nc,dp);
            }
        }
        return dp[k][r][c]=valid/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n+1, vector<double>(n+1, -1)));
        return dfs(n,k,row,column,dp);
        
    }
};
