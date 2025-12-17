class Solution {
public:
    void CombinationDisplay(vector<int>& arr, int r) {
        int n = arr.size();
        vector<int> data(r);
        makeCombination(arr, data, 0, n - 1, 0, r);
    }

private:
    void makeCombination(vector<int>& arr, vector<int>& data, int start, int end, int index, int r) {
        if (index == r) {
            for (int j = 0; j < r; j++)
                cout << data[j] << " ";
            cout << endl;
            return;
        }

        for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
            data[index] = arr[i];
            makeCombination(arr, data, i + 1, end, index + 1, r);
        }
    }
};

int main() {
    vector<int> arr = {1, 5, 4, 6, 8};
    int r = 4;

    cout << "The given array is:\n";
    for (int num : arr) cout << num << " ";
    cout << "\n\nCombinations of " << r << " elements are:\n";

    Solution sol;
    sol.CombinationDisplay(arr, r);

    return 0;
}
