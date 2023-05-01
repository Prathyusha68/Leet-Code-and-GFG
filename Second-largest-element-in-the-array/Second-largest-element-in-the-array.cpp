#include <bits/stdc++.h>

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.

    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if ((arr[i] > secondLargest) && (arr[i] != firstLargest))
        {
            secondLargest = arr[i];
        }
    }

    if (secondLargest > INT_MIN)
        return secondLargest;
    else
        return -1;
}