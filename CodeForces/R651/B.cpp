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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(2 * n);
        cin >> a;
        stack<ll> even, odd;
        for (int i = 0; i < 2 * n; i++) {
            if (a[i] % 2 == 0)
                even.push(i + 1);
            else
                odd.push(i + 1);
        }
        for (int i = 0; i < n - 1; i++) {
            if (even.size() > odd.size()) {
                cout << even.top() << ' ';
                even.pop();
                cout << even.top() << ' ';
                even.pop();
            } else {
                cout << odd.top() << ' ';
                odd.pop();
                cout << odd.top() << ' ';
                odd.pop();
            }
            cout << endl;
        }
    }
}