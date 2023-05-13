class disJointSet
{
public:
    vector<int> parent, size, rank;
    
    disJointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int findUlParent(int u)
    {
        if(parent[u] == u) return u;
        
        return parent[u] = findUlParent(parent[u]);
    }
    
    void unionByRank(int u, int v)
    {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v)
    {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        
        if(ulp_u == ulp_v)
            return;
        
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disJointSet ds(n);
        int extraEdges = 0;
        
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            
            if(ds.findUlParent(u) == ds.findUlParent(v))
            {
                extraEdges++;
            }
            else
            {
                ds.unionBySize(u, v);
            }
        }
        
        int numOfComponents = 0;
        for(int i = 0; i < n; i++)
        {
            if(ds.parent[i] == i)
                numOfComponents++;
        }
        
        int ans = numOfComponents-1;
        
        if(extraEdges >= ans)
            return ans;
        else
            return -1;
    }
};