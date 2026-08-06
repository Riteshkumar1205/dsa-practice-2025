class Solution {
public:
    int smallestNumber(int n, int t) {
       auto getDigitProduct = [](int num){
        int product = 1;
        while(num > 0){
            product *= (num % 10);
            num /= 10;
        }
        return product;
       } ;
       for(int curr = n; ; curr++){
        if(getDigitProduct(curr)%t == 0){
            return curr;
        }
       }
    }
};