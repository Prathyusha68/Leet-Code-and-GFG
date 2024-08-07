//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, sortByValuePerWt);
        
        double maxVal = 0.0;
        int currWt = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].weight <= W)
            {
                W -= arr[i].weight;
                maxVal += arr[i].value;
            }
            else
            {
                //int remain = W - currWt;
                maxVal += (arr[i].value/(double)arr[i].weight) * (double)W;
                break;
            }
        }
        
        return maxVal;
    }
        
    bool static sortByValuePerWt(Item a, Item b)
    {
        return (((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight));
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends