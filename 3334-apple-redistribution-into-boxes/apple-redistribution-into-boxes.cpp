class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        
        for (int a : apple) {
            totalApples += a;
        }
        
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        int usedCapacity = 0;
        int boxCount = 0;
        
        for (int cap : capacity) {
            usedCapacity += cap;
            boxCount++;
            
            if (usedCapacity >= totalApples) {
                return boxCount;
            }
        }
        
        return boxCount; 
    }
};
