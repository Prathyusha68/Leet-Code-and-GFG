//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minH;
        
        for(long long i = 0; i < n; i++)
        {
            minH.push(arr[i]);
        }
        
        long long ans = 0;
        while(minH.size() >= 2)
        {
            long long first = minH.top();
            minH.pop();
            long long second = minH.top();
            minH.pop();
            ans += first+second;
            
            minH.push(first+second);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends