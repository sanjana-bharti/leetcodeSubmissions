class Solution {
public:
    map<string,vector<vector<string>>> dp;
    vector<vector<string>> partition(string s) 
    {
        dp.clear();
        helper(s);
        return dp[s];
    }
    bool isPalindrome(string s)
    {
        int n,i,j;
        n=s.length();
        i=0;
        j=n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    vector<vector<string>> helper(string s)
    {
        if(dp.find(s)!=dp.end())
            return dp[s];
        int i,j,k,n;
        n=s.length();
        string str1,str2;
        vector<vector<string>> res;
        vector<string> vec;
        if(n<=1)
        {
            
            if(n==1)
                vec.push_back(s);
            dp[s].push_back(vec);
            return dp[s];
        }
        
        
        for(i=0;i<n;i++)
        {
            str1=s.substr(0,i+1);
            str2=s.substr(i+1,n-i-1);
            if(isPalindrome(str1))
            {
                //cout << str1 << " " << str2 << "\n";
                res=helper(str2);
                for(j=0;j<res.size();j++)
                {
                    vec=res[j];
                    vec.insert(vec.begin(),str1);
                    dp[s].push_back(vec);
                }
            }
        }
        return dp[s];
    }
    
};