#include<iostream>
#include<vector>
using namespace std;

int TrapRainWater(vector<int>& height){
    int n = height.size();
    if(n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int Water = 0;

    while(left <= right){
        if(height[left] >= height[right]){
            if(height[right] >= rightMax){
                rightMax = height[right];
            }
            else {
                Water += rightMax - height[right];
            }
            right--;  // ✅ FIX
        }
        else {
            if(height[left] >= leftMax){
                leftMax = height[left];
            }
            else {
                Water += leftMax - height[left];
            }
            left++;   // ✅ FIX
        }
    }
    return Water;
}

int main(){
    int n;
    cin >> n;

    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin >> height[i];
    }

    int water = TrapRainWater(height);
    cout << "the total water trapped is: " << water << endl;

    return 0;
}