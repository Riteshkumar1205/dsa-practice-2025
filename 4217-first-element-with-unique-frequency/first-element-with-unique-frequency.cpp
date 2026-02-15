class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
      unordered_map<int, int> freq;
      unordered_map<int, int> freqCount;

        for(int num : nums) {
            freq[num]++;
        }
        for(auto &p : freq) {
            freqCount[p.second]++;
        }
        for(int num : nums) {
            if(freqCount[freq[num]] == 1) {
                return num;
            }
        }
        return -1;
    }
};