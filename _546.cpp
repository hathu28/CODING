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

string taskname = "_546";

class _546 {
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

    // Debug template (uncomment when debugging)
    // #define debug(x) cerr << #x << " = " << x << endl

    // Hàm sinh chỉnh hợp chập k của n phần tử
    // Tham số:
    // - n: số phần tử của tập hợp (1..n)
    // - k: số phần tử cần chọn
    // - cur: vector lưu chỉnh hợp hiện tại
    // - used: đánh dấu số đã sử dụng
    void gen(int n, int k, vector<int> &cur, vector<bool> &used) {
        if (cur.size() == k) {  // Nếu đã chọn đủ k phần tử
            for (int i = 0; i < k; ++i) {
                cout << cur[i] << " ";
            }
            cout << endl;
            return;
        }

        // Thử các số từ 1 đến n
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {           // Nếu số i chưa dùng
                used[i] = true;       // Đánh dấu đã dùng
                cur.pb(i);            // Thêm vào chỉnh hợp
                gen(n, k, cur, used); // Đệ quy tiếp
                cur.po();             // Quay lui: xóa số vừa thêm
                used[i] = false;      // Đánh dấu chưa dùng
            }
        }
    }

    void solve() {
        int n,k;
        cin>>n>>k;
        vector<int> cur;
        vector<bool> used(n+1);
        gen(n,k,cur,used);
    }

public:
    void run() {
        fastio();
        // openfile();
        solve();
    }
};

int32_t main() {
    _546 solver;
    solver.run();
    return 0;
}

/************************************************************************
 * Author: thunguyenha                                                  *
 * -. --. ..- -.-- . -. / --.- ..- .- -. --. / -- .. -. .... / ...- ..- *
 * Created: 2025-04-10 19:10:31                                         *
 ************************************************************************/