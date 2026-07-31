class Solution {
public:
    int minimumPushes(string word) {
      std::vector<int> count(26,0);
      for(char c: word){
        count[c - 'a']++;
      }  
      std::sort(count.begin(), count.end(), std::greater<int>());
      int totalPushes = 0;
      for(int i=0;i<26;i++){
        if(count[i] == 0)break;
        int multiplier = (i / 8) + 1;
        totalPushes += count[i] * multiplier;
      }
      return totalPushes;
    }
};