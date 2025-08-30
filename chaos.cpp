#include <bits/stdc++.h>
using namespace std;
using LL = long long ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    LL m;
    if (!(cin >> n >> m)) return 0;
    vector<LL> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    vector<LL> cur(n);
    LL pref = 0;
    for (int i = 0; i < n; ++i) {
        pref = (pref + A[i]) % m;
        if (i % 2 == 0) {
            cur[i] = pref;
        } else {
            LL t = 0;
            int sgn = 1;
            for (int j = i; j >= 0; --j) {
                t += sgn * A[j];
                sgn = -sgn;
            }
            t %= m;
            if (t < 0) t += m;
            cur[i] = t;
        }
    }
    for (int i = 0; i < (int)cur.size(); ++i) {
        if (i) cout << ' ';
        cout << cur[i];
    }
    cout << '\n';

    vector<LL> B;
    if (n >= 3) {
        B.reserve(1LL * n * (n - 1) * (n - 2) / 6);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k) {
                    LL s = (cur[i] + cur[j] + cur[k]) % m;
                    if ((s & 1LL) == 0) {
                        B.push_back(s);
                    } else {
                        LL sq = (s * s) % m;
                        B.push_back(sq);
                    }
                }
    }
    for (int i = 0; i < (int)B.size(); ++i) {
        if (i) cout << ' ';
        cout << B[i];
    }
    cout << '\n';

    sort(B.begin(), B.end());
    for (size_t start = 0; start < B.size(); start += 3) {
        size_t end = min(start + (size_t)3, B.size());
        size_t block = start / 3;
        if (block % 2 == 1) {
            reverse(B.begin() + start, B.begin() + end);
        }
    }
    for (int i = 0; i < (int)B.size(); ++i) {
        if (i) cout << ' ';
        cout << B[i];
    }
    cout << '\n';

    vector<LL> uniq;
    uniq.reserve(B.size());
    for (size_t i = 0; i < B.size(); ++i) {
        if (i == 0 || B[i] != B[i - 1]){
           uniq.push_back(B[i]);
        } 
    }
    vector<LL> add;
    add.reserve(uniq.size());
    for (auto v : uniq) if (v > 0) add.push_back(v - 1);
    vector<LL> coll = uniq;
    coll.insert(coll.end(), add.begin(), add.end());
    sort(coll.begin(), coll.end());
    coll.erase(unique(coll.begin(), coll.end()), coll.end());
    for (int i = 0; i < (int)coll.size(); ++i) {
        if (i) cout << ' ';
        cout << coll[i];
    }
    cout << '\n';

    vector<LL> C;
    C.reserve(coll.size());
    for (auto x : coll) {
        LL y;
        if (x % 3 == 0) {
            y = (x / 3) % m;
        } else if (x % 3 == 1) {
            y = (2 * x + 1) % m;
        } else {
            LL t = (x * x) % m;
            y = (t - 1) % m;
            if (y < 0) y += m;
        }
        C.push_back(y);
    }
    vector<LL> ev, od;
    ev.reserve(C.size()); od.reserve(C.size());

    for (auto v : C) ((v & 1LL) == 0 ? ev : od).push_back(v);

    vector<LL> out; out.reserve(C.size());

    out.insert(out.end(), ev.begin(), ev.end());
    out.insert(out.end(), od.begin(), od.end());
    for (int i = 0; i < (int)out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
    return 0;
}
