//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> vis(n, 0);
        
        return isGraphCanBeColored(graph, m, n, 0, vis);
    }
    
    bool isGraphCanBeColored(bool graph[101][101], int m, int n, int index, vector<int> &vis)
    {
        if(index == n)
            return true;
        
        for(int i = 1; i <= m; i++)
        {
            vis[index] = i;
            
            if(isSafe(graph, n, index, vis, i) == true)
            {
                if(isGraphCanBeColored(graph, m, n, index + 1, vis) == true)
                    return true;
            }
            
            vis[index] = 0;
        }
        
        return false;
    }
    
    bool isSafe(bool graph[101][101], int n, int index, vector<int> vis, int col)
    {
        for(int i = 0; i < n; i++)
        {
            if((graph[index][i] == 1) && (vis[i] == col))
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends