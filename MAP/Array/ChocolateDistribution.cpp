/*
#include<bits/stdc++.h>
using namespace std;

int chocolateDistribution(int arr[], int n, int m) {
    
    //Edge case:
    if(m == 0 || n == 0) return 0;
    if(m > n) return -1;

    //Sort the array:
    int Ans = INT_MAX;
    //check window size 

    for(int i=0;i+m-1 < n;i++){
        int diff = arr[i+m-1] - arr[i];
        Ans = min(Ans, diff);
    }
    return Ans;
}
int main(){
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int m = 3;

    int ans = chocolateDistribution(arr, n, m);
    cout << "The minimum difference is: " << ans << endl;
    return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int chocolateDistribution(vector<int>& arr, int m){
    int n = arr.size();

    // Edge case:
    if(m == 0 || n == 0) return 0;
    if(m > n) return -1;

    // Sort the array:

    sort(arr.begin(), arr.end());
    cout << "Sorted array is: " << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int Ans = INT_MAX;

    //Check window size of m:

    for(int i=0;i+m-1 < n;i++){
        int diff = arr[i+m -1] - arr[i];
        Ans = min(Ans, diff);
    }
    return Ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans = chocolateDistribution(arr, m);
    cout << "The minimum difference is: " << ans << endl;
    return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int chocolateDistribution(vector<int>& arr, int m){
    int n =arr.size();
    
    //Edge case:

    if( m == 0|| n == 0) return 0;
    if(m > n) return -1;

    // Sort the array: 

    sort(arr.begin(), arr.end());
    cout << "Sorted array is: " << endl;

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int Ans = INT_MAX;

    // Check window size of m:

    for(int i=0;i+m-1 <n;i++){
        int diff = arr[i+m-1] - arr[i];
        Ans = min(Ans, diff);
    }
    return Ans;
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans = chocolateDistribution(arr, m);
    cout << "The minimum difference is: " << ans << endl;
    return 0;
}
