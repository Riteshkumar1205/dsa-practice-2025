/*
#include <iostream>
using namespace std;

class NStack {
    int *arr;       
    int *top;       
    int *next;      
    int n, s;
    int freeSpot;

public:
    // Constructor
    NStack(int N, int S) {
        n = N;
        s = S;
        
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize all stacks as empty
        for(int i = 0; i < n; i++)
            top[i] = -1;

        // Initialize free list
        for(int i = 0; i < s - 1; i++)
            next[i] = i + 1;
        next[s - 1] = -1;

        freeSpot = 0;
    }

    // Push x into mth stack (1-based index)
    bool push(int x, int m) {
        if(freeSpot == -1) {
            cout << "Stack Overflow\n";
            return false;
        }

        int index = freeSpot;
        freeSpot = next[index];

        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    // Pop from mth stack
    int pop(int m) {
        if(top[m - 1] == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    NStack st(3, 10); // 3 stacks in array of size 10

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);

    cout << st.pop(1) << endl; // 20
    cout << st.pop(2) << endl; // 30
}
*/

#include <iostream>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int n, s;
    int stackSize;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        stackSize = S / N;

        arr = new int[S];
        top = new int[N];

        for(int i = 0; i < N; i++)
            top[i] = -1;
    }

    bool push(int x, int m) {
        if(top[m-1] >= stackSize - 1) {
            cout << "Stack Overflow\n";
            return false;
        }

        top[m-1]++;
        arr[(m-1)*stackSize + top[m-1]] = x;
        return true;
    }

    int pop(int m) {
        if(top[m-1] < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int index = (m-1)*stackSize + top[m-1];
        int value = arr[index];
        top[m-1]--;
        return value;
    }
};

int main() {
    NStack st(3, 9);  // 3 stacks, array size 9

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);

    cout << st.pop(1) << endl; // 20
    cout << st.pop(2) << endl; // 30
}
