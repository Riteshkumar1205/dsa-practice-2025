class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        int n = height.size();
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                
                if(st.empty()) break; // no left boundary
                
                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                
                water += distance * boundedHeight;
            }
            st.push(i);
        }
        
        return water;
    }
};
