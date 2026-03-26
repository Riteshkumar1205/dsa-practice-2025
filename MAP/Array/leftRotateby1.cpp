/*
#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,4,5,6,7,3,8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    int first = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = first;

    //print the array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
*/
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,3,8,5,6,3,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    int first = arr[0];

    for(int i=0;i<n-1;i++){
        swap(arr[i], arr[i+1]);
    }

    arr[n-1] = first;

    cout << "The array is:" <<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}