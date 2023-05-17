#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> adjList[n];
        vector<ll> dist(n, LONG_MAX), ways(n, 0);
        priority_queue<pair<ll, ll>,
            vector<pair<ll, ll>>,
            greater<pair<ll, ll>>> pq;

        int mod = int(1e9 +7);
        
        for(auto it : roads)
        {
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        
        pq.push({0, 0});

        dist[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty())
        {
            ll node = pq.top().second;
            ll distance = pq.top().first;
            pq.pop();
            
            for(auto adjIter : adjList[node])
            {
                ll adjNode = adjIter.first;
                ll adjDist = adjIter.second;
  
                if(distance+adjDist < dist[adjNode])
                {
                    dist[adjNode] = distance+adjDist;
                    pq.push({distance+adjDist, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(distance+adjDist == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1] % mod; 
    }
};