#pragma GCC optimize("O3", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define fi first
#define se second
#define po pop_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define lb lower_bound // tim so nho nhat lon hon bang x
#define ub upper_bound // tim so nho nhat lon hon x
#define pq priority_queue
#define pof pop_front

using ld = long double;
using pii = pair<int, int>;

// Constants
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MAX_N = 2e5 + 5;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string taskname = "_545";

int n, k;
int a[10];
int assign[10];
int grp[10];
int target;
bool found = false;

class _545 {
private:
    void fastio() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    static void openfile() {
        freopen((taskname + ".inp").c_str(), "r", stdin);
        freopen((taskname + ".out").c_str(), "w", stdout);
    }

    void backtrack(int index) {
        if (found) return;
        if (index == n) {
            for (int i = 0; i < k; ++i) {
                if (grp[i] != target) return;
            }
            for (int i = 0; i < n; ++i) {
                cout << assign[i] << " ";
            }
            found = true;
            return;
        }
        for (int i = 0; i < k; ++i) {
            if (grp[i] + a[index] <= target) {
                grp[i] += a[index];
                assign[index] = i + 1;
                backtrack(index + 1);
                grp[i] -= a[index];
                assign[index] = 0;
                if (grp[i] == 0) break;
            }
        }
    }

    void solve() {
        cin >> n >> k;
        for (int &i : a) cin >> i;
        int sum = accumulate(a, a + n, 0);
        if (sum % k) {
            cout << "ze";
        } else {
            target = sum / k;
            sort(a, a + n, greater<int>());
            for (int i = 0; i < n; ++i) {
                if (a[i] > target) {
                    cout << "ze";
                    return;
                }
            }
            backtrack(0);
            if (!found) cout << "ze";
        }
    }

public:
    void run() {
        fastio();
        solve();
    }
};

int32_t main() {
    _545 solver;
    solver.run();
    return 0;
}

/************************************************************************
 * Author: thunguyenha                                                  *
 * -. --. ..- -.-- . -. / --.- ..- .- -. --. / -- .. -. .... / ...- ..- *
 * Created: 2025-04-18 00:05:24                                         *
 ************************************************************************/
