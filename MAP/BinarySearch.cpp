/*
#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]){
            start = mid + 1;
        }
        else {
            end = mid -1;
        }
        mid = start + (end - start) / 2;
    }
}
int main(){
    int even[5] = {2,4,8,9,13};

    cout << "Index of 9 is : " << binarySearch(even, 5, 9) << endl;

    return 0;
}
    */

    #include<iostream>
    using namespace std;

    int binarySearch(int arr[], int size, int key){
        int start = 0;
        int end = size - 1;

        int mid = start + (end - start) / 2;

        while (start <= end) {
            if(arr[mid] == key) {
                return mid;
            }
            if(key > arr[mid]) {
                start = mid + 1;
            }
            else {
                return end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
    }
    int main() {
        int even[6] = {4,5,6,7,8,9};
        cout << "Index of 7 is: " << binarySearch(even,6,9) << endl;
        return 0;
    }