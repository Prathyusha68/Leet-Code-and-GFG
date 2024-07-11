//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    int firstOne(vector<int> arr)
    {
        int low = 0, high = arr.size()-1, ans = -1;
        
        while(low<=high)
        {
            int mid = (low+high) >> 1;
            if(arr[mid] == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxi = -1;
	    int index = -1;
	    for(int i = 0; i < n; i++)
	    {
	        int onePos = firstOne(arr[i]);
	        if(onePos != -1)
	        {
	            if((m-onePos) > maxi)
	            {
    	            maxi = m-onePos;
    	            index = i;
	            }
	        }
	    }
	    
	    return index;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends