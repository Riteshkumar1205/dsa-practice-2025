#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int i =0;
        int j =0;
        int maxSum = INT_MIN;
        int sum = 0;

        while(j < nums.size()){
            sum += nums[j];
            maxSum = max(maxSum, sum);

            if(sum < 0){
                sum = 0;
                i = j + 1;
            }
            j++;
        }
        return maxSum;
    }
};

 int main(){
  Solution s;
  vector<int> arr = {2,-3,4,1,5,6};

  cout << s.maxSubArray(arr);
  return 0;
 }
/*
class Solution {
public:
    int maxSubArray(vector<int>& n) {
        int i = 0;
        int j = 0;
        int maxSum = INT_MIN;
        int sum = 0;

        while (j < n.size()) {
            sum += n[j];
            maxSum = max(maxSum, sum);   

            if (sum < 0) {              
                sum = 0;
                i = j + 1;
            }
            j++;
        }
        return maxSum;
    }
};
*/