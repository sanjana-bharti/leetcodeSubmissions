class Solution {
public:
    int maxm=INT_MIN;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m,n,i,j;
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                    
                    maxm=max(maxm,dfs(matrix,i,j,dp));
                
            }
        }
        
        return maxm;
    }
    bool isValid(int x,int y,int m,int n,vector<vector<int>>& arr,int val)
    {
        if(x<0||x>=m||y<0||y>=n)
            return false;
        return arr[x][y]>val;
        
    }
    int dfs(vector<vector<int>>& arr, int i, int j,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int m,n;
        m=arr.size();
        n=arr[0].size();
        int ans=0,x,y;
        x=i+1,y=j;
        if(isValid(x,y,m,n,arr,arr[i][j]))
        ans=dfs(arr,x,y,dp);
         
        x=i,y=j+1;
         if(isValid(x,y,m,n,arr,arr[i][j]))
        ans=max(ans,dfs(arr,x,y,dp));
        
        
        x=i-1,y=j;
         if(isValid(x,y,m,n,arr,arr[i][j]))
        ans=max(ans,dfs(arr,x,y,dp));
        
        x=i,y=j-1;
         if(isValid(x,y,m,n,arr,arr[i][j]))
        ans=max(ans,dfs(arr,x,y,dp));

        ans=ans+1;  
        dp[i][j]=ans;
        return ans;
    }
};