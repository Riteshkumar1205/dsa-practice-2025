#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:

    int largestElement(vector<int> &nums){
         int max = nums[0];

         for(int i = 0;i<nums.size();i++){
            if(nums[i] > max){
                max = nums[i];
            }
         }
         return max;
    }
};
int main(){
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0;i<n;i++){
        cin >> nums[i];

        cout << "The largest elements in the array is: " << Solution().largestElement(nums) << endl;
    }
    return 0;
}