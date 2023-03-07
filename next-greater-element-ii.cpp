class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(2*n),ans(n,-1);
        for(int i=0;i<n;i++)
        {
            arr[i]=arr[n+i]=nums[i]; //repeating the first half
        }
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=arr[i])
            {
                st.pop();
            }
            if(!st.empty()&&i<n) //storing from n to 1 only
            ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};