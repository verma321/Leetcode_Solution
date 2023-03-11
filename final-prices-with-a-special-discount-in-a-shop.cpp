class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=prices[i];
            while(!st.empty()&&st.top()>prices[i])
            {
                st.pop();
            }
            if(!st.empty())
            ans[i]-=st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};