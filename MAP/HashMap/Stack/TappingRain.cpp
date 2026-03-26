#include <bits/stdc++.h>
using namespace std;

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
                
                if(st.empty()) break;
                
                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                
                water += distance * boundedHeight;
            }
            st.push(i);
        }
        
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << endl; // Output should be 6
    return 0;
}
