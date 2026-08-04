class Solution {
public:
    std::vector<int> findMissingElements(vector<int>& nums) {
     int min_val = nums[0];
     int max_val = nums[0];
     std::unordered_set<int> num_set;

     for(int num : nums){
        min_val = std::min(min_val, num);
        max_val = std::max(max_val,num);
        num_set.insert(num);
     }   
     std::vector<int> missing;
     for(int i = min_val + 1; i < max_val;i++){
        if(num_set.find(i) == num_set.end()){
            missing.push_back(i);
        }
     }
     return missing;
    }
};