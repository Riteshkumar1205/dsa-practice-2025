class Solution {
public:
    struct Event {
        long long y;
        int l, r;
        int type;
        bool operator<(const Event& o) const {
            return y < o.y;
        }
    };

    struct SegTree {
        int n;
        vector<int> cnt;
        vector<long long> len;
        vector<long long>& xs;

        SegTree(int n, vector<long long>& xs)
            : n(n), xs(xs) {
            cnt.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int i, int l, int r) {
            if (cnt[i] > 0)
                len[i] = xs[r] - xs[l];
            else if (l + 1 == r)
                len[i] = 0;
            else
                len[i] = len[i << 1] + len[i << 1 | 1];
        }

        void update(int i, int l, int r, int ql, int qr, int v) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cnt[i] += v;
                pull(i, l, r);
                return;
            }
            int m = (l + r) >> 1;
            update(i << 1, l, m, ql, qr, v);
            update(i << 1 | 1, m, r, ql, qr, v);
            pull(i, l, r);
        }

        long long covered() const {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<Event> events;

        xs.reserve(2 * squares.size());
        events.reserve(2 * squares.size());

        for (auto& s : squares) {
            long long x = s[0], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](long long x) {
            return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
        };

        for (auto& s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            int L = getX(x);
            int R = getX(x + l);
            events.push_back({y, L, R, +1});
            events.push_back({y + l, L, R, -1});
        }

        sort(events.begin(), events.end());

        SegTree st((int)xs.size() - 1, xs);

        struct Slab {
            long long y, dy, width;
        };
        vector<Slab> slabs;
        slabs.reserve(events.size());

        long double totalArea = 0;

        // Sweep
        for (int i = 0; i + 1 < (int)events.size(); i++) {
            st.update(1, 0, st.n, events[i].l, events[i].r, events[i].type);
            long long dy = events[i + 1].y - events[i].y;
            if (dy == 0) continue;

            long long w = st.covered();
            if (w > 0) {
                slabs.push_back({events[i].y, dy, w});
                totalArea += (long double)w * dy;
            }
        }

        long double half = totalArea / 2.0;
        long double cur = 0;

        for (auto& s : slabs) {
            long double area = (long double)s.width * s.dy;
            if (cur + area >= half) {
                return (double)(s.y + (half - cur) / s.width);
            }
            cur += area;
        }

        return (double)slabs.back().y;
    }
};
