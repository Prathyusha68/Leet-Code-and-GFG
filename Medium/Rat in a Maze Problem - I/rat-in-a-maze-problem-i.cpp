//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, 1, -1};
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        if(m[0][0] == 1)
        {
            vis[0][0] = 1;
            solve(m, n, 0, 0, di, dj, vis, "", ans);
        }
            
        return ans;
    }
    
    void solve(vector<vector<int>> &m, int n, int x, int y, int di[], int dj[],
                   vector<vector<int>> &vis, string s, vector<string> &ans )
    {
        if((x == n-1) && (y == n-1))
        {
            ans.push_back(s);
            return;
        }
        
        string t = "DURL";
        for(int i = 0; i < 4; i++)
        {
            int nextX = di[i]+x;
            int nextY = dj[i]+y;
            if((nextX >= 0) && (nextX < n) && (nextY >= 0) && (nextY < n) && (!vis[nextX][nextY]) && (m[nextX][nextY] == 1))
            {
                vis[nextX][nextY] = 1;
                solve(m, n, nextX, nextY, di, dj, vis, s+t[i], ans);
                vis[nextX][nextY] = 0;
            }
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends