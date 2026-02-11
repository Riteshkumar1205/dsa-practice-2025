class Solution {
public:
    struct SegTree {
        int n;
        vector<int> mn, mx, lazy;

        SegTree(int n) {
            this->n = n;
            mn.assign(4*n, 0);
            mx.assign(4*n, 0);
            lazy.assign(4*n, 0);
        }

        void push(int node, int start, int end) {
            if(lazy[node] != 0) {
                mn[node] += lazy[node];
                mx[node] += lazy[node];
                if(start != end) {
                    lazy[node*2] += lazy[node];
                    lazy[node*2+1] += lazy[node];
                }
                lazy[node] = 0;
            }
        }

        void update(int node, int start, int end, int l, int r, int val) {
            push(node, start, end);
            if(r < start || end < l) return;

            if(l <= start && end <= r) {
                lazy[node] += val;
                push(node, start, end);
                return;
            }

            int mid = (start + end) / 2;
            update(node*2, start, mid, l, r, val);
            update(node*2+1, mid+1, end, l, r, val);

            mn[node] = min(mn[node*2], mn[node*2+1]);
            mx[node] = max(mx[node*2], mx[node*2+1]);
        }

        int findRightmostZero(int node, int start, int end, int l) {
            push(node, start, end);
            if(end < l || mn[node] > 0 || mx[node] < 0) return -1;

            if(start == end) return start;

            int mid = (start + end) / 2;

            int right = findRightmostZero(node*2+1, mid+1, end, l);
            if(right != -1) return right;

            return findRightmostZero(node*2, start, mid, l);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        SegTree seg(n);

        // Initial contribution
        for(auto &p : pos) {
            int val = p.first;
            int sign = (val % 2 ? 1 : -1);
            int first = p.second[0];
            seg.update(1, 0, n-1, first, n-1, sign);
        }

        int ans = 0;

        for(int l = 0; l < n; l++) {

            int r = seg.findRightmostZero(1, 0, n-1, l);
            if(r != -1) {
                ans = max(ans, r - l + 1);
            }

            int val = nums[l];
            int sign = (val % 2 ? 1 : -1);

            auto &vec = pos[val];
            vec.erase(vec.begin());
            int nextPos = vec.empty() ? n : vec[0];

            seg.update(1, 0, n-1, l, nextPos-1, -sign);
        }

        return ans;
    }
};
