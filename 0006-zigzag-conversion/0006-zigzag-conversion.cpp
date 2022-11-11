class Solution {
public:
    string convert(string s, int numRows) 
    {
        int n,i,j,k=0;
        n=s.length();
        if(numRows==1)
            return s;
        if(numRows>n)
            return s;
        vector<vector<char>> ans(numRows,vector<char> (n,'*'));
        i=0;
        j=0;
        while(j<n && i<numRows && k<n)
        {
            while(i>=0 && i<numRows && k<n)
            {
                ans[i][j]=s[k];
                k++;
                i++;
            }
            i=numRows-2;
            j++;
            while(i>=0 && j<n && k<n)
            {
                ans[i][j]=s[k];
                i--;
                j++;
                k++;
            }
            i+=2;
            j--;
        }
        string res="";
        for(i=0;i<ans.size();i++)
        {
            for(j=0;j<ans[i].size();j++)
            {
                //cout << ans[i][j] << " ";
                if(ans[i][j]!='*')
                    res=res+ans[i][j];
            }
            //cout << "\n";
        }
        return res;
        
    }
};