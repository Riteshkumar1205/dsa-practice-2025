/*
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargestElement(vector<int> &arr){
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int x : arr){
        if(x > largest) {
            secondLargest = largest;
            largest = x;
        }
        else if(x > secondLargest && x != largest) {
            secondLargest = x;
        }
    }
    if(secondLargest == INT_MIN) return -1;
    return secondLargest;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int result = secondLargestElement(arr);
    if(result == -1)
         cout << "There is no second Largest element in the array: " << endl;
         else
          cout << "The second Largest element in the array is: " << result << endl;
          return 0;
}
*/



#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargestElement(vector<int> &arr){
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int x : arr){
        if( x > largest){
            secondLargest = largest;
            largest = x;
        }
        else if(x > secondLargest && x!= largest){
            secondLargest = x;
        }
    }
    return secondLargest;
}
int main(){
    int n;
    cout << "Enter the size of the array: \n" ;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int result = secondLargestElement(arr);
    if(result == INT_MIN)
            cout << "There is no second largest element in the array: " << endl;
            else
            cout << "THe second largest element in the array is: " << result << endl;
            return 0;
}