class Solution {
public:
    bool shareEdge(vector<int>& stone1,vector<int>& stone2)
    {
        if(stone1[0]==stone2[0]||stone1[1]==stone2[1])
            return true;
        return false;
    }
    void dfs(map<int,vector<int>>& mp,vector<int>& visited,int s)
    {
        visited[s]=1;
        vector<int> adj=mp[s];
        int i;
        for(i=0;i<adj.size();i++)
        {
            if(!visited[adj[i]])
                dfs(mp,visited,adj[i]);
        }
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n=stones.size();
        int i,j;
        map<int,vector<int>> adj;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(shareEdge(stones[i],stones[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int components=0;
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                components++;
                dfs(adj,visited,i);
            }
        }
        return n-components;
        
    }
};