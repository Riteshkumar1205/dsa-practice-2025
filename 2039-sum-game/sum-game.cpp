class Solution {
    public:
    bool sumGame(string num){
        int n = num.size();
        int sum_diff = 0;
        int q_diff = 0;

        for(int i=0;i < n/2; i++){
            if(num[i] == '?'){
                q_diff++;
            } else {
                sum_diff += (num[i] - '0');
            }
        }
        for(int i=n/2; i < n; i++){
            if(num[i] == '?') {
                q_diff--;
            }
            else {
                sum_diff -= (num[i] - '0');
            }
        }
        return (sum_diff * 2 != -q_diff *9);
    }
};