class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adjList[n];
        
        for(auto it : flights)
        {
            // {src, dst, wt}
            adjList[it[0]].push_back({it[1], it[2]});
        }
        // <stops, <node, dist>>
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        vector<int> dist(n, 1e9);
        
        pq.push({0, {src, 0}});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int distance = pq.top().second.second;
            pq.pop();
            
            if(stops > k) continue;
            for(auto it : adjList[node])
            {
                int adjNode = it.first;
                int adjDist = it.second;
                if((distance+adjDist < dist[adjNode]) && (stops <= k))
                {
                    pq.push({stops+1, {adjNode, (distance+adjDist)}});
                    dist[adjNode] = distance+adjDist;
                }
            }            
        }
        
        if(dist[dst] == 1e9)
            return -1;
        
        return dist[dst];
    }
};