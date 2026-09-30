class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxar=0;
        for(int i=0;i<=n;i++){
            int curr = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()]>curr){
                int h=heights[st.top()];
                st.pop();
                int right=i;
                int left=st.empty() ? -1 : st.top();
                int wi=right-left-1;
                maxar=max(maxar,h*wi);
            }
        st.push(i);
        }
    return maxar;
    }
};