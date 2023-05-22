//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool canWePlaceKCows(int n, int noOfCows, vector<int> stalls, int minDist)
    {
        int placedCows = 1, prev = stalls[0];
        
        for(int i = 1; i < n; i++)
        {
            if(stalls[i] - prev >= minDist)
            {
                placedCows++;
                prev = stalls[i];
            }
            
            if(placedCows >= noOfCows)
                return true;
        }
        
        if(placedCows >= noOfCows)
                return true;
                
        return false;
    }
    
public:

    int solve(int n, int k, vector<int> &stalls) {
        
        if(k > n)
            return -1;
            
        sort(stalls.begin(), stalls.end());
        
        int start = 1, end = stalls[n-1] - stalls[0];
        int res = -1;
        while(start <= end)
        {
            int mid = (start+end) >> 1;
            
            if(canWePlaceKCows(n, k, stalls, mid))
            {
                res = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends