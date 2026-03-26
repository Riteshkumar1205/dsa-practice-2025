/*
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> S;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {
            while (!S.empty() && (i == heights.size() || heights[S.top()] >= heights[i])) {
                int height = heights[S.top()];
                S.pop();
                int width = S.empty() ? i : i - S.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            S.push(i);
        }

        return maxArea;   // ✅ Missing return added
    }
};

int main() {
    Solution Sol;
    vector<int> v = {2,1,5,6,2,3};
    cout << "The Area of Histogram is: " 
         << Sol.largestRectangleArea(v) << endl;
    return 0;
}
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    public:

    int largestArea(vector<int>& heights) {
        stack<int> S;
        int maxArea = 0;

        for(int i = 0; i <= heights.size(); i++) {
            while(!S.empty() && (i == heights.size() || heights[S.top()] > heights[i])) {
                int height = heights[S.top()];
                S.pop();
                int width = S.empty() ? i : i - S.top() - 1;
                maxArea = max(maxArea, height * width);
        }
        S.push(i);
    }
    return maxArea;
}

};
int main() {
    Solution Sol;
    vector<int> V = {2,3,5,6,1,1};
    cout << "Enter the number: " << Sol.largestArea(V) << endl;
    return 0;
}


