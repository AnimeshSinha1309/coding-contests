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
    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    ll b = 0;
    vll ans(n);

    ll counter = 0, mex = 0;
    vbl present(n + 1, false);
    vbl done(n + 1, false);
    for (auto el : a)
        present[el] = true;

    while (counter < n && present[counter])
        counter++;

    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] != a[i - 1])
            ans[i] = a[i - 1];
        else
            ans[i] = counter++;

        done[ans[i]] = true;
        while (done[mex])
            mex++;

        if (mex != a[i]) {
            cout << -1 << endl;
            exit(0);
        }
        counter = max(counter, ans[i]);
        while (counter < n && present[counter])
            counter++;
    }
    cout << ans;
}