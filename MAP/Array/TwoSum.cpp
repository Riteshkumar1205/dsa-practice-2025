#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> mp;

    for(int i=0;i<nums.size();i++){
        int complement = target - nums[i];

        if(mp.find(complement) != mp.end()){
            return {mp[complement],i};
        }
        mp[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {3,5,2,6,7,9,23};
    int target = 11;

    vector<int> result = twoSum(nums, target);
    cout << "Indices of the elements that sum is: " << result[0] << " and " << result[1] << endl;
    return 0;
}