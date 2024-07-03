class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 0);

        candies[0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] = candies[i-1] + 1;
            }
            else
            {
                candies[i] = 1;
            }
        }

        int numOfCandies = candies[n-1];
        for(int i = n-2;i >=0; i-- )
        {
            if(ratings[i] > ratings[i+1])
            {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
            numOfCandies += candies[i];
        }

        return numOfCandies;
    }
};