class disjointSets
{
    vector<int> parent, rank, size;
public:
    disjointSets(int n)
    {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i =0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    
    int findParent(int p)
    {
        if(p == parent[p])
            return p;
        return parent[p] = findParent(parent[p]);
    }
    
    void unionByRank(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
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
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        disjointSets ds(accounts.size());        
        unordered_map<string, int> mapMailNode;
        
        for(int i = 0; i < accounts.size(); i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                if(mapMailNode.find(accounts[i][j]) == mapMailNode.end())
                {
                    mapMailNode[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionBySize(i, mapMailNode[accounts[i][j]]);
                }
            }
        }
        
        vector<vector<string>> mergeAcc(accounts.size());
        for(auto it : mapMailNode)
        {
            int node = ds.findParent(it.second);
            mergeAcc[node].push_back(it.first);
        }
        
        vector<vector<string>> ans;

        for(int i = 0; i < accounts.size(); i++)
        {
            if(mergeAcc[i].size() == 0) continue;

            sort(mergeAcc[i].begin(), mergeAcc[i].end());

            vector<string> tmp;

            tmp.push_back(accounts[i][0]);

            for(auto it : mergeAcc[i])
            {
                tmp.push_back(it);
            }

            ans.push_back(tmp);
        }

        sort(ans.begin(), ans.end(), greater<vector<string>>());

        return ans;
        
    }
};