//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans(2, 0);
        sort(arr, arr+n, sortByProfit); // sort Job based on profit
        
        // find out max dead line
        int maxDeadLine = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            maxDeadLine = max(maxDeadLine, arr[i].dead);
        }

        vector<int> jobSeq(maxDeadLine, -1);
        
        int count = 0, maxProfit = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = arr[i].dead-1; j >= 0; j--)
            {
                if(jobSeq[j] == -1)
                {
                    count++;
                    jobSeq[j] = arr[i].id;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        ans[0] = count;
        ans[1] = maxProfit;
        
        return ans;
    } 
    
    bool static sortByProfit(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends