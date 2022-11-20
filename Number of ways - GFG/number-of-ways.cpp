//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int helper(int n,vector<long long int>& dp)
    {
        if(dp[n]!=-1)
        return dp[n];
        if(n<=4)
            return dp[n];
            
        dp[n]=helper(n-1,dp)+helper(n-4,dp);
        return dp[n];
    }
    long long int arrangeTiles(int n){
        vector<long long int> dp(n+1,-1);
        int i;
        if(n<=3)
        return 1;
        for(i=1;i<=3;i++)
        {
            dp[i]=1;
        }
        dp[4]=2;
        helper(n,dp);
        return dp[n];
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends