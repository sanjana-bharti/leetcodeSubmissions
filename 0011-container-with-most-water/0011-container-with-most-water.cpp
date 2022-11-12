class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i,j,n,h,w;
        n=height.size();
        i=0;
        j=n-1;
        int area=0;
        while(i<n && j>=0 && i<j)
        {
            h=min(height[i],height[j]);
            w=j-i;
            area=max(area,h*w);
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return area;
        
    }
};