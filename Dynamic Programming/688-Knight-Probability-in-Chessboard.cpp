class Solution {
    double dp[25][25][101];
    int dx[8]={2,2,-2,-2,1,1,-1,-1};
    int dy[8]={1,-1,1,-1,2,-2,2,-2};

    double dfs(int n,int k,int r,int c){

        if(r<0 || c<0 || r>=n || c>=n)
            return 0;

        if(k==0)
            return 1;

        if(dp[r][c][k] >= 0)
            return dp[r][c][k];

        double ans=0;

        for(int i=0;i<8;i++)
            ans += dfs(n,k-1,r+dx[i],c+dy[i])/8.0;

        return dp[r][c][k]=ans;
    }

public:
    double knightProbability(int n, int k,
                             int row, int column) {

        memset(dp,-1,sizeof(dp));

        return dfs(n,k,row,column);
    }
};
