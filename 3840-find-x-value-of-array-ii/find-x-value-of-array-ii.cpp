class Solution {
    struct Node {
        int prod;
        array<int, 5> count;

        Node() : prod(1) {
            count.fill(0);
        }
    };

    int n, K;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;
        
        for (int r = 0; r < K; ++r) {
            res.count[r] = left.count[r];
        }

        for (int r = 0; r < K; ++r) {
            if (right.count[r] > 0) {
                int rem = (left.prod * r) % K;
                res.count[rem] += right.count[r];
            }
        }
        
        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int val = nums[l] % K;
            tree[node].prod = val;
            tree[node].count[val] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node].count.fill(0);
            int v = val % K;
            tree[node].prod = v;
            tree[node].count[v] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        }
        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        }
        Node leftRes = query(2 * node, l, mid, ql, qr);
        Node rightRes = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(leftRes, rightRes);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        tree.resize(4 * n);
        
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);
            
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.count[x]);
        }

        return ans;
    }
};