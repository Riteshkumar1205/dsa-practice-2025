class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) freq2[num]++;
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        if (freq2[oldVal] == 0) freq2.erase(oldVal);

        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int a : nums1) {
            int need = tot - a;
            if (freq2.count(need)) res += freq2[need];
        }
        return res;
    }
};
