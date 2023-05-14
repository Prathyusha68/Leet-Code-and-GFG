class Solution {
private:
    void toposort(int K, vector<int> adjList[], vector<int> &topo)
    {
        int inDegree[K+1];
        memset(inDegree, 0, sizeof(inDegree));
        
        for(int i = 0; i < K; i++)
        {
            for(auto it : adjList[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < K; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it : adjList[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        vector<int> topo;
        
        for(auto it: prerequisites)
        {
            adjList[it[1]].push_back(it[0]);            
        }
        
        toposort(numCourses, adjList, topo);

        if(topo.size() != numCourses)
            return {};
        
        return topo;
    }
};