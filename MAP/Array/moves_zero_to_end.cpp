/*
#include<iostream>
using namespace std;

void moveZeros(int arr[], int n){
    int j = 0;

    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            arr[j++] = arr[i];
        }
    }
    while(j < n){
        arr[j++] = 0;
    }
}
int main(){
    int arr[] = {0,2,3,0,1,3,0,5};
    int n = sizeof(arr)/ sizeof(arr[0]);

    moveZeros(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

//Move all the zero to the end of the array while maintaining the order of non-zero elements.

#include<iostream>
using namespace std;

void moveZeros(int arr[], int n){
    int j = 0;

    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j++]);
        }
    }
}
int main(){
    int arr[] = {0,2,3,0,4,50,7,0,8};
    int n = sizeof(arr)/ sizeof(arr[0]);

    moveZeros(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
    */
   #include<iostream>
   using namespace std;

   void moveZeros(int arr[], int n){
    int j= 0;

    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j++]);
        }
    }
   }
   int main(){
    int arr[] = {2,3,1,0,4,7,0,3,2,0,4,3,0,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeros(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
   }