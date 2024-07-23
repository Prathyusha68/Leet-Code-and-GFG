class StockSpanner {
    stack<pair<int,int>> st;
    int count;
public:
    StockSpanner() {
        count = -1;
    }
    
    int next(int price) {
        int ans = 0;
        count++;

        while((!st.empty()) && (st.top().second <= price))
        {
            st.pop();
        }

        if(!st.empty())
        {
            ans =  (count - st.top().first); 
        }
        else
        {
            ans = count +1;
        }

        st.push({count, price});
    
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */