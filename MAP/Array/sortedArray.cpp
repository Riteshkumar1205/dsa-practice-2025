/*
#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[] = {2,4,3,5,6,7,9};
    int n = 5;

    if(isSorted(arr,n)) {
        cout << "The array is sorted: " << endl;
    }
    else {
        cout << "The array is not sorted:" << endl;
    }
    return 0;
}
*/
#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[] = {2,4,5,6,7,8,9};
    int n = 7;

    if(isSorted(arr,n)){
        cout << "THe array is sorted: " << endl;
    }
    else {
        cout << "The array is not the sorted array: " << endl;
    }
    return 0;
}

