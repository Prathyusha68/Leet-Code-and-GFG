//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vec;
        
        // store start and end time as a pair in a vector
        for(int i = 0; i < n; i++)
        {
            vec.push_back(make_pair(start[i], end[i]));
        }
        
        // sort based on end time
        sort(vec.begin(), vec.end(), sortBySec);
        
        // compare end time with next start time 
        int limit = vec[0].second;
        int count = 1;
        for(int i = 1; i < n; i++)
        {
            if(limit < vec[i].first)
            {
                count++;
                limit = vec[i].second;
            }
        }
        
        return count;
    }
    
    bool static sortBySec(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.second < b.second);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends