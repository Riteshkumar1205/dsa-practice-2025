/*
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;

    int i= 0;
    for(int j=1;j<n;j++){
        if(nums[j] != nums[j-1]){
            nums[i++] = nums[j];
        }
    }
    return i+1;
}
int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int k = removeDuplicates(nums);
    cout << "The array is: " << endl;

    for(int i=0;i<k;i++){
        cout << nums[i] << " ";
    }
    return 0;
}
*/

#include<iostream>
#include<algorithm>
using namespace std;

int removeDuplicates(int arr[], int n){
    if(n == 0) return 0;
     
     sort(arr, arr+n);

    int k = 1;
    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            arr[k++] = arr[i];
        }
    }
    return k;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k = removeDuplicates(arr, n);
    cout << "The array is: " << endl;
    for(int i=0;i<k;i++){
        cout << arr[i] << " ";
    }
    return 0;
}