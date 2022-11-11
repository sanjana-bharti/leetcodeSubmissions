class Solution {
public:
    string longestPalindrome(string s) {
        
        int i,j,n,gap,len=0;
        n=s.length();
        string ans="";
        vector<vector<int>> dp(n,vector<int> (n));
        for(gap=0;gap<s.length();gap++)
        {
            for(i=0,j=gap;i<s.length() && j<s.length();i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=true;
                }
                else if(gap==1)
                {
                        dp[i][j]=(s[i]==s[j]);
                }
                else 
                {
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]==true)
                {
                    if(gap>=len)
                    {
                        len=gap;
                        ans=s.substr(i,gap+1);
                    }
                }
            }
        }
        return ans;
    }
};