#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = 1e9 + 7;

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        ll n, k;
        cin >> n >> k;
        k -= n;  // Convert to 0 to n-1 valued matrix
        if (k % n != 0) {
            cout << "Case #" << test << ": IMPOSSIBLE" << endl;
            continue;
        }
        cout << "Case #" << test << ": POSSIBLE" << endl;
        vll mapping(n);
        for (int i = 0; i < n; i++)
            mapping[(i + k / n) % n] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (j - mapping[i] + n) % n + 1 << " ";
            }
            cout << endl;
        }
    }
}