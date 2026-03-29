class Solution {
public:
    bool canBeEqual(string S1, string S2) {
        string S1_even = {S1[0], S1[2]};
        string S1_odd = {S1[1], S1[3]};

         string S2_even = {S2[0], S2[2]};
         string S2_odd =  {S2[1], S2[3]};

         sort(S1_even.begin(), S1_even.end());
         sort(S1_odd.begin(), S1_odd.end());
         sort(S2_even.begin(), S2_even.end());
         sort(S2_odd.begin(), S2_odd.end());

         return(S1_even == S2_even) && (S1_odd == S2_odd);
    }
};