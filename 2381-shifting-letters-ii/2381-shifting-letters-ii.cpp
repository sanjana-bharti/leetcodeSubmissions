class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n,i,j,l,r,d,c;
        n=s.length();
        vector<int> calculateShifts(n,0);
        for(i=0;i<shifts.size();i++)
        {
            l=shifts[i][0];
            r=shifts[i][1];
            d=shifts[i][2];
            if(d==0)
                c=-1;
            else
                c=1;
                calculateShifts[l]+=c;
            if(r+1<n)
                calculateShifts[r+1]-=c;
        }
        for(i=0;i<n;i++)
        {
            //cout << calculateShifts[i]  << " ";
            if(i!=0)
                calculateShifts[i]+=calculateShifts[i-1];
            
        }
        for(i=0;i<n;i++)
        {
            calculateShifts[i]%=26;
             d=(((int)s[i])+calculateShifts[i]);
            if(d>122)
                d-=26;
            if(d<97)
                d+=26;
            s[i]=(char)d;
            
        }
        return s;
        
    }
};