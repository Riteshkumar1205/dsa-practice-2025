class Solution {
public:
    struct Event {
        long long y;
        int x1, x2;
        int type; 
    };

    struct SegTree {
        int n;
        vector<int> cnt;
        vector<long long> len;
        vector<long long> xs;

        SegTree(const vector<long long>& xs) : xs(xs) {
            n = xs.size() - 1;
            cnt.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int idx, int l, int r) {
            if (cnt[idx] > 0) {
                len[idx] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                len[idx] = 0;
            } else {
                len[idx] = len[idx * 2] + len[idx * 2 + 1];
            }
        }

        void update(int idx, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cnt[idx] += val;
                pull(idx, l, r);
                return;
            }
            int m = (l + r) / 2;
            update(idx * 2, l, m, ql, qr, val);
            update(idx * 2 + 1, m, r, ql, qr, val);
            pull(idx, l, r);
        }

        long long covered() const {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<Event> events;

        for (auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](long long x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        for (auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            int x1 = getX(x);
            int x2 = getX(x + l);
            events.push_back({y, x1, x2, +1});
            events.push_back({y + l, x1, x2, -1});
        }

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) {
                 return a.y < b.y;
             });

        SegTree st(xs);

        long double totalArea = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            st.update(1, 0, st.n, events[i].x1, events[i].x2, events[i].type);
            long long dy = events[i + 1].y - events[i].y;
            totalArea += (long double)st.covered() * dy;
        }

        long double half = totalArea / 2.0;

        st = SegTree(xs);
        long double curArea = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            st.update(1, 0, st.n, events[i].x1, events[i].x2, events[i].type);
            long long dy = events[i + 1].y - events[i].y;
            long long width = st.covered();
            if (width == 0) continue;

            long double slab = (long double)width * dy;
            if (curArea + slab >= half) {
                long double need = half - curArea;
                return (double)(events[i].y + need / width);
            }
            curArea += slab;
        }

        return (double)events.back().y;
    }
};
