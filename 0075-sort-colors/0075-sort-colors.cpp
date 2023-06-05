class Solution {
public:
    void sortColors(vector<int>& arr) {
        int a[3] = {};
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            a[arr[i]]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(a[0] > 0)
            {
                arr[i] =0;
                a[0]--;
            }
            else if(a[1] >0)
            {
                arr[i] =1;
                a[1]--;
            }
            else if(a[2] >0)
            {
                arr[i] =2;
                a[2]--;
            }
        }
    }
};