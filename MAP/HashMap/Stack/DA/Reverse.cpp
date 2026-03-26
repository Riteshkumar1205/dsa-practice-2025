/*
#include<iostream>
using namespace std;
int main () {
    int arr[5];

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    for(int  i = 0;i < 5;i++) {
        cout << arr[i] << " ";
    }
}
    */

    //initilizer list

    #include<iostream>
    using namespace std;

    int main() {
        int arr[] = {1,5,6,3,4,5,3,8,6,4,2,4,5,6,};

        int n = sizeof(arr)/ sizeof(arr[0]);
        for(int i = 0; i < n - 1; i++) {
            cout << arr[i] << " ";
        }
    }