class Solution {
public:
    int findNum(int t,int l,int r,vector<int>& nums)
    {
        int i;
        for(i=l;i<=r;i++)
        {
            if(nums[i]==t)
                return i;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i,n,x,y,z;
        n=nums.size();
        vector<int> res;
        for(i=0;i<n;i++)
        {
            x=nums[i];
            y=target-x;
            z=findNum(y,i+1,n-1,nums);
            if(z!=-1)
               res={i,z}; 
            
        }
        return res;
    }
    
};