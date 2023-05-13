//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class disJointSet
{
    vector<int> parent, size, rank;
public:
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
    bool isValid(int adjRow, int adjCol, int n, int m)
    {
        return (adjRow >=0 && adjRow < n && adjCol >= 0 && adjCol < m);
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        vector<int> ans;
        int cnt = 0;
        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};
        
        disJointSet ds(n*m);

        for(auto it : operators)
        {
            int r = it[0];
            int c = it[1];
            
            if(vis[r][c] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[r][c] = 1;
            cnt++;
            for(int i = 0; i < 4; i++)
            {
                int adjRow = r + di[i];
                int adjCol = c + dj[i];
                int node = r * m + c;
                int adjNode = adjRow * m + adjCol;
                
                if(isValid(adjRow, adjCol, n, m) && (vis[adjRow][adjCol] == 1))
                {
                    if(ds.findUlParent(node) != ds.findUlParent(adjNode))
                    {
                        cnt--;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends