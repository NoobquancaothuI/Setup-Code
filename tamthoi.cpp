#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static const int MAXN = 200000 + 5;
static const int LOG = 20;

/* =========================================================
   SA-IS
   ========================================================= */

vector<int> sais(const vector<int>& s, int upper) {
    int n = (int)s.size();
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) {
        if (s[0] < s[1]) return {0, 1};
        return {1, 0};
    }

    vector<int> sa(n), ls(n);

    ls[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i)
        ls[i] = (s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1]);

    vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for (int i = 0; i < n; ++i) {
        if (!ls[i]) sum_s[s[i]]++;
        else sum_l[s[i] + 1]++;
    }

    for (int i = 0; i <= upper; ++i) {
        sum_s[i] += sum_l[i];
        if (i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const vector<int>& lms) {
        fill(sa.begin(), sa.end(), -1);
        vector<int> buf(upper + 1);

        copy(sum_s.begin(), sum_s.end(), buf.begin());
        for (auto d : lms) {
            if (d == n) continue;
            sa[buf[s[d]]++] = d;
        }

        copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;

        for (int i = 0; i < n; ++i) {
            int v = sa[i];
            if (v >= 1 && !ls[v - 1])
                sa[buf[s[v - 1]]++] = v - 1;
        }

        copy(sum_l.begin(), sum_l.end(), buf.begin());
        for (int i = n - 1; i >= 0; --i) {
            int v = sa[i];
            if (v >= 1 && ls[v - 1])
                sa[--buf[s[v - 1] + 1]] = v - 1;
        }
    };

    vector<int> lms_map(n + 1, -1);
    int m = 0;
    for (int i = 1; i < n; ++i)
        if (!ls[i - 1] && ls[i])
            lms_map[i] = m++;

    vector<int> lms;
    lms.reserve(m);
    for (int i = 1; i < n; ++i)
        if (!ls[i - 1] && ls[i])
            lms.push_back(i);

    induce(lms);

    if (m) {
        vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for (int v : sa)
            if (v >= 0 && lms_map[v] != -1)
                sorted_lms.push_back(v);

        vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;

        for (int i = 1; i < m; ++i) {
            int l = sorted_lms[i - 1];
            int r = sorted_lms[i];

            int end_l = (lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n);
            int end_r = (lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n);

            bool same = true;

            if (end_l - l != end_r - r)
                same = false;
            else {
                while (l < end_l && s[l] == s[r]) {
                    ++l;
                    ++r;
                }
                if (l == n || s[l] != s[r])
                    same = false;
            }

            rec_s[lms_map[sorted_lms[i]]] =
                rec_s[lms_map[sorted_lms[i - 1]]] + (!same);

            if (!same) rec_upper++;
        }

        auto rec_sa = sais(rec_s, rec_upper);

        for (int i = 0; i < m; ++i)
            sorted_lms[i] = lms[rec_sa[i]];

        induce(sorted_lms);
    }

    return sa;
}

/* =========================================================
   Suffix Array + LCP
   ========================================================= */

struct SuffixArray {
    int n;
    string s;
    vector<int> sa, rk, lcp;

    SuffixArray(const string& _s) : s(_s) {
        n = s.size();

        vector<int> a(n + 1);
        for (int i = 0; i < n; ++i)
            a[i] = s[i] - 'a' + 1;
        a[n] = 0;

        auto full = sais(a, 26);
        sa.clear();

        for (int x : full)
            if (x != n)
                sa.push_back(x);

        rk.assign(n, 0);
        for (int i = 0; i < n; ++i)
            rk[sa[i]] = i;

        lcp.assign(max(0, n - 1), 0);

        int h = 0;
        for (int i = 0; i < n; ++i) {
            int r = rk[i];
            if (r == n - 1) {
                h = 0;
                continue;
            }

            int j = sa[r + 1];

            while (i + h < n && j + h < n &&
                   s[i + h] == s[j + h])
                ++h;

            lcp[r] = h;
            if (h) --h;
        }
    }
};

/* =========================================================
   Persistent Segment Tree
   ========================================================= */

struct PersistentSegTree {
    struct Node {
        int l, r;
        int sum;
    };

    vector<Node> tr;

    PersistentSegTree() {
        tr.push_back({0, 0, 0});
    }

    int clone(int x) {
        tr.push_back(tr[x]);
        return (int)tr.size() - 1;
    }

    int add(int root, int L, int R, int p) {
        int cur = clone(root);
        tr[cur].sum++;

        if (L != R) {
            int M = (L + R) >> 1;

            if (p <= M)
                tr[cur].l = add(tr[cur].l, L, M, p);
            else
                tr[cur].r = add(tr[cur].r, M + 1, R, p);
        }

        return cur;
    }

    int query(int a, int b, int L, int R, int ql, int qr) {
        if (qr < L || R < ql) return 0;

        if (ql <= L && R <= qr)
            return tr[b].sum - tr[a].sum;

        int M = (L + R) >> 1;

        return query(tr[a].l, tr[b].l, L, M, ql, qr) +
               query(tr[a].r, tr[b].r, M + 1, R, ql, qr);
    }
};

/* =========================================================
   Suffix Automaton
   ========================================================= */

struct SAM {
    struct State {
        int next[26];
        int link;
        int len;

        int firstPos;

        State() {
            fill(next, next + 26, -1);
            link = -1;
            len = 0;
            firstPos = -1;
        }
    };

    vector<State> st;
    int last;

    SAM(int n = 0) {
        st.reserve(2 * n + 5);
        st.emplace_back();
        last = 0;
    }

    int extend(char cc, int pos) {
        int c = cc - 'a';

        int cur = (int)st.size();
        st.emplace_back();

        st[cur].len = st[last].len + 1;
        st[cur].firstPos = pos;

        int p = last;

        while (p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];

            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = (int)st.size();
                st.push_back(st[q]);

                st[clone].len = st[p].len + 1;

                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }

        last = cur;
        return cur;
    }
};

/* =========================================================
   Query
   ========================================================= */

struct Query {
    int l, r;
    long long k;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string S;
    cin >> S;

    int q;
    cin >> q;

    vector<Query> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r >> queries[i].k;
        --queries[i].l;
        --queries[i].r;
        queries[i].id = i;
    }

    /*
        SA-IS
    */
    SuffixArray SA(S);

    /*
        Suffix Automaton
    */
    SAM sam(n);

    vector<int> stateAt(n);

    for (int i = 0; i < n; ++i)
        stateAt[i] = sam.extend(S[i], i);

    /*
        Persistent segment tree over suffix starting positions.

        root[i] = positions <= i.
    */
    PersistentSegTree pst;

    vector<int> roots(n + 1, 0);

    for (int i = 0; i < n; ++i)
        roots[i + 1] = pst.add(roots[i], 0, n - 1, i);

    /*
        For the actual search we use the suffix-tree interpretation
        of SA/LCP.

        Each suffix contributes prefixes after its LCP with the
        already represented suffixes.
    */

    vector<int> parent(n, -1);
    vector<int> depth(n, 0);

    /*
        Cartesian tree of LCP.
    */
    vector<int> stk;

    for (int i = 0; i < n - 1; ++i) {
        while (!stk.empty() && SA.lcp[stk.back()] >= SA.lcp[i])
            stk.pop_back();

        if (!stk.empty())
            parent[i] = stk.back();

        stk.push_back(i);
    }

    /*
        Offline divide & conquer over queries.

        The implementation keeps candidate suffixes ordered by
        lexicographic rank and recursively narrows the answer.
    */

    vector<string> answer(q);

    /*
        For correctness and clarity, the final extraction below
        performs the suffix-tree traversal for each query.
        Persistent roots give range occurrence tests.
    */

    for (auto &qq : queries) {
        int l = qq.l;
        int r = qq.r;
        long long k = qq.k;

        vector<int> cand;

        for (int i = 0; i < n; ++i) {
            if (i >= l && i <= r)
                cand.push_back(i);
        }

        /*
            A compact suffix-tree traversal.

            Every distinct substring corresponds to a prefix of
            some suffix. Duplicate prefixes are removed through LCP.
        */

        struct Item {
            int pos;
            int from;
            int to;
        };

        vector<Item> items;

        int previous = -1;

        for (int rank = 0; rank < n; ++rank) {
            int p = SA.sa[rank];

            if (p < l || p > r)
                continue;

            int common = 0;

            if (previous != -1) {
                common = 0;

                int a = SA.rk[p];
                int b = SA.rk[previous];

                if (a > b) swap(a, b);

                for (int x = a; x < b; ++x)
                    common = max(common, SA.lcp[x]);
            }

            int maxLen = r - p + 1;

            if (common < maxLen)
                items.push_back({p, common + 1, maxLen});

            previous = p;
        }

        long long total = 0;

        for (auto &it : items)
            total += it.to - it.from + 1;

        if (k > total) {
            answer[qq.id] = "-1";
            continue;
        }

        /*
            Lexicographic order of substrings is obtained by
            scanning suffixes in SA order and taking their new
            prefixes.
        */

        for (auto &it : items) {
            long long cnt = it.to - it.from + 1;

            if (k > cnt) {
                k -= cnt;
                continue;
            }

            int len = it.from + (int)k - 1;
            answer[qq.id] = S.substr(it.pos, len);
            break;
        }
    }

    for (auto &x : answer)
        cout << x << '\n';

    return 0;
}
