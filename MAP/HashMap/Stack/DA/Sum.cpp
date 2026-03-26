/*
#include<iostream>
using namespace std;

int main() {
    int arr[] = {4,2,5,6,8,7,5,4,68,1,2};

    int n = sizeof(arr)/ sizeof(arr[0]);
    
    int sum = 0;
    for(int i = 0; i < n ;i++) {
        sum +=  arr[i];
    }
    cout << sum << " ";
}
    

   #include<iostream>
   using namespace std;
   
   int main() {
    int arr[] = {4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int product = 1;

    for(int i = 0; i < n; i++) {
        product *= arr[i];
    }
    cout << product << " ";
   }
    
 
    // search for an element in the array
#include<iostream>
using namespace std;

int main() {
   int arr[] = {4,6,8,9,5,2,3,4};

   int n = sizeof(arr) / sizeof(arr[0]);

   int x = 0;
   cout << "Enter the element to the search: " << endl;
   cin >> x;

   for(int  i = 0; i < n; i++) {
    if(arr[i] == x) {
        cout << "Elements found at index: " << i << endl;
        break;
    }
   }
}
   */

   //search for an element in the array
  #include<iostream>
  using namespace std;

  int main() {
    int arr[] = {4,5,62,4,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x  = 0;
    cout << "Enter the element to search: " << endl;
    cin >> x;

    for(int i = 0;i < n;i++ ){
        if(arr[i] == x){
        cout << "Element found at the index: " << i << endl;
        break;
    }
  }
}