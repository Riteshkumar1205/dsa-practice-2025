#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

bool pairInSortedRotated(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = findPivot(nums);
    int l = pivot;
    int r = (pivot - 1 + n) % n;

    while (l != r) {
        int sum = nums[l] + nums[r];
        if (sum == target)
            return true;
        else if (sum < target)
            l = (l + 1) % n;
        else
            r = (n + r - 1) % n;
    }
    return false;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements of the sorted and rotated array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target sum: ";
    cin >> target;

    if (pairInSortedRotated(nums, target))
        cout << " Pair exists with sum " << target << endl;
    else
        cout << " No such pair found" << endl;

    return 0;
}
