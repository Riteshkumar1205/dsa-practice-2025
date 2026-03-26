/*
#include<iostream>
using namespace std;

int firstOccur(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;       // store index
            end = mid - 1;   // look for first occurrence on the left
        }
        else if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int even[5] = {2, 3, 3, 5, 6};
    cout << "First Occurrence of 3 is: " << firstOccur(even, 5, 3) << endl;
    return 0;
}
*/
#include<iostream>
using namespace std;

int firstOccur(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) /2;
        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        }
        else if(key > arr[mid]){
            start = mid  + 1;
        }
        else {
            end = mid - 1;
        }
    }
}
int main() {
    int even[5] = {4,5,6,7,8};
    cout << "First Occurence of 7 is: " << firstOccur(even, 5,7) << endl;
    return 0;
}
