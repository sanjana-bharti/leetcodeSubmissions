class Solution {
public:
    bool shareEdge(vector<int>& stone1,vector<int>& stone2)
    {
        if(stone1[0]==stone2[0]||stone1[1]==stone2[1])
            return true;
        return false;
    }
    int find(vector<int>& parent,int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent,parent[x]);
    }
    int performUnion(vector<int>& parent, vector<int>& rank,int x,int y)
    {
        x=find(parent,x);
        y=find(parent,y);
        if(x==y)
            return 0;
        if(rank[x]>=rank[y])
        {
            parent[y]=x;
            rank[x]+=rank[y];
        }
        else
        {
            parent[x]=y;
            rank[y]+=rank[x];
        }
        return 1;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n,i,j;
        n=stones.size();
        vector<int> parent(n);
        vector<int> rank(n);
        for(i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        int components=n;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(shareEdge(stones[i],stones[j]))
                {
                 components-=performUnion(parent,rank,i,j);   
                }
            }
        }
        return n-components;
    }
};