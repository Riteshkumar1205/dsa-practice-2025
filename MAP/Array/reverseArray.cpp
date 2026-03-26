/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr = {1,3,4,5,6,6,7};
    
    reverse(arr.begin(), arr.end());

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   vector<int> arr = {2,3,5,6,7,3};
   
   reverse(arr.begin(), arr.end());

   for(int x : arr){
    cout << x << " ";
   }
   return 0;
}