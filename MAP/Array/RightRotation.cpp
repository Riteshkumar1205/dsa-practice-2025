#include<iostream>
using namespace std;

void rightRotatebyOne(int arr[], int n){
    int last = arr[n-1];

    for(int i=n-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}
int main(){
    int arr[] = {2,4,1,6,4,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    rightRotatebyOne(arr,n);

    cout << "The array is: " << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}