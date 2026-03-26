#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:

    int smallestElement(vector<int> &nums){
         int min = nums[0];

         for(int i = 0;i<nums.size();i++){
            if(nums[i] < min){
                min = nums[i];
            }
         }
         return min;
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

        cout << "The smallest elements in the array is: " << Solution().smallestElement(nums) << endl;
    }
    return 0;
}