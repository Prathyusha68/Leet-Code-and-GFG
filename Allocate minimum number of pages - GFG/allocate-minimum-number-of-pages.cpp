//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    private:
    
    bool isAllocationPossible(int A[], int N, int noOfStud, int maxPages)
    {
        int allocStud = 1, pages = 0;
        for(int i = 0; i < N; i++)
        {
            if(A[i] > maxPages)
                return false;
                
            if(pages+A[i] > maxPages)
            {
                pages = A[i];
                allocStud++;
            }
            else
            {
                pages += A[i];
            }
        }
        
        if(allocStud > noOfStud)
            return false;
            
        return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int start = INT_MAX, end = 0;
        
        if(M > N)
            return -1;
            
        for(int i = 0; i < N; i++)
        {
            end += A[i];
            start = min(start, A[i]);
        }
        
        int res = -1; 
        while(start <= end)
        {
            int mid = (start + end) >> 1;
            if(isAllocationPossible(A, N, M, mid))
            {
                res = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends