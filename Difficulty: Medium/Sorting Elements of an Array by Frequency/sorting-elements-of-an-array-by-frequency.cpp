//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    struct comparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b)
        {
            //cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minH;
        
        for(auto it : mp)
        {
            minH.push({it.second, it.first});
        }
        
        vector<int> ans;
        while(minH.size())
        {
            for(int i = 0; i < minH.top().first; i++)
            {
                ans.push_back(minH.top().second);
            }
            minH.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends