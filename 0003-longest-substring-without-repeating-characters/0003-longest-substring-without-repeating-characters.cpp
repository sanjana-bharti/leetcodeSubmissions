class Solution {
public:
    int lengthOfLongestSubstring(string str) 
    {
        map<char,int> mp;
        int i,len,last=0,maxm=1;;
        len=str.length();
        if(len==0)
            return 0;
        mp[str[0]]=0;
        for(i=1;i<len;i++)
        {
            if(mp.find(str[i])!=mp.end())
            {
                last=max(last,mp[str[i]]+1);
                // remove everything before it 
            }
            mp[str[i]]=i;
            maxm=max(maxm,i-last+1);
        }
        return maxm;
        
    }
};