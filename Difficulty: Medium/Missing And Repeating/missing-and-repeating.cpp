//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int> arr) {
        int xr = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            xr ^= arr[i];
            xr ^= (i+1);
        }
        
        int num = (xr & (xr - 1)) ^ xr;
        int one = 0, zero =0, tmp = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if((arr[i] & num) == 0)
            {
                zero ^= arr[i];
            }
            else
            {
                one ^= arr[i];
            }
            
            if(((i+1) & num) == 0)
            {
                zero ^= (i+1);
            }
            else
            {
                one ^= (i+1);
            }
        }

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == zero) cnt++;
        }

        if (cnt == 2) return {zero, one};
        return {one, zero};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends