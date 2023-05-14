class Solution {
private:
    bool bfs(vector<vector<int>> graph, int node, vector<int> &vist, int col)
    {
        queue<pair<int, int>> q;
        q.push({node, col});
        vist[node] = col;
        
        while(!q.empty())
        {
            int qNode = q.front().first;
            int qCol = q.front().second;
            q.pop();
            
            for(auto it: graph[qNode])
            {
                if(vist[it] == -1)
                {
                    q.push({it, !qCol});
                    vist[it] = !qCol;
                }
                else if(vist[it] == qCol)
                {
                    return false;
                }
            }
        }
        
        return true;  
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vist(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(vist[i] == -1)
            {
                if(bfs(graph, i, vist, 0) == false) return false;
            }
        }
        
        return true;
    }
};