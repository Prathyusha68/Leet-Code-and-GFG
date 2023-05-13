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
private:
    bool isValid(int adjRow, int adjCol, int n)
    {
        return (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < n);
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disJointSet ds(n * n);
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {   
                if(grid[i][j] == 0)
                    continue;
                
                int node = i*n+j;
                
                for(int k = 0; k < 4; k++)
                {
                    int adjRow = i + di[k];
                    int adjCol = j + dj[k];
                    
                    if(isValid(adjRow, adjCol, n) && (grid[adjRow][adjCol] == 1))
                    {
                        int adjNode = adjRow * n + adjCol;
                        
                        if(ds.findUlParent(adjNode) != ds.findUlParent(node))
                        {
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        
        int largeIsland = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {   
                if(grid[i][j] == 1)
                    continue;
                
                set<int> parentNodesSet;
                for(int k = 0; k < 4; k++)
                {
                    int adjRow = i + di[k];
                    int adjCol = j + dj[k];
                    
                    if(isValid(adjRow, adjCol, n) && (grid[adjRow][adjCol] == 1))
                    {
                        int adjNode = adjRow * n + adjCol;
                        int parentNode = ds.findUlParent(adjNode);
                        parentNodesSet.insert(parentNode);
                    }
                }
                
                int island = 1; 
                for(auto it : parentNodesSet)
                {
                    island += ds.size[it];
                }
                
                largeIsland = max(largeIsland, island);
            }
        }
        
        int allOnesIsland = 0;
        for(int i = 0; i < n; i++)
        {
            largeIsland = max(largeIsland, ds.size[i]);  
        }
        
        return largeIsland;       
    }
};