class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int n=heights.size();
        vector<int>next_smallest_left(n),next_smallest_right(n),total_span(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            next_smallest_right[i]=s.top()-i;
            else
            next_smallest_right[i]=n-i;
            s.push(i);
        }

        while(!s.empty())
        s.pop();

        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            next_smallest_left[i]=i-s.top()-1;
            else 
            next_smallest_left[i]=i;
            s.push(i);
        }
        
        int max_area=0;
        for(int i=0;i<n;i++)
        {
            total_span[i]=next_smallest_left[i]+next_smallest_right[i];
            total_span[i]*=heights[i];
            max_area=max(max_area,total_span[i]);
        }
        return max_area;
    }
};