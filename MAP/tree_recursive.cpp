#include<iostream>
using namespace std;
 
void fun(int n){
    if(n > 0) {
        cout << n << " ";
        fun(n-1);
        fun(n-2);
    }
}

int main() {
    int a = 5;
    fun(a);
    return 0;
}