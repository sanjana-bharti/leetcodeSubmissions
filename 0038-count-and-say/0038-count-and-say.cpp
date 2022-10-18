class Solution {
public:
    string fun(string str,int n,int k)
    {
        if(n>k)
            return str;
        int len,i;
        len=str.length();
        char last=str[0];
        char current=str[0];
        int count=1;
        string newStr="";
        string c;
        for(i=1;i<len;i++)
        {
            current=str[i];
            if(current==last)
            {
             count++;   
            }
            else
            {
                c=to_string(count);
                newStr+=c+last;
                count=1;
            }
            last=str[i];
        }
        c=to_string(count);
        //cout << c << " - " << current << " ";
        newStr+=c+current;
        return fun(newStr,n+1,k);
    }
    string countAndSay(int n) {
        if(n==1)
            return "1";
        else return fun("1",2,n);
    }
};